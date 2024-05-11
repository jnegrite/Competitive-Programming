#include<cstdio>
#include<vector>
#include<queue>

#define INF 1000000

using namespace std;
int nStages;
vector<int> lab {};
vector<vector<int>> dependencies {};
vector<int> reqs_cache {};
vector<int> reqs {};
vector<queue<int>> q {{},{}};

int a, b;
int remStages;

void process(int pos){
    for(int nxt:dependencies[pos]){
        if((--reqs[nxt]) == 0){
            q[lab[nxt]].push(nxt);
        }
    }
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    while(nCases--){
        int nDependencies;
        scanf("%d %d\n",&nStages,&nDependencies);
        lab.assign(nStages+1,0);
        dependencies.assign(nStages+1,{});
        reqs_cache.assign(nStages+1,0);
        reqs.assign(nStages+1,0);

        //get lab data
        for(int i=1;i<=nStages;++i){
            scanf("%d",&lab[i]);
            --lab[i];
        }

        //get dependencies data
        while(nDependencies--){
            scanf("%d %d\n",&a,&b);
            dependencies[a].push_back(b);
            ++reqs_cache[b];
        }

        //simulate
        int minSwaps {INF};
        for(int startLab=0;startLab<2;startLab++){
            int currLab = startLab;

            copy(reqs_cache.begin(),reqs_cache.end(),reqs.begin());

            q.assign(2,{});
            
            //populate queues
            int nSwaps {0};
            remStages = nStages;
            for(int i=1;i<=nStages;++i){
                if(reqs[i] == 0){
                    q[lab[i]].push(i);
                }
            }

            while(remStages>0){
                
                //try processing current queue
                while(!q[currLab].empty()){
                    remStages--;
                    process(q[currLab].front());
                    q[currLab].pop();
                }

                if(!q[1-currLab].empty()){
                    currLab = 1 - currLab;
                    nSwaps++;
                } else {
                    break;
                }
            }

            if(remStages == 0 && nSwaps < minSwaps){
                minSwaps = nSwaps;
            }
        }
        printf("%d\n",minSwaps);
    }
}