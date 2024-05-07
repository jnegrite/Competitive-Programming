#include<cstdio>
#include<vector>

using namespace std;

vector<vector<int>> connections {};
vector<bool> isVisited {};

void dfs(int pos){
    isVisited[pos] = true;
    for(auto nxt: connections[pos]){
        if(!isVisited[nxt]){
            dfs(nxt);
        }
    }
}

int main(){
    int nHouses, nConnections;
    scanf("%d %d\n",&nHouses,&nConnections);
    isVisited.assign(nHouses+1,false);
    connections.assign(nHouses+1,{});

    int a, b;
    while(nConnections--){
        scanf("%d %d\n",&a,&b);
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    
    dfs(1);

    bool connected {true};
    for(int i=1;i<=nHouses;i++){
        if(!isVisited[i]){
            printf("%d\n",i);
            connected = false;
        }
    }

    if(connected){
        printf("Connected\n");
    }

}