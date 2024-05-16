#include<cstdio>
#include<vector>
#include<stack>
#include<set>

using namespace std;

int nStatements;
vector<vector<int>> paths {};
vector<vector<int>> pathsRev {};
vector<int> inCount {};
vector<int> outCount {};
vector<bool> visited {};
vector<int> group {};
stack<int> ts {};
int nGroups;

vector<set<int>> pathsGroup {};
stack<int> tsGroup {};


void topsort(int pos, int groupCtr){
    visited[pos] = true;
    vector<int> &curr {groupCtr < 0 ? paths[pos] : pathsRev[pos]};
    for(int &nxt: curr){
        if(!visited[nxt]){
            topsort(nxt,groupCtr);
        }
    }

    if(groupCtr<0){
        ts.push(pos);
    } else {
        group[pos] = groupCtr;
    }
}

int nIn{};
int nOut{};

void topsortGroup(int pos, bool append=true){
    visited[pos] = true;
    auto &curr {pathsGroup[pos]};

    if(curr.size()==0){
        nOut++;
    }
    for(auto it {curr.begin()};it!=curr.end();++it){
        if(!visited[*it]){
            topsortGroup(*it,append);
        }
    }
    if(append){
        ts.push(pos);
    }
}

void traverse(int pos){
    visited[pos] = true;
    for(int &nxt:paths[pos]){
        //add graph if not from the same family
        if(group[pos] != group[nxt]){
            pathsGroup[group[pos]].emplace(group[nxt]);
        }

        if(!visited[nxt]){
            traverse(nxt);
        }
    }
}

int main(){
    int nCases;
    int nRelations;
    scanf("%d\n",&nCases);
    while(nCases--){
        scanf("%d %d\n",&nStatements,&nRelations);
        nStatements++;
        paths.assign(nStatements,{});
        pathsRev.assign(nStatements,{});

        int a, b;
        while(nRelations--){
            scanf("%d %d\n",&a,&b);
            paths[a].push_back(b);
            pathsRev[b].push_back(a);
        }

        //traverse forward
        visited.assign(nStatements,false);
        for(int i=1;i<nStatements;++i){
            if(!visited[i]){
                topsort(i,-1);
            }
        }

        //traverse backward
        nGroups = 0;
        visited.assign(nStatements,false);
        group.assign(nStatements,-1);
        while(!ts.empty()){
            if(!visited[ts.top()]){
                topsort(ts.top(),nGroups++);
            }
            ts.pop(); 
        }

        //traverse, create the reduced DAG
        visited.assign(nStatements,false);
        pathsGroup.assign(nGroups,{});
        for(int i=1;i<nStatements;++i){
            if(!visited[i]){
                traverse(i);
            }
        }

        //topsort dag
        while(!ts.empty()){
            ts.pop();
        }
        visited.assign(nGroups,false);
        for(int i=0;i<nGroups;++i){
            if(!visited[i]){
                topsortGroup(i,true);
            }
        }
        
        //process dag
        nIn = 0;
        nOut = 0;

        visited.assign(nGroups,false);
        while(!ts.empty()){
            if(!visited[ts.top()]){
                nIn++;
                topsortGroup(ts.top(),false);
            }
            ts.pop();
        }

        int ans {0};
        if(nGroups != 1){
            ans=max(nIn,nOut);
        }
        printf("%d\n",ans);
    }
}