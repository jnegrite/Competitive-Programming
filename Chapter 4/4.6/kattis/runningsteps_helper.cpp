#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
using ll = long long;

using tKey = tuple<int,int,int,int,int,int>;

struct key_hash : public unary_function<tKey, size_t>
{
 size_t operator()(const tKey& k) const
 {
   return get<0>(k) ^ get<1>(k) ^ get<2>(k) ^ get<3>(k) ^ get<4>(k) ^ get<5>(k);
 }
};


//leg-l2-l1-r2-r1
unordered_map<tKey,ll,key_hash> memo {};
int p;

ll dp(int leg, int rem, int l2, int l1, int r2, int r1){

    if((rem < 0) || (((abs(l2-r2)<<1) + abs(l1-r1) > rem))){
        return 0LL;
    } else if (rem==0){
        if(l2==r2 && l1==r1 && l2>=l1){
            return 1LL;
        } else {
            return 0LL;
        }
    }

    tKey s{make_tuple(leg,rem,l2,l1,r2,r1)};
    auto it {memo.find(s)};
    if(it != memo.end()){
        return it->second;
    }

    if(leg==0){
        memo[s] = dp(1,rem-2,l2+1,l1,r2,r1) + dp(1,rem-1,l2,l1+1,r2,r1);
    } else {
        memo[s] = dp(0,rem-2,l2,l1,r2+1,r1) + dp(0,rem-1,l2,l1,r2,r1+1);
    }
    return memo[s];
}

int main(){
    memo.clear();
    for(int val=2;val<=100;val+=2){
        cout << val << ' ' << dp(0,val,0,0,0,0) << '\n';
    }
}