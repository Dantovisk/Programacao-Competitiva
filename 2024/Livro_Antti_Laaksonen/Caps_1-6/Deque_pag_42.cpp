//Pilha + fila = deque

/*
A deque is a dynamic array whose size can be efficiently changed at 
both ends of the array.
Like a vector, a deque provides the functions push_back and pop_back,
but it also includes the functions push_front and pop_front 
which are not available in a vector.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> d;
    d.push_back(5); // [5]
    d.push_back(2); // [5,2]
    d.push_front(3); // [3,5,2]
    d.pop_back(); // [3,5]
    d.pop_front(); // [5]
}