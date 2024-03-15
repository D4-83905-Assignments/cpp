#include<iostream>
using namespace std;
int factorial( int n)
{
    if(n<=0)
    throw 1;
    int result = 1, i;
    for (i = 1; i <= n; i++)
        result = result*i;
    return result;

}
int main()
{
    int num;
    try
    {
        factorial(num);
        cout << "Inside try  ()  - " << endl;
    }
    catch (int error)
    {
        cout << "Number cannot be Less than  0" << endl;
    }
    //int num;
    cout<<"Enter any Number -";
    cin>>num;
    cout << "Factorial of is -"<<num<<endl
        << factorial(num) << endl;
    return 0;
}


