#include<cstdio>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

unordered_map<char,int> mapIds {};
vector<char> ids {};

int dist[26][26] {};
int p[26][26] {};
int nJumps[26][26] {};

vector<int> path {};

void getPath(int from, int to){
    int mid = p[from][to];

    if(mid==from){
        path.push_back(from);
    } else {
        getPath(from, mid);
        getPath(mid, to);
    }
}

int getId(char ch){
    auto it {mapIds.find(ch)};
    
    if(it!=mapIds.end()){
        return it->second;
    }

    int ans = mapIds[ch] = ids.size();
    ids.push_back(ch);
    return ans;
}

int main(){
    int nValues;
    int nPaths;

    char ch1, ch2;
    int id1, id2, cost;

    scanf("%d %d\n",&nValues,&nPaths);


    for(int i=0;i<nValues;i++){
        for(int j=0;j<nValues;j++){
            dist[i][j] = (i==j? 0 : 10000);
            p[i][j] = i;
            nJumps[i][j] = 0;
        }
    }

    while(nPaths--){
        scanf("%c %c %d\n",&ch1,&ch2,&cost);
        id1 = getId(ch1);
        id2 = getId(ch2);
        nJumps[id1][id2] = nJumps[id2][id1] = 1;
        dist[id1][id2] = dist[id2][id1] = cost;
    }

    //processing
    for(int k=0;k<nValues;k++){
        for(int i=0;i<nValues;i++){
            for(int j=0;j<nValues;j++){
                int tempCost {dist[i][k] + dist[k][j]};

                if(tempCost < dist[i][j] ||
                        ((tempCost == dist[i][j]) && (nJumps[i][j] > (nJumps[i][k] + nJumps[k][j])))){
                    nJumps[i][j] = nJumps[i][k] + nJumps[k][j];
                    dist[i][j] = tempCost;
                    p[i][j] = k;
                }
            }
        }
    }

    int nQueries;
    scanf("%d\n",&nQueries);
    while(nQueries--){
        scanf("%c %c\n",&ch1,&ch2);
        id1 = getId(ch1);
        id2 = getId(ch2);

        path.clear();
        getPath(id1,id2);

        for(int v:path){
            printf("%c ",ids[v]);
        }
        printf("%c\n",ids[id2]);
    }
}