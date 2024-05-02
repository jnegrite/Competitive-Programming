#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct StructNumber{
    long value {};
    long modN {};
    long mod2 {};

    StructNumber(long _val, long N){
        value = _val;
        
        if(value >= 0){
            modN = value%N;
        } else {
            modN = -((-value)%N);
        }
        mod2 = abs(value%2);
    }

    
    bool operator<(const StructNumber o){
        if(modN != o.modN){
            return modN < o.modN;
        } else if (mod2 != o.mod2){
            return mod2 > o.mod2;
        } else if(mod2 == 1){
            return value > o.value;
        } else {
            return value < o.value;
        }
    }
    
};

int main(){
    long M, N;
    while(true){
        cin >> M >> N;
        cout << M << ' ' << N << '\n';
        if(M==0 && N==0){
            break;
        }
        
        vector<StructNumber> numbers {};
        for(long i=0;i<M;i++){
            long v;
            cin >> v;
            StructNumber num {v,N};
            numbers.push_back(num);
        }

        sort(numbers.begin(), numbers.end());

        
        for(StructNumber num:numbers){
            cout << num.value << '\n';
        }
    }
}