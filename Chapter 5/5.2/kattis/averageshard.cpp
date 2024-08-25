#include<iostream>

using namespace std;

int nCS, nEcon;
long long valsCS[200000] {};
long long valsEcon[200000] {};

long long totalCS {};
long long totalEcon {};

int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        cin >> nCS >> nEcon;
        totalCS = totalEcon = 0LL;
        for(int i=0;i<nCS;++i){
            cin >> valsCS[i];
            totalCS += valsCS[i];
        }
        for(int i=0;i<nEcon;++i){
            cin >> valsEcon[i];
            totalEcon += valsEcon[i];
        }
        
        int ans {0};
        for(int i=0;i<nCS;++i){
            if(valsCS[i]*nCS < totalCS && valsCS[i]*nEcon > totalEcon){
                ++ans;
            }
        }
        cout << ans << '\n';
    }
}