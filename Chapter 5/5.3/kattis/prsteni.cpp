#include<iostream>

using namespace std;

int gcd(int a, int b){
    return (b==0 ? a : gcd(b, a%b));
}

int main(){
    int nValues, val, g;
    int first;

    cin >> nValues;
    cin >> first;
    for(int i=1;i<nValues;++i){
        cin >> val;
        g = gcd(first, val);
        cout << (first/g) << '/' << (val/g) << '\n';
    }

}