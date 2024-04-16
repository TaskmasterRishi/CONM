#include <bits/stdc++.h>
using namespace std;

double fun(double x, double y)
{
    return (y - x) / (y + x);
}

void euler(double x0, double y0, double h, double x)
{
    while (x0 < x)
    {
        double y = y0 + h * fun(x0, y0);
        cout << "x = " << x0 << " y = " << y << endl;
        y0 = y;
        x0 = x0 + h;
    }
}

int main()
{
    double x, y, X, h;
    cout << "Enter initaial and y :";
    cin >> y;
    cout << "Enter starting and ending value of x :";
    cin >> x >> X;
label:
    if (X < x)
    {
        cout << "Please enter correct range from low to high : ";
        goto label;
    }
    cout << "Enter h :" << endl;
    cin >> h;
    euler(x, y, h, X);
    return 0;
}