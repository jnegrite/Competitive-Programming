#include<iostream>
#include<vector>

#define LSOne(x) ((x) & -(x))

using namespace std;

int nPoints{};

vector<vector<int>> paths {};
vector<bool> visited {};
vector<int> depth {};
int parent[200001][18] {};

long long ans {-1};

void dfs(int pos, int currDepth, int currParent){
    depth[pos] = currDepth;
    parent[pos][0] = currParent;

    //save next parents

    int idxCurr {1};
    int idxPrev {0};
    int flagCurr {1<<idxCurr};
    int flagPrev {1<<idxPrev};

    while(flagCurr <= currDepth){
        parent[pos][idxCurr] = parent[ parent[pos][idxPrev] ][idxPrev];

        idxPrev = idxCurr++;
        flagPrev = flagCurr;
        flagCurr<<=1;
    }

    ans += 1 + currDepth;
    for(int nxt: paths[pos]){
        if(nxt == currParent) continue;
        dfs(nxt, currDepth+1,pos);
    }
}

int getKthParent(int pos, int k){
    while(k > 0){
        int flag = LSOne(k);
        int ctr = __builtin_ctz(flag);

        pos = parent[pos][ctr];
        k -= flag;
    }
    return pos;
}

int findLCADepth(int a, int b){
    int low {0};
    int dA {depth[a]};
    int dB {depth[b]};
    int high {min(dA,dB)};

    int d1, d2;
    int v1, v2;
    while(low < high){
        int mid {(low+high+1)>>1};

        d1 = dA - mid;
        d2 = dB - mid;

        if(getKthParent(a,d1) == getKthParent(b,d2)){
            low = mid;
        } else {
            high = mid-1;
        }
    }
    return low;
}

int main(){
    cin >> nPoints;

    int a, b;
    paths.assign(nPoints+1,{});
    depth.assign(nPoints+1,-1);

    for(int i=1;i<nPoints;++i){
        cin >> a >> b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }

    dfs(1,0,-1);

    int lastIdx {nPoints<<1};
    for(int i=2;i<=lastIdx;++i){
        for(int j=(i<<1);j<=nPoints;j+=i){
            int lca = findLCADepth(i,j);
            int dist {depth[i] + depth[j] - (lca<<1) + 1};
            ans += dist;
        }
    }
    cout << ans << '\n';
}