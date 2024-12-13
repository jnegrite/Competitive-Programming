#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
const int MAXVAL = 32000;

bool isPrime[MAXVAL + 1] {};
vector<long> primes {};

int main(){
    //generate the sieve
    memset(isPrime,true,sizeof(isPrime));
    for(long long i=3;i<=MAXVAL;i+=2){
        if(!isPrime[i]){
            continue;
        } else {
            primes.push_back(i);
        }

        long long increment {i<<1};
        for(long long j=i*i;j<=MAXVAL;j+=increment){
            isPrime[j] = false;
        }
    }

    sort(primes.begin(), primes.end());

    long low, high;
    //process per pair
    while(cin >> low >> high, low != 0 || high != 0){
        if(low > high){
            swap(low,high);
        }
        auto first {lower_bound(primes.begin(), primes.end(), low)};

        /*
        if(*first == low && first != primes.begin()){
            --first;
        }
        */

        //try to find all series
        while(first != primes.end() && *first < high){
            auto second = first;
            ++second;

            if(second == primes.end()){
                break;
            }

            int nTerms {2};
            int diff {*second - *first};
            
            auto right {second};
            auto left {right++};

            
            bool partialMatch {false};
            while(right != primes.end() && ((*right - *left) == diff)){
                
                if (*right > high){
                    partialMatch = true;
                    break;
                }

                ++nTerms;
                ++right;
                ++left;
            }
            
            if(partialMatch){
                break;
            }

            if(nTerms >= 3){
                //check if subset
                bool isSubset {false};
                auto prev {first};
                
                if(prev != primes.begin()){
                    --prev;
                    if((*prev < low) && (*prev + diff == *first)){
                        isSubset = true;
                    }
                }

                if(!isSubset){
                    auto ptr {first};
                    cout << *(ptr++);
                    
                    while(ptr != right){
                        cout << ' ' << *(ptr++);
                    }
                    cout << '\n';
                }
            }

            first = left;
        }
    }
}