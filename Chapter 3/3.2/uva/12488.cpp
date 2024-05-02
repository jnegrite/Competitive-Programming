#include<cstdio>

using namespace std;

int main(){
    int positions[25] {};
    int nPlayers {};
    int curr;
    while(scanf("%d\n",&nPlayers)!=EOF){

        bool seen[25] {};
        //record initial positions
        for(int i=0;i<nPlayers;++i){
            scanf("%d",&positions[i]);
        }

        int ans {0};
        for(int i=0;i<nPlayers;i++){
            scanf("%d",&curr);
            for(int j=0;positions[j] != curr;++j){
                if(!seen[positions[j]]){
                    ++ans;
                }
            }
            seen[curr] = true;
        }
        printf("%d\n",ans);
    }
}