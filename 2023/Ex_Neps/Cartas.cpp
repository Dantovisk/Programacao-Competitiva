#include <bits/stdc++.h>

using namespace std;

set <int> st;
int a;

int main(){

    for (int i =0; i<3; i++){

        cin>>a;
        if(st.find(a)!=st.end()){
            st.erase(a);
        }else{
            st.insert(a);
        }
    }
    auto ptr = st.begin();
	cout << *ptr << endl;

}