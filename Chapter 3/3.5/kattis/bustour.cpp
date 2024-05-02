#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>

#define INF 1000000000
#define LSOne(x) ((x) & -(x))

using namespace std;

using ii = pair<int,int>;

int dist[20][20]{};
int N;

struct cmpPair{
    bool operator()(const ii &a, const ii &b) const {
        return a.second > b.second;
    }
};

void dijkstra(int src){
    bool isVisited[20] {};
    priority_queue<ii,vector<ii>,cmpPair> q {};
    q.push({src,0});
    while(!q.empty()){
        ii curr {q.top()};
        q.pop();
        
        if(isVisited[curr.first]){
            continue;
        }
        isVisited[curr.first] = true;

        if(dist[src][curr.first] == 0 || dist[src][curr.first] >= curr.second){
            dist[src][curr.first] = dist[curr.first][src] = curr.second;
            for(int i=0;i<N;i++){
                if(!isVisited[i] && dist[curr.first][i] != 0){
                    q.push({i,curr.second + dist[curr.first][i]});
                }
            }
        }
    }
}

long long memo[20][1<<21] {};
long long memoRev[20][1<<21] {};

long long dp(int pos, int mask, int fin){
    if(mask==0){
        return dist[pos][fin];
    }

    auto &curr {fin == 0 ? memoRev[pos][mask] : memo[pos][mask]};

    if(curr != -1){
        return curr;
    }

    curr = INF;
    int tMask {mask};
    while(tMask != 0){
        int flag {LSOne(tMask)};
        int target {__builtin_ctz(flag)};
        curr = min(curr, dist[pos][target] + dp(target, mask ^ flag, fin));
        tMask -= flag;
    }
    return curr;
}

long long dpFwd(int pos, int mask){
    return dp(pos,mask,N-1);
}

long long dpRev(int pos, int mask){
    return dp(pos,mask,0);
}


int main(){
    int nNodes;
    int tc {};
    while(scanf("%d %d\n",&N,&nNodes)!=EOF){
        memset(dist,0,sizeof(dist));
        memset(memo,-1,sizeof(memo));
        memset(memoRev,-1,sizeof(memoRev));

        int a, b, c;
        for(int i=0;i<nNodes;++i){
            scanf("%d %d %d\n",&a,&b,&c);
            dist[a][b] = dist[b][a] = c;
        }

        //complete all nodes
        for(int i=0;i<N;++i){
            dijkstra(i);
        }

        //base case when 3
        if(N==3){
            printf("Case %d: %lld\n",++tc,2*(dist[0][1] + dist[1][2]));
            continue;
        }

        //do the TSP
        vector<int> perm {};
        perm.assign(N-2,0);
        int nHalf {N/2 - 1};
        for(int i=1;i<=nHalf;i++){
            perm[perm.size()-i] = 1;
        }

        int window {(1<<(N-1))-2};

        long long overallBest {INF};
        do {
            int mask {};
            for(int i=1;i<=perm.size();++i){
                if(perm[i-1] == 1){
                    mask |= (1<<i);
                }
            }

            int coMask {(~mask) & window};

            long long bestForward {INF};
            long long bestBackward {INF};

            int tMask{mask};
            while(tMask != 0){
                int flag {LSOne(tMask)};
                int target {__builtin_ctz(flag)};

                long long tempForward {dpFwd(target,coMask) + dpRev(target,mask ^ flag)};
                long long tempBackward {dpFwd(target,mask ^ flag) + dpRev(target,coMask)};

                bestForward = min(bestForward,tempForward);
                bestBackward = min(bestBackward,tempBackward);
                tMask -= flag;
            }
            overallBest = min(overallBest,bestForward+bestBackward);
        } while(next_permutation(perm.begin(),perm.end()));

        printf("Case %d: %lld\n",++tc,overallBest);
    }
}