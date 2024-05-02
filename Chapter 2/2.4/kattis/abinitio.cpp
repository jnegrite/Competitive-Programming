#include<cstdio>
#include<malloc.h>
#include<algorithm>

using namespace std;


int main(){
    int V, Q;
    long E;
    int from, to;
    int activeFlag {1};
    int inactiveFlag{0};
    bool normal {true};
    int cmd;
    int val;
    int (*g)[4000] = (int (*)[4000])malloc(sizeof(*g) * 4000);
    long multiplier {1L};
    int numNeighbors {};
    long hash {};

    scanf("%d %ld %d\n", &V, &E, &Q);

    //read edges
    for(long i=0;i<E;i++){
        scanf("%d %d\n",&from,&to);
        g[from][to] = activeFlag;
    }

    for(int i=0;i<Q;i++){
        scanf("%d",&cmd);
        switch(cmd){
        case 1:
            for(int j=0;j<V;j++){
                g[V][j] = g[j][V] = inactiveFlag;
            }
            V++;
            break;
        case 2:
            if(normal){
                scanf("%d %d\n",&from,&to);
            } else {
                scanf("%d %d\n",&to,&from);
            }
            g[from][to] = activeFlag;
            break;
        case 3:
            scanf("%d\n", &val);
            for(int j=0;j<V;j++){
                g[val][j] = g[j][val] = inactiveFlag;
            }
            break;
        case 4:
            if(normal){
                scanf("%d %d\n",&from,&to);
            } else {
                scanf("%d %d\n",&to,&from);
            }
            g[from][to] = inactiveFlag;
            break;
        case 5:
            normal ^= normal;
            break;
        case 6:
            activeFlag ^= 1;
            inactiveFlag ^= 1;
            break;
        }
    }


    const long div {1000000007L};
    printf("%d\n",V);
    if(normal){
        for(int i=0;i<V;i++){
            multiplier = 1L;
            numNeighbors = 0;
            hash = 0;
            for(int j=0;j<i;j++){
                if((g[i][j] == activeFlag)){
                    long subFactor {(j * multiplier)%div};
                    hash = (hash+subFactor)%div;
                    ++numNeighbors;
                    multiplier = (7*multiplier)%div;
                }
            }
            for(int j=i+1;j<V;j++){
                if((g[i][j] == activeFlag)){
                    long subFactor {(j * multiplier)%div};
                    hash = (hash+subFactor)%div;
                    ++numNeighbors;
                    multiplier = (7*multiplier)%div;
                }
            }
            printf("%d %ld\n",numNeighbors,hash);
        }
    } else {
        for(int i=0;i<V;i++){
            multiplier = 1L;
            numNeighbors = 0;
            hash = 0;
            for(int j=0;j<i;j++){
                if((g[j][i] == activeFlag)){
                    long subFactor {(j * multiplier)%div};
                    hash = (hash+subFactor)%div;
                    ++numNeighbors;
                    multiplier = (7*multiplier)%div;
                }
            }
            for(int j=i+1;j<V;j++){
                if((g[j][i] == activeFlag)){
                    long subFactor {(j * multiplier)%div};
                    hash = (hash+subFactor)%div;
                    ++numNeighbors;
                    multiplier = (7*multiplier)%div;
                }
            }
            printf("%d %ld\n",numNeighbors,hash);
        }
    }

    free(g);
}