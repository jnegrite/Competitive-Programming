#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    long x[800] {};
    long y[800] {};

    int nCases;
    cin >> nCases;
    for(int tc=1;tc<=nCases;tc++){
        int n;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> x[i];
        }
        for(int i=0;i<n;i++){
            cin >> y[i];
        }

        sort(x,x+n);
        sort(y,y+n,greater<long>());
        
        long ans {};
        for(int i=0;i<n;i++){
            ans += (x[i] * y[i]);
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}