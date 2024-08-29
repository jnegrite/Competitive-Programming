#include<iostream>

using namespace std;

//1000, 2, 100
long long cntZeroByPos(long long val, int pos, long long factor){
    if(pos==0){
        return val/10;
    }
    long long ans {0};
    
    //check how many times it will be 0
    long long temp {factor *(val/(factor*10) - 1)};
    ans += temp;

    temp = min(factor, 1+(val%(10*factor)));
    ans += temp;
    return ans;
}


long long cntZeroes(long long val){
    if(val<0){
        return 0;
    }

    int currPos {0};
    long long currFactor {1LL};
    long long ans {0};
    
    while(currFactor*10LL <= val){
        long long inc = cntZeroByPos(val,currPos, currFactor);
        //cout << '\t' << currPos << ": " << inc << '\n';
        ans += inc;
        ++currPos;
        currFactor *= 10;
    }
    return 1 + ans;
}

int main(){
    long long a, b;
    while(cin >> a >> b, a>=0){
        cout << cntZeroes(b) - cntZeroes(a-1) << '\n';
    }
}