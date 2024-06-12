#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

class Gate {
private:
    int dest {};
    int t0 {};
    int interval {};
    int traversal {};

public:
    Gate(int _dest, int _t0, int _interval,int _traversal){
        dest = _dest;
        t0 = _t0;
        interval = _interval;
        traversal = _traversal;
    }

    int getDest(){
        return dest;
    }

    int traverse(int t){
        if(t<=t0){
            return t0 + traversal;
        }

        if(interval==0){
            return -1;
        }

        int reps {(t-t0)/interval};
        if((t-t0)%interval != 0){
            reps++;
        }

        return t0 + reps*interval + traversal;
    }
};

vector<vector<Gate>> paths {};
vector<int> dist {};
int nNodes, nEdges, nQueries, source;

int main(){
    while(true){
        cin >> nNodes >> nEdges >> nQueries >> source;

        if(nNodes == 0 && nEdges == 0 && nQueries == 0 && source == 0) break;

        paths.assign(nNodes, {});
        dist.assign(nNodes,-1);

        //get edges
        int  a, b, t0, interval, traversal;
        while(nEdges--){
            cin >> a >> b >> t0 >> interval >> traversal;
            paths[a].emplace_back(b,t0,interval,traversal);
        }

        //do dijkstra
        priority_queue<tuple<int,int>> q {};
        
        q.emplace(0,source);

        while(!q.empty()){
            int currDist {-get<0>(q.top())};
            int currNode {get<1>(q.top())};
            q.pop();

            if(dist[currNode] != -1) continue;
            dist[currNode] = currDist;

            for(Gate &nxt: paths[currNode]){
                if(dist[nxt.getDest()] != -1) continue;

                int finTime {nxt.traverse(currDist)};

                if(finTime != -1){
                    q.emplace(-finTime,nxt.getDest());
                }
            }
        }

        //answer the queries
        while(nQueries--){
            cin >> a;
            if(dist[a] == -1){
                cout << "Impossible\n";
            } else {
                cout << dist[a] << '\n';
            }
        }
    }
}