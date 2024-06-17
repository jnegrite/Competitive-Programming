#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>

using namespace std;
using ii = pair<int,int>;

int dist[20][60] {};
int strength[20][60] {};
int parent[20][60][2] {};

int rows, cols;
string s;
int endCol;

int main(){
    while(cin >> rows >> cols,rows!=0 && cols!=0){
        memset(dist,-1,sizeof(dist));

        //get data
        for(int i=0;i<rows;i++){
            cin >> s;
            for(int j=0;j<cols;j++){
                strength[i][j] = s.at(j)-'0';
            }
        }

        priority_queue<tuple<int,int,int,int,int>> q {};

        //initialize seed
        for(int j=0;j<cols;j++){
            q.emplace(-strength[0][j],0,j,-1,-1);
        }

        //do dijkstra
        while(!q.empty()){
            int currDist {-get<0>(q.top())};
            ii currNode {get<1>(q.top()),get<2>(q.top())};
            ii parentNode {get<3>(q.top()),get<4>(q.top())};
            q.pop();

            if(dist[currNode.first][currNode.second] != -1) continue;

            dist[currNode.first][currNode.second] = currDist;
            auto &cParent {parent[currNode.first][currNode.second]};
            cParent[0] = parentNode.first;
            cParent[1] = parentNode.second;

            if(currNode.first == rows-1){
                endCol = currNode.second;
                break;
            }

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int tRow {currNode.first+i};
                    int tCol {currNode.second+j};

                    if(tRow<0 || tRow>=rows || tCol<0 || tCol>=cols || dist[tRow][tCol] != -1) continue;

                    q.emplace(-(currDist + strength[tRow][tCol]),tRow,tCol,currNode.first,currNode.second);
                }
            }
        }

        //trace back
        int row, col, pRow, pCol;
        row = rows-1;
        col = endCol;

        while(row!=-1){
            pRow = parent[row][col][0];
            pCol = parent[row][col][1];

            strength[row][col] = -1;
            row = pRow;
            col = pCol; 
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int val {strength[i][j]};
                if(val == -1){
                    cout << ' ';
                } else {
                    cout << val;
                }
            }
            cout << '\n';
        }
        cout << '\n';
    }
}