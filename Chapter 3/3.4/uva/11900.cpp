#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int nCases;
    cin >> nCases;
    int n, p, q;
    int weights[30] {};
    for(int tc=1;tc<=nCases;tc++){
        cin >> n >> p >> q;
        for(int i=0;i<n;i++){
            cin >> weights[i];
        }
        sort(weights,weights+n);

        int cnt {};
        int currWeight {};
        
        for(cnt=0;cnt<n && cnt<p && currWeight+weights[cnt] <= q;currWeight+=weights[cnt++]);

        cout << "Case " << tc << ": " << cnt << '\n';
    }
}