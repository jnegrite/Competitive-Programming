#include<iostream>
#include<cstring>
#include<unordered_map>
#include<algorithm>
#include<stack>

#define LSOne(x) ((x) & -(x))

using namespace std;

int nNodes;
int nEdges;
char nodes[15] {};
int paths[15] {};

int memo[15][1<<16] {};

stack<int> finPath {};

int dp(int pos, int mask){
    if(mask == 0){
        if(paths[pos] & (1<<(nNodes-1))){
            finPath.push(pos);
            return 1;
        } else {
            return 0;
        }
    }

    auto &curr {memo[pos][mask]};

    switch(curr){
        case 1:
            finPath.push(pos);
            return 1;
        case 0:
            return 0;
    }

    curr = 0;
    int tMask {mask & paths[pos]};
    while(tMask!=0){
        int flag {LSOne(tMask)};
        int target {__builtin_ctz(flag)};
        
        if(dp(target,mask ^ flag)){
            finPath.push(pos);
            return curr=1;
        }
        tMask -= flag;
    }

    return curr;
}

int main(){
    int nCases;
    cin >> nCases;
    for(int tc=1;tc<=nCases;++tc){
        cin >> nNodes >> nEdges;

        //get nodes
        for(int i=0;i<nNodes;++i){
            cin >> ws >> nodes[i];
        }

        sort(nodes+1,nodes+nNodes-1);

        unordered_map<char,int> mapping {};
        for(int i=0;i<nNodes;++i){
            mapping[nodes[i]] = i;
        }

        //process edges
        memset(paths,0,sizeof(paths));
        char a, b;
        int p1,p2;
        for(int i=0;i<nEdges;++i){
            cin >> a >> b;
            p1 = mapping[a];
            p2 = mapping[b];
            paths[p1] |= (1<<p2);
            paths[p2] |= (1<<p1);
        }

        //do dp
        memset(memo,-1,sizeof(memo));
        while(!finPath.empty()){
            finPath.pop();
        }
        int possible {dp(0,(1<<(nNodes-1))-2)};

        cout << "Case " << tc << ": ";
        if(possible != 0){
            while(!finPath.empty()){
                cout << nodes[finPath.top()];
                finPath.pop();
            }
            cout << nodes[nNodes-1] << '\n';
        } else {
            printf("impossible\n");
        }
    }
}