#include<iostream>
#include<algorithm>

using namespace std;


int main(){
    int nCases;
    cin >> nCases;

    int prices[20000] {};

    while(nCases--){
        int nValues;
        cin >> nValues;

        for(int i=0;i<nValues;i++){
            cin >> prices[i];
        }
        sort(prices,prices+nValues,greater<int>());

        long ans {};
        for(int pos=2;pos<nValues;pos+=3){
            ans+=prices[pos];
        }
        cout << ans << '\n';
    }
}