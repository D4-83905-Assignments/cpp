#include<iostream>
using namespace std;
class Time
{
    private:
    int hour,min,sec;

    public:
    Time()
    {
        hour=1;
        min=1;
        sec=1;
    }
    Time(int h,int m,int s)
    {
        hour=h;
        min=m;
        sec=s;
    }
    void acceptTime()
    {
        cout<<"Enter Hour :";
        cin>>hour;
        cout<<"Enter Minute :";
        cin>>min;
        cout<<"Enter Second :";
        cin>>sec;
    }
    void displayTime()
    {
        cout<<"Hour"<<hour<<endl;
        cout<<"Minute"<<min<<endl;
        cout<<"Seconds"<<sec<<endl;
    }
    int get_Hour()
    {    
        return hour;
    }
    int get_Minute()
    {
        
        return min;
    }
    int get_Seconds()
    { 
        
        return sec;
    }
   void  PrintTime()
    {
        cout<<"Time :"<<this->hour<< ":"<<this->min <<":" <<this->sec <<" :"<<endl;
    }
    void set_Hour(int h)
    {
       this->hour=h;
    }
    void set_min(int m)
    {
        min=m;
    }
    void set_sec(int s)
    {
        sec=s;
    }
};//end of class
int main()
{
    Time t;
    t.acceptTime();
    t.displayTime();
    int choice;
    
    do
    {
        cout<<"Enter your choice"<<endl;
        cout<<"1.Set time"<<endl;
        cout<<"2.get time"<<endl;
        cout<<"3.Exit"<<endl;
        cin>>choice;
        

        switch(choice)
        {
        case 1:
            //t.set_Hour(4);
            //t.set_min(03);
            //t.set_sec(01);
            cout<<"hiiii........"<<endl;


        break;
        case 2:
            t.acceptTime();
            t.displayTime();
             //t.get_Hour();
             //t.get_Minute();
            // t.get_Seconds();

        break;
        case 3:
        cout<<"thank you";
        break;
        default:
        cout<<"invalid choice"<<endl;
        
        }
    }while(choice!=3);
    
}

 
