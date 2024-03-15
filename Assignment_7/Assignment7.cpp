#include <iostream>
using namespace std;

class employee
{
private:
    int id;
    float salary;

public:
    employee()
    {
        int id = 10;
        float salary = 10000;
    }
    employee(int id, float salary)
    {
        this->id = id;
        this->salary = salary;
    }

    void set_id(int employee_id)
    {
        this->id = employee_id;
    }
    int get_id()
    {
        return this->id;
    }

    void set_salary(float employee_salary)
    {
        salary = employee_salary;
    }
    int get_salary()
    {
        return this->salary;
    }

    virtual void acceptData()
    {
        cout << "Enter ID -" << endl;
        cin >> id;
        cout << "Enter Salary -" << endl;
        cin >> salary;
    }
    virtual void displayData()
    {
        cout << "Id -" << id << endl;
        cout << "Salary -" << salary << endl;
    }
    virtual ~employee()
    {
    }
};

class manager : virtual public employee

{
private:
    float bonus;

protected:
    void accpetManagerData()

    {
        cout << "Enter bonus -" << endl;
        cin >> bonus;
    }

    void displayManagerData()
    {
        cout << "Bonus -" << bonus << endl;
    }

public:
    manager()
    {
        bonus = 1000;
    }

    manager(int id, float salary, float bonus) : employee(id, salary)
    {
        this->bonus = bonus;
    }

    void set_bonus(float manager_bonus)
    {
        bonus = manager_bonus;
    }
    int get_bonus()
    {
        return this->bonus;
    }

    void acceptData()
    {
        employee::acceptData();
        this->accpetManagerData();
    }

    void displayData()
    {
        employee::displayData();
        this->displayManagerData();
    }

    ~manager()
    {
    }
};

class salesman : virtual public employee
{
private:
    float commision;

protected:
    void acceptSalesmanData()
    {
        cout << "Enter Commision -" << endl;
        cin >> commision;
    }
    void displaySalesmanData()
    {
        cout << "Commision-" << commision << endl;
    }

public:
    salesman()
    {
        float commision = 1000;
    }

    salesman(int id, float salary, float commision) : employee(id, salary)

    {
        this->commision = commision;
    }

    void set_commision(float employee_commision)
    {
        commision = employee_commision;
    }
    int get_commision()
    {
        return this->commision;
    }

    void acceptData()
    {
        employee::acceptData();
        this->acceptSalesmanData();
    }

    void displayData()
    {
        employee::displayData();
        this->displaySalesmanData();
    }
    ~salesman()
    {
    }
};

class sales_manager : public manager, public salesman

{
public:
    sales_manager()
    {
    }
    sales_manager(int id, float salary, float bonus, float commision)
    {
        this->set_id(id);
        this->set_salary(salary);
        this->set_bonus(bonus);
        this->set_commision(commision);
    }
    void acceptData()
    {
        employee::acceptData();
        this->accpetManagerData();
        this->acceptSalesmanData();
    }

    void displayData()
    {
        employee::displayData();
        this->displaySalesmanData();
        this->displayManagerData();
    }
    ~sales_manager()
    {
    }
};

int menu()
{
    int choice;
    cout << "0. EXIT" << endl;
    cout << "1. Add Manager" << endl;
    cout << "2. Add Salesman" << endl;
    cout << "3. Add sales_Manager" << endl;
    cout << "4. Display Managers" << endl;
    cout << "5. Display Salesmans" << endl;
    cout << "6. Display Salaes_Managers" << endl;
    cout << "7. Display All Employees" << endl;
    cout << "8. Display the count of all employees with respect to designation" << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    return choice;
}
int main()
{
    int choice, size = 10, count = 0;
    employee *Employee[size];

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            if (count < size)
            {
                Employee[count] = new manager();
                Employee[count]->acceptData();
                count++;
            }
            else
                cout << "List is full" << endl;
            break;
        case 2:
            if (count < size)
            {
                Employee[count] = new salesman();
                Employee[count]->acceptData();
                count++;
            }
            else
                cout << "List is full" << endl;
            break;
        case 3:
            if (count < size)
            {
                Employee[count] = new sales_manager();
                Employee[count]->acceptData();
                count++;
            }
            else
                cout << "List is full" << endl;
            break;

        case 4:
            for (int i = 0; i < count; i++)
                if (typeid(*Employee[i]) == typeid(manager))
                    Employee[i]->displayData();
            break;

        case 5:
            for (int i = 0; i < count; i++)
                if (typeid(*Employee[i]) == typeid(salesman))
                    Employee[i]->displayData();
            break;

        case 6:
            for (int i = 0; i < count; i++)
                if (typeid(*Employee[i]) == typeid(sales_manager))
                    Employee[i]->displayData();

            break;

        case 7:
            for (int i = 0; i < count; i++)
                Employee[i]->displayData();
            break;

        case 8:
        {
            int man = 0, sman = 0, smanager = 0;
            for (int i = 0; i < count; i++)
            {
                if (typeid(*Employee[i]) == typeid(manager))
                {
                    man++;
                }
                else if (typeid(*Employee[i]) == typeid(salesman))
                {
                    sman++;
                }
                else
                {
                    smanager++;
                }
            }
            cout << " Manager count : " << man << endl;
            cout << " Salesman count : " << sman << endl;
            cout << " Sales MAnager count : " << smanager << endl;
            break;
        }

        
        default:
            cout << "Wrong choice ..." << endl;
            break;
        }
    }
    for (int i = 0; i < count; i++)
        delete Employee[i];

   
    return 0;
}

