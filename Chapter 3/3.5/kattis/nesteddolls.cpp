#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;
using ii = pair<long,long>;

struct Doll {
    long height {};
    long width {};

    Doll(long _height, long _width){
        height = _height;
        width = _width;
    }

    Doll(){};

    bool operator<(const Doll &o) const {
        if(height != o.height){
            return height < o.height;
        } else {
            return width > o.width;
        }
    }

};

int main(){
    int nCases {};
    scanf("%d",&nCases);
    while(nCases--){
        Doll dolls[100000] {};
        long nDolls {};
        long w, h;

        scanf("%ld\n",&nDolls);

        for(long i=0;i<nDolls;++i){
            Doll &curr {dolls[i]};
            scanf("%ld %ld",&(curr.width), &(curr.height));
        }

        sort(dolls,dolls+nDolls);
        long L[100000] {};
        long L_id[100000] {};
        long p[100000] {};
        long k {0};
        long last_idx {0};

        memset(p,-1,sizeof(p));
        

        for(long i=0;i<nDolls;++i){
            Doll &curr {dolls[i]};
            long pos = upper_bound(L,L+k,curr.width,greater<long>()) - L;
            L[pos] = curr.width;
            L_id[pos] = i;
            p[i] = pos? L[pos-1]: -1;

            if(pos==k){
                ++k;
            }
        }
        
        printf("%ld\n",k);
    }

}