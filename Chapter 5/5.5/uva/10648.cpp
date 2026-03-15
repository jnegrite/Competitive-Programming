#include<cstdio>
#include<cstring>

using namespace std;

int nChocolates, nBoxes;
bool visited[101][101] {};
double memo[101][101] {};

double dp(int remChocolates, int emptyBoxes){
    if(remChocolates < emptyBoxes){
        return 1;
    }

    if(emptyBoxes == 0){
        return 0;
    }

    double &ans {memo[remChocolates][emptyBoxes]};

    if(visited[remChocolates][emptyBoxes]){
        return ans;
    } else {
        visited[remChocolates][emptyBoxes]=true;
    }

    ans = ((nBoxes-emptyBoxes)*(dp(remChocolates-1,emptyBoxes)) + (emptyBoxes)*dp(remChocolates-1,emptyBoxes-1))/nBoxes;
    return ans;
}

int main(){
    int nCases = 0;
    while(scanf("%d",&nChocolates), nChocolates != -1){
        scanf("%d",&nBoxes);
        memset(memo,0,sizeof(memo));
        memset(visited,false,sizeof(visited));
        
        printf("Case %d: %.07lf\n",++nCases, dp(nChocolates,nBoxes));
    }
}