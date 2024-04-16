#include <bits/stdc++.h>
using namespace std;

double fun(double x, double y)
{
    return x + y;
}

void rungeKutta(double x0, double y0, double h, double x)
{
    while (x0 < x)
    {
        double k1 = h * fun(x0, y0);
        double k2 = h * fun(x0 + h / 2, y0 + k1 / 2);
        double k3 = h * fun(x0 + h / 2, y0 + k2 / 2);
        double k4 = h * fun(x0 + h, y0 + k3);
        y0 = y0 + ((k1 + 2 * k2 + 2 * k3 + k4) / 6);
        x0 = x0 + h;
        cout << "x = " << x0 << " y = " << y0 << endl;
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
    rungeKutta(x, y, h, X);
    return 0;
}