#include<cstdio>
#include<algorithm>

using namespace std;

struct Block {
    int l {};
    int m {};

    Block(int _l, int _m){
        l=_l;
        m=_m;
    }

    Block(){};

    bool operator<(const Block &o) const {
        if(l != o.l){
            return l < o.l;
        } else {
            return m < o.m;
        }
    }
};

Block blocks[10000] {};
long L[10000] {};
long k;

int main(){
    long n;
    while(scanf("%ld\n",&n), n!=0){
        for(long i=0;i<n;++i){
            Block &curr {blocks[i]};
            scanf("%d %d",&curr.l,&curr.m);
        }

        sort(blocks, blocks+n);

        k=0;
        for(long i=0;i<n;++i){
            int val {blocks[i].m};
            long pos {upper_bound(L,L+k,val) - L};

            L[pos] = val;
            
            if(pos==k){
                ++k;
            }
        }

        printf("%ld\n",k);
    }
    printf("*\n");
}