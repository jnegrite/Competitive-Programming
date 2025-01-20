#include<iostream>
#include<vector>

using namespace std;

vector<long long> factors {};

void factorize(long long n, long long nFrom){
    for(long long i=nFrom;i*i<=n;++i){
        if(n%i == 0){
            factors.push_back(i);
            factorize(n/i, i); 
            return;           
        }
    }

    factors.push_back(n);
}

int main(){
    int n;
    while(cin >> n, n != 4){
        int nSteps = 0;

        while(true){
            ++nSteps;
            factors.clear();
            factorize(n,2);
            
            if(factors.size() == 1){
                break;
            }

            n = 0;
            for(long long val:factors){
                n += val;
            }
        }
        cout << factors[0] << ' ' << nSteps << '\n';
    }
}