#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<tuple>
#include<string>
#include<algorithm>

using namespace std;
int row, col;
char code[3] {};
vector<tuple<int,int>> ans {};
int dist[8][8] {};
int maxDist {0};

vector<pair<int,int>> paths {
    {-2,-1},
    {-2,1},
    {-1,-2},
    {-1,2},
    {1,-2},
    {1,2},
    {2,-1},
    {2,1},
};

string stringify(int row, int col){
    string output {};
    output += static_cast<char>('a' + row);
    output += to_string(1+col);
    return output;
}

bool inGrid(int row, int col){
    return row>=0 && row<8 && col>=0 && col<8;
}

void bfs(){
    int row {code[0]-'a'};
    int col {code[1]-'1'};
    
    memset(dist,-1,sizeof(dist));

    queue<pair<int,int>> q {};
    q.emplace(row,col);
    dist[row][col] = 0;

    maxDist=0;
    while(!q.empty()){
        row = {q.front().first};
        col = {q.front().second};
        q.pop();

        if(dist[row][col] > maxDist){
            maxDist = dist[row][col];
            ans.clear();
        }

        ans.emplace_back(-col,row);

        for(auto nxt:paths){
            int tRow {row+nxt.first};
            int tCol {col+nxt.second};

            if(!inGrid(tRow,tCol) || dist[tRow][tCol] != -1) continue;

            q.emplace(tRow,tCol);
            dist[tRow][tCol] = dist[row][col]+1;
        }
    }
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);

    while(nCases--){
        scanf("%s\n",&code);
        ans.clear();
        bfs();
        sort(ans.begin(),ans.end());
        printf("%d",maxDist);
        for(auto point:ans){
            printf(" %s",stringify(get<1>(point),-get<0>(point)).c_str());
        }
        printf("\n");
    }
}