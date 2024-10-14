#include<iostream>
#include<cstring>

using namespace std;

int main(){
    int n, k;
    long long memo[10001] {};

    while(cin >> n >> k, n!=-1 || k !=-1){
        memset(memo,0LL,sizeof(memo));
        for(int i=n;i>=0;--i){
            cin >> memo[i];
        }

        for(int i=0,j=k;j<=n;++i,++j){
            memo[j] -= memo[i];
        }
        int lastTerm {max(0,n-k+1)};

        while(lastTerm<n && (memo[lastTerm] == 0LL)){
            ++lastTerm;
        }

        cout << memo[n];
        for(int i=n-1;i>=lastTerm;--i){
            cout << ' ' << memo[i];
        }
        cout << '\n';
    }
}