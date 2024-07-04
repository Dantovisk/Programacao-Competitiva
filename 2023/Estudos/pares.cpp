#include <iostream>

using namespace std;

int main()
{
    pair<int,int> a = make_pair(1, 2); // a = {1, 2}
    pair<string,double> b = make_pair("Dantovisk", 20.03); // b = {"Dantovisk", 20.03}

    int c = a.first; // c = 1
    double d = b.second; // 20.03

    b.first = "Novo Dantovisk";
    string e = b.first; // e = "Novo Dantovisk"

    cout<<" "<<a.first<<" "<<d<<" "<<c<<" "<<e;
}