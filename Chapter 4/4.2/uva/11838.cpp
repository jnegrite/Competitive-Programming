#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

int nIntersections;
vector<vector<int>> paths {};
vector<vector<int>> pathsRev {};
vector<bool> visited {};
stack<int> st {};

void kosaraju(int pos, bool forwards){
    visited[pos] = true;
    auto &curr {forwards? paths[pos] : pathsRev[pos]};
    for(int &nxt: curr){
        if(!visited[nxt]){
            kosaraju(nxt,forwards);
        }
    }

    if(forwards){
        st.push(pos);
    }
}

int main(){
    int nStreets;
    while(scanf("%d %d\n",&nIntersections,&nStreets),nIntersections!=0 || nStreets!=0){
        ++nIntersections;
        paths.assign(nIntersections,{});
        pathsRev.assign(nIntersections,{});

        while(!st.empty()){
            st.pop();
        }

        int a, b, p;
        while(nStreets--){
            scanf("%d %d %d\n",&a,&b,&p);
            paths[a].push_back(b);
            pathsRev[b].push_back(a);

            if(p==2){
                paths[b].push_back(a);
                pathsRev[a].push_back(b);
            }
        }


        //forwards
        visited.assign(nIntersections,false);
        for(int i=1;i<nIntersections;++i){
            if(!visited[i]){
                kosaraju(i,true);
            }
        }

        int nSCC {0};
        visited.assign(nIntersections,false);
        while(!st.empty()){
            int nxt {st.top()};
            st.pop();

            if(!visited[nxt]){
                nSCC++;
                kosaraju(nxt,false);
            }
        }

        if(nSCC <= 1){
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
}
