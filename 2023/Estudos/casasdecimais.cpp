//#include <iostream>
//#include <iomanip> // biblioteca para manipular casas decimais
#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a = 0.123456;

    cout << fixed << setprecision(1) << a << endl; // 1 casa decimal
    cout << fixed << setprecision(2) << a << endl; // 2 casas decimal
    cout << fixed << setprecision(5) << a << endl; // 3 casas decimal
    cout << fixed << setprecision(6) << a << endl; // 6 casas decimal
}