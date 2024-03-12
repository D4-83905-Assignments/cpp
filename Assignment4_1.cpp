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
        day=31;
        month=07;
        year=2000;
    }
    Date(int d,int m,int y)
    {
        day=d;
        month=m;
        year=y;

    }
    void acceptDate()
    {
        cout<<"Enter Day"<<endl;
        cin>>day;
        cout<<"Enter Month"<<endl;
        cin>>month;
        cout<<"Enter Year"<<endl;
        cin>>year;
    }
    void displayDate()
    {
        cout<<"DATE:  "<<day<<"/"<<month<<"/"<<year<<endl;
    }

    //getter-inspector
    int get_day()
    {
        return day;
    }
    int get_month()
    {
        return month;
    }
    int get_year()
    {
        return year;
    }

    //settor -muttator
    void set_day(int day)
    {
        this->day=day;
    }
    void set_month(int month)
    {
        this->month=month;
    }
    void set_year(int year)
    {
        this->year=year;
    }
  //  bool isLeapYear()
    //{
     //   if ((year % 4 == 0 || year % 400 == 0)==1);  
     //   {
      //      cout<<"Leap year";
     //   }
      //  else ()
       // {
        //    cout<<"Not a leap year";
        
       // }
        
   // }
};
class Person
{
    private:
    string name;
    string address;
    Date DOB;
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
        DOB.acceptDate();
        cout<<"-----------------------------------------------"<<endl;
    }
    void displayPerson()
    {
        cout<<"\nname: "<<name<<endl;
        cout<<"address: "<<address<<endl;
        cout<<"Date of Birth is : \n";
        DOB.displayDate();
    }
    string get_name()
    {
        return name;
    }
    string get_address()
    {
        return address;
    }
    Date get_DOB()
    {
        return DOB;
    }
    void set_name(string name)
    {
        this->name=name;
    }
    void set_address(string address)
    {
        this->address=address;
    }
    void set_DOB(Date DOB )
    {
        this->DOB=DOB;
    }
};
class Employee:public Person
{ 
private:
    int emp_id;
    float salary;
    string dept;
    Date joining;

public:
    Employee()
    {
        
        emp_id = 101;
        salary = 10000;
        dept="DAC";
    }

     Employee(int empid, string dept, float salary)
    {
        
        this->emp_id = emp_id;
        this->salary = salary;
        this->dept=dept;
    }
   

    void acceptEmployee()
    {
        cout << "Enter employee id - ";
        cin >> emp_id;
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
        cout << "\nEmpid - " << emp_id << endl;
        cout << "salary - " << salary << endl;
        cout << "Department - " << dept << endl;
        this->displayPerson();
        cout << "Joining Date: "<<endl;
        joining.displayDate();
        
    }

    int get_emp_id()
    {
       return emp_id;
    }
    float get_salary()
    {
        return salary;
    }
    string get_dept()
    {
        return dept;
    }
    Date get_date()
    {
        return joining;
    }
    void set_emp_id(int emp_id)
    {
        this->emp_id=emp_id;
    }
    void set_address(float salary)
    {
        this->salary=salary;
    }
    void set_joining(Date joining )
    {
        this->joining=joining;
    }

};

int main()
{
 //   Date d;
  //  d.displayDate();
   // d.displayDate();

  //  Person p;
   // p.acceptPerson();
   // p.displayPerson();

    Employee e;
    e.acceptEmployee();
    e.displayEmployee();
    return 0;
}

