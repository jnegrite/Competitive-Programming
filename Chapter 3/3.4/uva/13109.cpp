#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int nCases;
    cin >> nCases;
    long m, w;
    vector<long> elephants {};
    while(nCases--){
        cin >> m >> w;
        elephants.assign(m,0L);
        for(long i=0;i<m;i++){
            cin >> elephants[i];
        }
        sort(elephants.begin(),elephants.end());

        long currWeight{};
        long ans {};
        long temp;
        for(ans=0;ans<m && (currWeight+=elephants[ans]) <= w;ans++);
        cout << ans << '\n';
    }
}