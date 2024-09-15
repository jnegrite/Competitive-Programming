#include<cstdio>
#include<bitset>

using namespace std;

int main(){
    unsigned val;
    while(scanf("%u\n",&val), val != 0u){
        bitset<32> bitVals {val};
        string ans {bitVals.to_string()};
        auto pos {ans.find('1')};
        printf("The parity of %s is %d (mod 2).\n", ans.substr(pos).c_str(), __builtin_popcount(val));
    }
}