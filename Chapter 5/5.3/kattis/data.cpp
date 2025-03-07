#include<iostream>
#include<vector>

#define LSOne(x) ((x) & (-x))

using namespace std;

const long long MAXVAL = 14000;

long long ndFactors[MAXVAL + 1] {};
long long values[14] {};
long long combinationSum[1<<14] {};
vector<long long> memo {};

void generate_codes(long long pos, long long currVal, vector<long long> &components, vector<long long> &codes){
    if(pos >= components.size()){
        codes.push_back(currVal);
        return;
    }

    if(pos > 0){
        generate_codes(pos+1, currVal, components, codes);
    }
    generate_codes(pos+1, currVal + components[pos], components, codes);
}

long long dp(long long remItems){
    long long &curr {memo[remItems]};

    if (curr != -1){
        return curr;
    }

    curr = ndFactors[combinationSum[remItems]];

    //disect components
    long long temp {remItems};
    vector<long long> components = {};
    while(temp != 0){
        long long x {LSOne(temp)};
        components.push_back(x);
        temp -= x;
    }

    vector<long long> codes {};
    codes.reserve(1L<<(components.size()));
    generate_codes(0, 0, components, codes);
    for(long long code:codes){
        long long other {remItems - code};
        if(other != 0){
            curr = max(curr, dp(code) + dp(other));
        }
    }

    return curr;
}

int main(){
    //initialize
    for(long long i=2;i<=MAXVAL;++i){
        if(ndFactors[i]  == 0){
            for(long long j=i;j<=MAXVAL;j+=i){
                ++ndFactors[j];
            }
        }
    }

    long long nValues;
    cin >> nValues;
    long long val;

    long long ans {};
    for(long long i=0;i<nValues;++i){
        cin >> values[i];
    }

    combinationSum[0] = 0;

    for(long long itemIdx=0;itemIdx<nValues;++itemIdx){
        long long &currItem {values[itemIdx]};
        long long startIdx {1L<<itemIdx};
        long long* src {combinationSum};
        long long* dest {combinationSum + startIdx};
        for(long long i=0;i<startIdx;++i){
            *dest = *(src++) + currItem;
            ++dest;
        }
    }

    memo.assign(1<<nValues, -1);
    memo[0] = 0;

    ans = dp((1<<nValues)-1);
    cout << ans << '\n';
}