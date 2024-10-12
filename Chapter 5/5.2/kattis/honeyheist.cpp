#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int gridSize, chewMax, src, dest, nBlocked;

int memo[42][42] {};

vector<pair<int,int>> moves {
    {-1,0},
    {1,1},
    {0,1},
    {1,0},
    {-1,-1},
    {0,-1},
};

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

pair<int,int> encode(int val){
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

    return {row,col};
}

void makeMark(pair<int,int> &pr, int val){
    memo[pr.first][pr.second] = val;
}

void makeMark(int markVal, int val){
    auto pr {encode(markVal)};
    makeMark(pr, val);
}

int main(){
    cin >> gridSize >> chewMax >> src >> dest >> nBlocked;
    
    //reset grid
    generateMarkers(gridSize);
    memset(memo, -2, sizeof(memo));
    for(int row=1, width=gridSize; row<=gridSize; ++row, ++width){
        for(int col=1;col<=width;++col){
            memo[row][col] = -1;
        }
    }
    int lastIdx {gridSize<<1};
    for(int row=gridSize+1,colStart=2;colStart<=gridSize;++row,++colStart){
        for(int col=colStart;col<lastIdx;++col){
            memo[row][col] = -1;
        }
    }

    //mark blocked cells
    int val;
    while(nBlocked--){
        cin >> val;
        makeMark(val,-2);
    }
    
    int ans {-1};
    queue<pair<int,int>> q {};
    auto pr {encode(src)};

    q.emplace(pr.first,pr.second);
    makeMark(pr,0);

    pr = encode(dest);
    makeMark(pr, -3);
    
    //do BFS
    int tempRow, tempCol, nxtDist;
    while(ans == -1 && !q.empty()){
        pair<int,int> &curr {q.front()};
        nxtDist = memo[curr.first][curr.second]+1;
        q.pop();

        for(pair<int,int> &pr:moves){
            tempRow=curr.first + pr.first;
            tempCol=curr.second + pr.second;

            if(tempRow <= 0 || tempRow > lastIdx ||
                tempCol <= 0 || tempCol >= lastIdx) continue;
            
            auto &target {memo[tempRow][tempCol]};
            if(target == -3){
                ans = nxtDist;
                break;
            } else if ((target == -1) && (nxtDist < chewMax)){
                target=nxtDist;
                q.emplace(tempRow,tempCol);
            }
        }
    }

    if(ans == -1){
        cout << "No\n";
    } else {
        cout << ans << '\n';
    }
}