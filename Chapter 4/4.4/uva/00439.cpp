#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int dRow[8] {-2,-2,-1,-1,1,1,2,2};
int dCol[8] {-1,1,-2,2,-2,2,-1,1};

bool inGrid(int row, int col){
    return row>=0 && row<8 && col>=0 && col<8;
}

int bfs(string from, string to){
    int rFrom {from.at(0)-'a'};
    int cFrom {from.at(1)-'1'};

    int rTo {to.at(0)-'a'};
    int cTo {to.at(1)-'1'};

    bool visited[8][8] {};

    if(from==to){
        return 0;
    }

    queue<tuple<int,int,int>> q {};
    q.emplace(rFrom,cFrom,0);
    visited[rFrom][cFrom] = true;

    int ans {-1};
    while(!q.empty() && ans==-1){
        auto t {q.front()};
        q.pop();

        int row {get<0>(t)};
        int col {get<1>(t)};
        int dist {get<2>(t)};

        for(int i=0;i<8;i++){
            int tRow {row+dRow[i]};
            int tCol {col+dCol[i]};

            if(!inGrid(tRow,tCol) || visited[tRow][tCol]) continue;

            if(rTo==tRow && cTo==tCol){
                ans=dist+1;
                break;
            }

            visited[tRow][tCol] = true;
            q.emplace(tRow,tCol,dist+1);
        }

    }    
    return ans;
}


int main(){
    string s1, s2;
    while(cin >> s1 >> s2){
        int ans {bfs(s1,s2)};
        cout << "To get from " << s1 << " to " << s2 << " takes " << ans << " knight moves.\n";
    }    
}