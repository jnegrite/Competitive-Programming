#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
int nSticks;
vector<int> deps {};
vector<vector<int>> paths {};
int a, b;
queue<int> q {};
queue<int> finQ {};

void process(int pos){
    finQ.push(pos);
    for(int nxt:paths[pos]){
        if((--deps[nxt]) == 0){
            q.push(nxt);
        }
    }
}

int main(){
    int nDeps;
    scanf("%d %d\n",&nSticks,&nDeps);

    deps.assign(nSticks+1,0);
    paths.assign(nSticks+1,{});

    while(nDeps--){
        scanf("%d %d\n",&a,&b);
        paths[a].push_back(b);
        ++deps[b];
    }

    //generate initial
    for(int i=1;i<=nSticks;++i){
        if(deps[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        process(q.front());
        q.pop();
    }

    if(finQ.size() == nSticks){
        while(!finQ.empty()){
            printf("%d\n",finQ.front());
            finQ.pop();
        }
    } else {
        printf("IMPOSSIBLE\n");
    }
}