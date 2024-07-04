#include <bits/stdc++.h>

using namespace std;

int main(){

    int meno= 1000000;
    list <int> ocorr;
    vector <int> v;
    int a;
    auto ptr = v.begin();

    for (int i=0; i<10;i++){
		cin>>a;
		v.push_back(a);
        if(a<meno){
            ocorr.clear();
            ocorr.push_back(i);
            meno=a;
        }else if(a==meno){
            ocorr.push_back(i);
        }
	}	

    cout<<"Menor: "<<meno<<endl;
    cout<<"Ocorrencias: ";
    for(auto i : ocorr){ // lê o alcance da lista
		cout << i << " ";
    }
	cout << endl;


    ptr = v.begin();
    auto ptr2 = ocorr.begin();
    for (int i=0; i<10;i++){
        if (ptr2!=ocorr.end() && i==*ptr2){
            *ptr=-1;
            ptr2++;
        }
        ptr++;
    }

    ptr = v.begin();
    for (int i=0; i<10;i++){
		cout<< *ptr <<" ";
        ptr++;
	}	

    return 0;
}