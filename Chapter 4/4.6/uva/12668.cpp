#include<iostream>
#include<cstring>
#include<vector>
#include<set>

using namespace std;


vector<bool> visited {};
vector<int> match {};
vector<set<int>> paths {};
int gridSize;
int code[100][100] {};
int nRows, nCols;
string s;

int aug(int L){
    if(visited[L]) return 0;

    visited[L] = true;
    for(auto it {paths[L].begin()};it!=paths[L].end();++it){
        int nxt {*it};

        if((match[nxt]==-1) || aug(match[nxt])){
            match[nxt] = L;
            return 1;
        }
    }
    return 0;
}


int main(){ 
    while(cin >> gridSize){
        memset(code,-1,sizeof(code));
        nRows = nCols = 0;

        //mark pawns
        for(int row=0;row<gridSize;++row){
            cin >> s;
            for(int col=0;col<gridSize;++col){
                if(s.at(col) == 'X') {
                    code[row][col] = -2;
                }
            }
        }

        //mark areas
        bool isUsed {false};
        for(int row=0;row<gridSize;++row){
            for(int col=0;col<gridSize;++col){
                if(code[row][col] == -2){
                    if(isUsed){
                        ++nRows;
                        isUsed = false;
                    }
                } else {
                    code[row][col] = nRows;
                    isUsed = true;
                }
            }

            if(isUsed){
                ++nRows;
                isUsed = false;
            }
        }

        paths.assign(nRows, {});

        isUsed = false;
        for(int col=0;col<gridSize;++col){
            for(int row=0;row<gridSize;++row){
                if(code[row][col] == -2){
                    if(isUsed){
                        ++nCols;
                        isUsed = false;
                    }
                } else {
                    paths[code[row][col]].emplace(nCols);
                    isUsed = true;
                }
            }

            if(isUsed){
                ++nCols;
                isUsed = false;
            }
        }

        match.assign(nCols, -1);

        int ans {};
        for(int i=0;i<nRows;++i){
            visited.assign(nRows,false);
            ans += aug(i);
        }
        cout << ans << '\n';
    }
}