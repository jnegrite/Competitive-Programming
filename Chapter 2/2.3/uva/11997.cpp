#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

long df[750][750] {};
long dfAns[750] {};
int k;
long minSum {};

int main(){
    long val;
    while(scanf("%d",&k) != EOF){
        
        //get initial data
        for(int row=0;row<k;row++){
            for(int col=0;col<k;col++){
                scanf("%ld",&df[row][col]);
            }
            sort(df[row],df[row]+k);
        }

        //fill active with initial data
        for(int i=0;i<k;i++){
            dfAns[i] = df[0][i];
        }

        for(int row=1;row<k;row++){
            priority_queue<long,vector<long>, greater<long>> qB {};
            int pos1 {0};
            int pos2 {0};

            while((pos1+1) * (pos2+1) < 2*k){
                if(pos2 == k-1 || (pos1 < k-1 && dfAns[pos1+1] - dfAns[0] <= df[row][pos2+1] - df[row][0])){
                    pos1++;
                } else {
                    pos2++;
                }
            }

            for(int i=0;i<=pos1;i++){
                for(int j=0;j<=pos2;j++){
                    qB.emplace(dfAns[i] + df[row][j]);
                }
            }

            for(int i=0;i<k;i++){
                dfAns[i] = qB.top();
                qB.pop();
            }
        }

        printf("%ld",dfAns[0]);

        for(int i=1;i<k;i++){
            printf(" %d",dfAns[i]);
        }
        printf("\n");
   }
}