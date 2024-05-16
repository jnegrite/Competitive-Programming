#include<cstdio>
#include<vector>
#include<stack>

using namespace std;
int nPeople, nConnections;

vector<vector<int>> paths {};
stack<int> ts {};
vector<bool>visited {};

void topsort(int pos, bool append=true){
    visited[pos] = true;
    for(int &nxt: paths[pos]){
        if(!visited[nxt]){
            topsort(nxt);
        }
    }

    if(append){
        ts.push(pos);
    }
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    for(int tc=1;tc<=nCases;tc++){
        scanf("%d %d\n",&nPeople,&nConnections);
        nPeople++;

        paths.assign(nPeople,{});
        visited.assign(nPeople,false);

        int a, b;
        while(nConnections--){
            scanf("%d %d\n",&a,&b);
            paths[a].push_back(b);
        }

        while(!ts.empty()){
            ts.pop();
        }

        //do topsort
        for(int i=1;i<nPeople;++i){
            if(!visited[i]){
                topsort(i);
            }
        }

        //reverse
        int nSCC {};
        visited.assign(nPeople,false);
        while(!ts.empty()){
            if(!visited[ts.top()]){
                nSCC++;
                topsort(ts.top(),false);
            }
            ts.pop();
        }

        printf("Case %d: %d\n",tc,nSCC);
    }
}