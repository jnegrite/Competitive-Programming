#include<iostream>
#include<algorithm>

using namespace std;


int main(){
    long prices[200000] {};
    long nValues;
    cin >> nValues;

    for(long i=0;i<nValues;i++){
        cin >> prices[i];
    }
    sort(prices,prices+nValues,greater<long>());

    long ans {};
    for(long pos=2;pos<nValues;pos+=3){
        ans+=prices[pos];
    }
    cout << ans << '\n';
}