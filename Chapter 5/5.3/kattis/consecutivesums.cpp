#include<iostream>
#include<bitset>
#include<cmath>
#include<vector>
#include<map>
#include<queue>

using namespace std;

const long long MAX_VAL {50000};

vector<long> primes {};

void initPrimes(){
    primes.clear();

    bitset<MAX_VAL+1> isPrime {};
    isPrime.set();

    for(long long i=2;i<=MAX_VAL;++i){
        if(isPrime.test(i)){
            primes.push_back(i);

            for(long long j=i*i;j<=MAX_VAL;j+=i){
                isPrime.reset(j);
            }
        }
    }
}

long long remove2(long long val){
    auto pos {__builtin_ctz(val)};
    return val >> pos;
}

long long get_lowest_factor(long long val){
    val = remove2(val);
    for(int i=1;i<primes.size();++i){
        if(val%primes[i] == 0){
            return primes[i];
        }
    }
    return val;
}

vector<pair<long long,int>> primeFactorize(long long val) {
    vector<pair<long long,int>> result {};

    for(long pos=0;primes[pos] * primes[pos] <= val; ++pos){
        int nFactors {};
        long long currVal {primes[pos]};
        while(val % currVal == 0){
            ++nFactors;
            val /= currVal;
        }

        if(nFactors != 0){
            result.push_back({currVal, nFactors});
        }
    }

    if(val != 1){
        result.push_back({val,1});
    }
    return result;
}

void backtrack(int pos, int currCnt, int currVal, vector<pair<long long,int>> &factors,
        priority_queue<long long,vector<long long>, greater<long long>> &results){
    if(pos == factors.size()){
        if(currVal != 1){
            results.emplace(currVal);
        }
        return;
    }

    //move to next
    backtrack(pos+1,0,currVal,factors,results);

    if(currCnt < factors[pos].second){
        backtrack(pos,currCnt+1,currVal*factors[pos].first, factors, results);
    }
}

long long getOdd(long long val){
    long long ans {-1};
    long long oddVal {remove2(val)};
    auto pf {primeFactorize(oddVal)};
    priority_queue<long long,vector<long long>, greater<long long>> results {};

    backtrack(0,0,1,pf,results);


    while(!results.empty()){
        long long candidate {results.top()};
        results.pop();

        long long mid {val/candidate};
        long long span {candidate/2};
        long long lower = mid-span;

        if(lower > 0){
            return candidate;
        }
    }
    return -1;
}



int main(){
    initPrimes();

    int nCases;
    cin >> nCases;
    long long val;
    while(nCases--){
        cin >> val;

        if(remove2(val) == 1){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        
        int candidateLength {-1};
        int valFrom, valTo, lower;

        //check odd
        long long lowest_odd {getOdd(val)};
        if(lowest_odd != val && lowest_odd != -1){
            long long mid {val/lowest_odd};
            long long span {lowest_odd/2};

            candidateLength = lowest_odd;
            valFrom = mid-span;
            valTo = mid+span;
        }

        //check even
        long long lowest_even {2 << __builtin_ctz(val)};
        if(candidateLength == -1 || lowest_even < candidateLength){

            long long span {(lowest_even/2)-1};
            long long oddSum {remove2(val)};
            lower = (oddSum>>1) - span;
            if(span == 0){
                candidateLength = 2;
                valFrom = oddSum/2;
                valTo = valFrom+1;
            } else if(lower > 0){
                candidateLength = lowest_even;
                valFrom = lower;
                valTo = lower + candidateLength - 1;
            }
        }
        
        if(candidateLength == -1){
            cout << "IMPOSSIBLE\n";
            continue;
        }

        cout << val << " = " << valFrom;
        for(long long v=valFrom+1;v<=valTo;++v){
            cout << " + " << v;
        }
        cout << '\n';        
    }
}