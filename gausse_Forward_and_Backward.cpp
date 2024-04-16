#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> forwardTable(vector<double> &x, vector<double> &y) {
    int n = x.size();
    vector<vector<double>> forwardDifferenceTable(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) {
        forwardDifferenceTable[i][0] = y[i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            forwardDifferenceTable[j][i] = forwardDifferenceTable[j + 1][i - 1] - forwardDifferenceTable[j][i - 1];
        }
    }
    return forwardDifferenceTable;
}

double gaussForwardInterpolation(vector<double> &x, vector<double> &y, double xi) {
    int n = x.size();
    double result = y[0];
    vector<vector<double>> forwardDifferenceTable = forwardTable(x, y);

    double p = (xi - x[0]) / (x[1] - x[0]);
    double term = 1.0;

    for (int i = 1; i < n; ++i) {
        term *= (p - i + 1) / i;
        result += term * forwardDifferenceTable[0][i];
    }
    return result;
}

vector<vector<double>> backwardTable(vector<double> &x, vector<double> &y) {
    int n = x.size();
    vector<vector<double>> backwardDifferenceTable(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        backwardDifferenceTable[i][0] = y[i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = n - 1; j >= i; --j) {
            backwardDifferenceTable[j][i] = backwardDifferenceTable[j][i - 1] - backwardDifferenceTable[j - 1][i - 1];
        }
    }
    return backwardDifferenceTable;
}

double gaussBackwardInterpolation(vector<double> &x, vector<double> &y, double xi) {
    int n = x.size();
    double result = y[n - 1];
    vector<vector<double>> backwardDifferenceTable = backwardTable(x, y);

    double p = (xi - x[n - 1]) / (x[1] - x[0]);
    double term = 1.0;

    for (int i = 1; i < n; ++i) {
        term *= (p + i - 1) / i;
        result += term * backwardDifferenceTable[n - 1][i];
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);

    cout << "Enter the data points:\n";
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i << "]: ";
        cin >> x[i];
        cout << "y[" << i << "]: ";
        cin >> y[i];
    }

    double xi;
    cout << "Enter the value to interpolate: ";
    cin >> xi;

    cout << "Cout Choice : \n 1. Gauss Forward \n 2. Gauss Backward \n";
    int ans;
    cin >> ans;
    if (ans == 1) {
        cout << "Gauss Forward Interpolation: " << gaussForwardInterpolation(x, y, xi) << endl;
    } else if (ans == 2) {
        cout << "Gauss Backward Interpolation: " << gaussBackwardInterpolation(x, y, xi) << endl;
    } else {
        cout << "Incorrect Choice";
    }
    return 0;
}
