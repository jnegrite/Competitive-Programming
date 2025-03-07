#include<iostream>
#include<vector>

using namespace std;

const long long MAXVAL {100000};

int main(){
    vector<long long> numDiv {};
    vector<long long> sumDiv {};

    numDiv.assign(MAXVAL+1,0LL);
    sumDiv.assign(MAXVAL+1,0LL);

    for(long long i=1;i<=MAXVAL;++i){
        for(long long j=i;j<=MAXVAL;j+=i){
            numDiv[j] += 1;
            sumDiv[j] += i;
        }
    }

    long long nCases, a, b, k;
    cin >> nCases;
    while(nCases-- > 0){
        long long g {};
        long long h {};
        cin >> a >> b >> k;
        if(a%k != 0){
            a+= (k- (a%k));
        }
        for(long long i=a; i<=b; i+=k){
            g += numDiv[i];
            h += sumDiv[i];
        }

        cout << g << ' ' << h << '\n';
    }

    numDiv.clear();
    sumDiv.clear();
}