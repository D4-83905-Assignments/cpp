
include <iostream>
using namespace std;

// Enum to represent the type of account
enum class AccountType {
    SAVINGS,
    CHECKING,
    CREDIT
};

// Exception class for insufficient funds
class InsufficientFundsException {
public:
    const char* what() const noexcept {
        return "Insufficient funds in the account.";
    }
};

// Account class
class Account {
private:
    string accountNumber;
    string accountHolderName;
    AccountType type;
    double balance;

public:
    // Constructor
    Account() : balance(0.0) {}

    // Getters and setters
    void setAccountNumber(const std::string& accNum) {
        accountNumber = accNum;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    void setAccountHolderName(const std::string& name) {
        accountHolderName = name;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    void setAccountType(AccountType accType) {
        type = accType;
    }

    AccountType getAccountType() const {
        return type;
    }

    void setBalance(double bal) {
        if (bal < 0) {
            throw "Balance cannot be negative.";
        }
        balance = bal;
    }

    double getBalance() const {
        return balance;
    }

    // Deposit function
    void deposit(double amount) {
        if (amount <= 0) {
            throw "Deposit amount must be positive.";
        }
        balance += amount;
        cout << "Deposit successful. Updated balance: " << balance << endl;
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount <= 0) {
            throw "Withdrawal amount must be positive.";
        }
        if (balance < amount) {
            throw InsufficientFundsException();
        }
        balance -= amount;
        cout << "Withdrawal successful. Updated balance: " << balance << endl;
    }
};

int main() {
    Account accounts[5];

    // Accepting details for each account
    for (int i = 0; i < 5; ++i) {
        string accNum, accHolderName;
        int accType;
        double balance;

        cout << "Enter account number for account " << i+1 << ": ";
        cin >> accNum;
        accounts[i].setAccountNumber(accNum);

        cout << "Enter account holder name for account " << i+1 << ": ";
        cin >> accHolderName;
        accounts[i].setAccountHolderName(accHolderName);

        cout << "Enter account type (0 for Savings, 1 for Checking, 2 for Credit) for account " << i+1 << ": ";
        cin >> accType;
        accounts[i].setAccountType(static_cast<AccountType>(accType));

        cout << "Enter initial balance for account " << i+1 << ": ";
        cin >> balance;
        accounts[i].setBalance(balance);
    }

    // Menu-driven program
    int choice, accIndex;
    double amount;
    do {
        cout << "\nMenu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account index: ";
                cin >> accIndex;
                cout << "Enter deposit amount: ";
                cin >> amount;
                try {
                    accounts[accIndex].deposit(amount);
                }
                catch (const char* msg) {
                    cerr << "Error: " << msg << endl;
                }
                break;

            case 2:
                cout << "Enter account index: ";
                cin >> accIndex;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                try {
                    accounts[accIndex].withdraw(amount);
                }
                catch (const InsufficientFundsException& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                catch (const char* msg) {
                    cerr << "Error: " << msg << endl;
                }
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;

