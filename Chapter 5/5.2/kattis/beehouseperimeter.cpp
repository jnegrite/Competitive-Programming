#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int gridSize;
int maxIdx;
int memo[102][102] {};

vector<int> markers {};

void generateMarkers(int sideLength){
    int basis {1};
    int nxtBorder {sideLength << 1};
    markers.clear();
    markers.push_back(1);

    for(int i=sideLength;i<nxtBorder;i++){
        basis+=i;
        markers.push_back(basis);
    }

    for(int i=nxtBorder-2;i>sideLength;i--){
        basis+=i;
        markers.push_back(basis);
    }
}

void encode(int val){
    auto it {lower_bound(markers.begin(),markers.end(),val)};
    int row, col;

    if((it == markers.end()) || (*it > val)){
        --it;
    }

    row = 1 + (it-markers.begin());
    col = 1 + (val - *it);
    if(row > gridSize){
        col += (row-gridSize);
    }

    //cout << val << ": " << row << "," << col << "\n";
    memo[row][col] = 1;
}

int main(){
    int nPoints, val;
    cin >> gridSize >> nPoints;
    
    maxIdx = ((1+gridSize)<<1);

    generateMarkers(gridSize);
    while(nPoints--){
        cin >> val;
        encode(val);
    }

    queue<pair<int,int>> q {};

    memo[0][0] = -1;
    q.emplace(0,0);

    int ans {0};
    int rNext, cNext;

    while(!q.empty()){
        pair<int,int> curr {q.front()};
        q.pop();

        //evaluate around this
        for(int dr=-1;dr<=1;++dr){
            for(int dc=-1;dc<=1;++dc){
                if((dr==0 && dc==0) || (dr*dc == -1)) continue;

                rNext = curr.first + dr;
                cNext = curr.second + dc;

                if(rNext < 0 || rNext >= maxIdx) continue;
                if(cNext < 0 || cNext >= maxIdx) continue;            
                
                switch(memo[rNext][cNext]){
                    case 0:
                        q.emplace(rNext,cNext);
                        memo[rNext][cNext] = -1;
                        break;
                    case 1:
                        ++ans;
                        break;
                }
            }
        }
    }

    cout << ans << '\n';
}