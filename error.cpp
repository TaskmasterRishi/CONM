#include <bits/stdc++.h>
using namespace std;
void relative(float tr, float ap)
{
    float re;
    re = abs((tr - ap) / tr);
    cout << "\nRelative Error: " << re << endl;
}
void truncation(float tr, float ap)
{
    cout << "\nTruncation Error: " << abs(tr - ap) << endl;
}
void round_off(float tr)
{
    int n;

    cout << "Enter number to round off digits: ";
    cin >> n;
    long double value = (int)(tr * pow(10, n) + 0.5);
    long double b = (double)(value / pow(10, n));
    cout << "round off: " << b << endl;
    cout << "\nRounf off Error: " << abs(b - tr) << endl;
}
int main()
{
    float tr, ap;

    cout << "Enter true value: ";
    cin >> tr;
    cout << "Enter approximate value: ";
    cin >> ap;

    relative(tr, ap);
    truncation(tr, ap);
    round_off(tr);

    return 0;
}