#include<cstdio>
#include<vector>

using namespace std;
int counts[2] {};
int nPeople {};
vector<int> org {};
vector<vector<int>> enemies {};
bool isBipartite {};

void process(int pos, int orgNum){
    ++counts[orgNum];
    org[pos] = orgNum;
    for(int &nxt:enemies[pos]){
        if(org[nxt] == -1){
            process(nxt, 1-orgNum);
        } else if (org[nxt] != (1-orgNum)){
            isBipartite = false;
        }
    }
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    while(nCases--){
        scanf("%d\n",&nPeople);
        org.assign(nPeople+1,-1);
        enemies.assign(nPeople+1,{});

        //get enemies data;
        int nEnemies;
        int enemy;
        for(int curr=1;curr<=nPeople;++curr){
            scanf("%d\n",&nEnemies);
            while(nEnemies--){
                scanf("%d\n",&enemy);

                if(enemy > nPeople){
                    continue;
                }
                enemies[curr].push_back(enemy);
                enemies[enemy].push_back(curr);
            }
        }

        int maxInvited {};
        for(int i=1;i<=nPeople;++i){
            if(org[i] == -1){
                isBipartite=true;
                counts[0] = counts[1] = 0;
                process(i,0);
                if(isBipartite){
                    maxInvited += max(counts[0],counts[1]);
                }
            }
        }
        printf("%d\n",maxInvited);
    }
}
