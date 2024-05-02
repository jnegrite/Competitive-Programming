#include<cstdio>
#include<vector>

using namespace std;

vector<long> p, rk, sz, sumElem;
long nItems, nCommands, a, b, p1, p2;
int cmd;

long getParent(long i){
    return p[i]==i?i:getParent(p[i]);
}

void combineSet(long i1, long i2){
    long p1 = getParent(i1+nItems);
    long p2 = getParent(i2+nItems);
    
    if(p1 == p2){
        return;
    }

    if(rk[p1] < rk[p2]){
        swap(p1,p2);
    } else if(rk[p1]==rk[p2]){
        ++rk[p1];
    }

    p[p2] = p1;
    sz[p1] += sz[p2];
    sz[p2] = 0;
    sumElem[p1] += sumElem[p2];
    sumElem[p2] = 0;
}

void moveItem(long i1, long i2){
    long p1 = getParent(i1+nItems);
    long p2 = getParent(i2+nItems);

    if(p1 == p2){
        return;
    }

    --sz[p1];
    ++sz[p2];
    sumElem[p1] -= i1;
    sumElem[p2] += i1;
    if(rk[p2] == 0){
        rk[p2]++;
    }
    p[i1+nItems] = p2;
}

int main(){
    while(scanf("%ld %ld\n",&nItems,&nCommands)!= EOF){
        
        p.assign(2*nItems+1,0);
        sumElem.assign(nItems+1,0);
        rk.assign(nItems+1,0);
        sz.assign(nItems+1,1);

        for(long i=1;i<=nItems;i++){
            p[i+nItems] = i;
            p[i]=i;
            sumElem[i] = i;
        }

        while(nCommands--){
            scanf("%d %ld",&cmd,&a);
            switch(cmd){
                case 1:
                    scanf("%ld\n",&b);
                    combineSet(a,b);
                    break;
                case 2:
                    scanf("%ld\n",&b);
                    moveItem(a,b);
                    break;
                case 3:
                    b = getParent(a+nItems);
                    printf("%ld %ld\n",sz[b],sumElem[b]);
                    break;
            }

        }
    }
}