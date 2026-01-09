#include<cstdio>
#include<iostream>

using namespace std;

int nItems, nSelected;
double memo[2][21][21] {};
double probSelected[21] {};

void clearMemo(){
    for(int i=0;i<=1;++i){
        for(int j=0;j<=20;++j){
            for(int k=0;k<=20;++k){
                memo[i][j][k] = -1;
            }
        }
    }
}

//direction (0:from fron, 1:from back), up to what position, items counted
double dp(int dir, int pos, int items){
    if((dir == 0 &&pos < 0) || (dir==1 && pos >= nItems)){
        return items==0?1:0;
    }

    if (dir == 0 && pos==0){
        if (items == 0){
            return 1-probSelected[pos];
        } else if (items == 1){
            return probSelected[pos];
        } else {
            return 0;
        }
    }

    if(dir == 1 && pos == (nItems-1)){
        if (items == 0){
            return 1-probSelected[pos];
        } else if (items == 1){
            return probSelected[pos];
        } else {
            return 0;
        }
    }

    //check memo
    double &ans {memo[dir][pos][items]};

    if(ans != -1){
        return ans;
    }

    if(dir == 0){
        ans = probSelected[pos] * dp(dir,pos-1,items-1) + (1-probSelected[pos]) * dp(dir,pos-1,items);
    } else {
        ans = probSelected[pos] * dp(dir,pos+1,items-1) + (1-probSelected[pos]) * dp(dir,pos+1,items);
    }

    return ans;
}

int main(){
    int caseNum {0};
    while(scanf("%d %d\n", &nItems, &nSelected), nItems!=0){
        clearMemo();

        for(int i=0;i<nItems;++i){
            scanf("%lf\n",&probSelected[i]);
        }

        printf("Case %d:\n",++caseNum);
        int cntOthers {nSelected-1};
        for(int item=0;item<nItems;++item){
            double multiplier {0};
            for(int i=0;i<=cntOthers;++i){
                multiplier += dp(0,item-1,i)*dp(1,item+1,cntOthers-i);
            }
            printf("%0.6lf\n",(multiplier*probSelected[item])/dp(1,0,nSelected));
        }
    }

}