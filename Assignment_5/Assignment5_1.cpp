#include<iostream>
using namespace std;
class Date
{
private:
    int day;
    int month;
    int year;
public:
Date()
{
    day=1;
    month=1;
    year=1;
}
Date(int d,int m,int y)
{
    day=d;
    month=m;
    year=y;
}
void acceptDate()
{
    cout<<"Enter day-"<<endl;
    cin>>day;
    cout<<"Enter month-"<<endl;
    cin>>month;
    cout<<"Enter year -"<<endl;
    cin>>year;
}
void displayDate()
{
    cout<<"DATE : "<<"Day"<<"Month"<<"Year"<<endl;
}
};
class Person
{
private:
    string name;
    string address;
    Date Dob;
public:
    Person()
    {
        name="neha";
        address="Icchi";
    }
    Person(string name,string address)
    {
       this-> name = name;
       this-> address = address;
    }
    void acceptPerson()
    {   cout<<endl<<"---------Enter personal info---------"<<endl;
        cout<<"Enter name"<<endl;
        cin>>name;
        cout<<"Enter address"<<endl;
        cin>>address;
        cout<<"Enter your birthdate: "<<endl;
        Dob.acceptDate();
        cout<<"-----------------------------------------------"<<endl;
    }
    void displayPerson()
    {
        cout<<"\nname: "<<name<<endl;
        cout<<"address: "<<address<<endl;
        cout<<"Date of Birth is : \n";
        Dob.displayDate();
    }
};
class Employee:public Person
{
private:
int empid;
float salary;
string dept;
Date joining;
public:
    Employee()
    {
        empid=1;
        salary=10000;
        dept="";
    }
    Employee(int empid,float salary,string dept)
    {
        this->empid=empid;
        this->salary=salary;
        this->dept=dept;
    }
    void acceptEmployee()
    {
        cout << "Enter employee id - ";
        cin >> empid;
        cout << "Enter Salary - ";
        cin >> salary;
        cout << "Enter department- ";
        cin >> dept;
        this->acceptPerson();
        cout << "Enter Date of joining - " << endl;
        joining.acceptDate();
    }
    
    void displayEmployee()
    {
        cout << "\nEmpid - " << empid << endl;
        cout << "salary - " << salary << endl;
        cout << "Department - " << dept << endl;
        this->displayPerson();
        cout << "Joining Date: "<<endl;
        joining.displayDate();
    }
};
int main()
{
    Employee e;
    e.acceptEmployee();
    e.displayEmployee();
    return 0;
}
