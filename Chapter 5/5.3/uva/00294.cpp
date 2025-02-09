#include<cstdio>
#include<unordered_map>

using namespace std;

using um = unordered_map<long, int>;

void addFactor(long val, um &f){
    if(val==1){
        return;
    }
    auto it {f.find(val)};
    if(it == f.end()){
        f[val] = 1;
    } else {
        f[val] = (1+ it->second);
    }
}

void primeFactorize(long val, long start, um &f){
    for(long i=start; i*i <= val; ++i){
        if(val%i == 0){
            addFactor(i,f);
            primeFactorize(val/i,i,f);
            return;
        }
    }

    addFactor(val,f);
}

long getNumDivisors(long val){
    um f {};
    primeFactorize(val,2,f);
    long ans {1};
    for(auto it: f){
        ans *= (1 + it.second);
    }
    return ans;
}

int main(){
    int nCases;
    long low, high;
    scanf("%d",&nCases);
    while(nCases--){
        scanf("%ld %ld",&low,&high);
        long bestNum {low};
        long bestScore {getNumDivisors(low)};

        for(long i=low+1;i<=high;++i){
            long tempScore {getNumDivisors(i)};
            if(tempScore > bestScore){
                bestNum = i;
                bestScore = tempScore;
            }
        }

        printf("Between %ld and %ld, %d has a maximum of %d divisors.\n",low,high,bestNum,bestScore);

    }
}