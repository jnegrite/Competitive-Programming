#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int MAX_VAL = 10000;

vector<int> primes {};
bool is_prime[MAX_VAL+1] {};

int main(){
    memset(is_prime,true,sizeof(is_prime));
    for(int i=2;i<=MAX_VAL;i++){
        if(is_prime[i]){
            primes.push_back(i);

            for(int j=i*i;j<=MAX_VAL;j+=i){
                is_prime[j] = false;
            }
        }
    }

    int val;
    while(cin >> val, val != 0){
        int ans = 0;

        auto left {primes.begin()};
        auto right {left};

        int currSum {primes[0]};
        while(right != primes.end() && *right <= val){
            if(currSum == val){
                ans++;

                currSum -= *(left++);
                ++right;
                if(right == primes.end()){
                    break;
                }
                currSum += *right;

            } else if (currSum < val){
                ++right;
                if(right == primes.end()){
                    break;
                }
                currSum += *right;
            } else {
                currSum -= *(left++);
            }
        }
        
        cout << ans << '\n';
    }
}