#include<cstdio>
#include<vector>
#include<stack>

using namespace std;
using vi = vector<int>;

int nDominoes {};
vector<vi> paths {};
vi visited {};
stack<int> ts {};

void topsort(int pos, bool append=false){
    visited[pos] = true;
    for(int &nxt:paths[pos]){
        if(!visited[nxt]){
            topsort(nxt,append);
        }
    }

    if(append){
        ts.push(pos);
    }
}

int main(){
    int nCases;
    int nRelations;
    scanf("%d\n",&nCases);
    while(nCases--){
        scanf("%d %d\n",&nDominoes,&nRelations);
        nDominoes++;
        paths.assign(nDominoes,{});
        visited.assign(nDominoes,false);

        int a, b;
        while(nRelations--){
            scanf("%d %d\n",&a,&b);
            paths[a].push_back(b);
        }

        //create base ts
        for(int i=1;i<nDominoes;i++){
            if(!visited[i]){
                topsort(i,true);
            }
        }

        int ans {};
        visited.assign(nDominoes,false);
        while(!ts.empty()){
            int nxt {ts.top()};
            ts.pop();

            if(!visited[nxt]){
                ans++;
                topsort(nxt,false);
            }
        }
        printf("%d\n",ans);
    }
}