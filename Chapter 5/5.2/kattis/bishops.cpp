#include<iostream>

using namespace std;

int main(){
    int val;
    while(cin >> val){
        cout << (val + max(0,val-2)) << '\n';
    }
}
