#include <bits/stdc++.h>
using namespace std;

double trapezoid(vector<double> &x, vector<double> &y)
{
    int n = x.size();
    double h = (x[1] - x[0]);
    double result = y[0] + y[n - 1];
    for (int i = 1; i < n - 1; i++)
    {
        result += 2 * y[i];
    }
    result =  h * result / 2;
    return result;
}

int main()
{
    int n;
    cout << "Enter the number of data points : " << endl;
    cin >> n;
    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cout << "X[" << i << "] : ";
        cin >> x[i];
        cout << "Y[" << i << "] : ";
        cin >> y[i];
    }
    cout << "Trapezoid rule : " << trapezoid(x, y) << endl;
    return 0;
}