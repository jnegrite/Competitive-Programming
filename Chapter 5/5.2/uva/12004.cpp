#include<iostream>

using namespace std;

int main(){
    int nCases;
    cin >> nCases;

    long long val;
    int denom;
    for(int tc=1;tc<=nCases;++tc){
        cin >> val;
        val *= (val-1);
        val /= 2;

        cout << "Case " << tc << ": ";
        if(val%2==0){
            cout << val/2;
        } else {
            cout << val << "/2";
        }
        cout << '\n';
    }
}