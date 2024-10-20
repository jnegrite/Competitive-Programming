#include<iostream>
#include<cmath>

using namespace std;

long long H(long long n){

    if(n<1){
        return 0;
    }
    
    long long ans {0};
    long long prev {-1};

    long long sq = static_cast<long long>(sqrt(n));

    for(int i=1;i<=sq;++i){
        long long tmp {n/i};

        ans += tmp;

        if(prev != -1){
            ans += (i-1)*(prev-tmp);
        }
        prev = tmp;
    }

    ans += sq * (prev-sq);
    return ans;
}

int main(){
    int nCases;
    int n;

    cin >> nCases;
    while(nCases--){
        cin >> n;
        cout << H(n) << '\n';
    }
}
