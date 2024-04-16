#include<iostream>
#include<math.h>
using namespace std;
void relative(float x, float y)
{
    float rlv;
    rlv=abs((x-y)/x);
    cout<<"\nRelative Error: "<<rlv<<endl;
}
void truncation(float x, float y)
{
    cout<<"\nTruncation Error: "<<abs(x-y)<<endl;
}
void round_off(float x)
{   int n;

    cout<<"Enter number to round off digits: ";  cin>>n;
    long double value=(int)(x*pow(10,n)+0.5);
    long double b=(double)(value/pow(10,n));
    cout<<"round off: "<<b<<endl;
    cout<<"\nRounf off Error: "<<abs(b-x)<<endl;
}
int main()
{
    float x,y;

    cout<<"Enter true value: ";         cin>>x;
    cout<<"Enter approximate value: ";  cin>>y;

    relative(x,y);
    truncation(x,y);
    round_off(x);

    return 0;
}