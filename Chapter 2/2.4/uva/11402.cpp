#include<cstdio>
#include<cstring>
#include<bitset>
#include<malloc.h>

#define L(x) ((x) << 1)
#define R(x) (((x) << 1) + 1)

using namespace std;
int depth;
string s;

const long arrLen {10240001};

bitset<arrLen> initPirates {};

long st[4*arrLen] {};
char lazy[4*arrLen] {};

void build(long p, long from, long to){
    if(from==to){
        st[p] = initPirates.test(from);
    } else {
        long m {(from + to) >> 1};
        build(L(p),from,m);
        build(R(p),m+1,to);
        st[p] = st[L(p)] + st[R(p)];
    }
    lazy[p] = 'X';
}

void applyLazy(long p, char op){
    if(op=='I'){
        switch(lazy[p]){
            case 'F':
                lazy[p] = 'E';
                break;
            case 'E':
                lazy[p] = 'F';
                break;
            case 'I':
                lazy[p] = 'X';
                break;
            case 'X':
                lazy[p] = 'I';
        }
    } else {
        lazy[p] = op;
    }
}

void propagate(long p, long from, long to){
    switch(lazy[p]){
        case 'F':
            st[p] = to - from + 1;
            break;
        case 'E':
            st[p] = 0;
            break;
        case 'I':
            st[p] = to - from + 1 - st[p];
            break;
    }

    if(from != to){
        applyLazy(L(p),lazy[p]);
        applyLazy(R(p),lazy[p]);
    }
    lazy[p] = 'X';
}

void update(long p, long from, long to, long i, long j, char op){
    if(lazy[p] != 'X'){
        propagate(p, from, to);
    }
    if(i <= from && to <= j){
        switch(op){
            case 'F':
                st[p] = to - from + 1;
                break;
            case 'E':
                st[p] = 0;
                break;
            case 'I':
                st[p] = to - from + 1 - st[p];
                break;
        }

        if(from != to){
            applyLazy(L(p),op);
            applyLazy(R(p),op);
        }
    } else if (i > to || j < from){

    } else if (from!=to){
        long m {(from + to) >> 1};
        update(L(p),from, m, i, j, op);
        update(R(p),m+1,to,i,j,op);
        st[p] = st[L(p)] + st[R(p)];
    }
}

long search(long p, long from, long to, long i, long j){
    if(lazy[p] != 'X'){
        propagate(p, from, to);
    }

    if(i <= from && to <= j){
        return st[p];
    } else if (i > to || j < from){
        return 0L;
    } else if(from != to){
        long m {(from+to)>>1};
        return search(L(p),from,m,i,j) + search(R(p),m+1,to,i,j);
    }
    return 0;
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    
    for(int tc=1;tc<=nCases;tc++){
        int M;
        
        scanf("%d\n",&M);
        
        int reps;
        long totalPirates {0};
        char s[100] {};
        while(M--){
            scanf("%d %s\n", &reps, &s);
            auto len {strlen(s)};
            while(reps--){
                for(long long unsigned i=0;i<len;i++){
                    if(s[i] == '1'){
                        initPirates.set(totalPirates++);
                    } else {
                        initPirates.reset(totalPirates++);
                    }
                }
            }
        }

        build(1,0,totalPirates-1);
        
        int nQueries;
        scanf("%d\n",&nQueries);
        string op;
        long from, to;
        long qCount = 0;
        printf("Case %d:\n",tc);
        while(nQueries--){
            char chOp;
            scanf("%c %ld %ld\n", &chOp, &from, &to);
            switch(chOp){
                case 'F':
                case 'E':
                case 'I':
                    update(1,0,totalPirates-1,from,to,chOp);
                    break;
                case 'S':
                   printf("Q%ld: %ld\n",++qCount,search(1,0,totalPirates-1,from,to));
            }
        }
    }   
}