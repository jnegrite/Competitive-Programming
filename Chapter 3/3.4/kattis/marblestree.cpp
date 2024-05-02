#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<vector<long>> children {};
vector<long> netDiff {};
unordered_set<long> root {};
long totalMoves {};

void resolve(long pos){
    //resolve children first

    auto &chill  {children[pos]};
    for(long c: chill){
        resolve(c);
        netDiff[pos] += netDiff[c];    
    }
    totalMoves += abs(netDiff[pos]);
}

int main(){
    int nVertices {};
    long idx, nMarbles, curr;
    while(cin >> nVertices, nVertices != 0){
        ++nVertices;
        root.clear();

        children.assign(nVertices,{});
        netDiff.assign(nVertices,0);
        for(long i=1;i<nVertices;++i){
            root.emplace(i);
        }
        
        //get details per vertex
        for(long i=1;i<nVertices;++i){
            long nChildren;
            cin >> idx >> netDiff[i] >> nChildren;
            --netDiff[i];

            auto &chill {children[i]};
            while(nChildren--){
                cin >> curr;
                root.erase(curr);
                chill.push_back(curr);
            }
        }

        int rootVertex {*root.begin()};
        totalMoves = 0;
        resolve(rootVertex);
        cout << totalMoves << '\n';
    }
}