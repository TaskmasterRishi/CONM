#include <bits/stdc++.h>
using namespace std;

vector<double> dividedDifference(vector<double> &x, vector<double> &y)
{
    int n = x.size();
    vector<double> dividedDiff(n);
    dividedDiff[0] = y[0];

    for (int j = 1; j < n; ++j)
    {
        for (int i = n - 1; i >= j; --i)
        {
            y[i] = (y[i] - y[i - 1]) / (x[i] - x[i - j]);
        }
        dividedDiff[j] = y[j];
    }
    return dividedDiff;
}
double newtonDivideDiffrence(vector<double> &x, vector<double> &y, double xi)
{
    int n = x.size();
    vector<double> dividedDiff = dividedDifference(x, y);
    double result = dividedDiff[0];

    for (int i = 1; i < n; ++i)
    {
        double term = dividedDiff[i];
        for (int j = 0; j < i; ++j)
        {
            term *= (xi - x[j]);
        }
        result += term;
    }
    return result;
}
int main()
{
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);

    cout << "Enter the data points:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }

    double xi;
    cout << "Enter the value to interpolate: ";
    cin >> xi;
    cout << "Newton Divide Diffrence Interpolation: " << newtonDivideDiffrence(x, y, xi) << endl;
    return 0;
}
