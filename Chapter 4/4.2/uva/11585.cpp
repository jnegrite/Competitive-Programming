#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int grid[100][100] {};
char solution[100][101] {};
int rows, cols;
int row, col, val;
int dRow[4] {-1,0,1,0};
int dCol[4] {0,1,0,-1};

bool visited[100][100] {};

int fillEdge(int row, int col, char ch){
    if(row < 0 || row >= rows) return 0;
    if(col < 0 || col >= cols) return 0;
    if(visited[row][col] || solution[row][col] != ch) return 0;

    int ans {1};
    visited[row][col] = true;
    for(int i=0;i<4;++i){
        ans += fillEdge(row+dRow[i],col+dCol[i],ch);
    }
    return ans;
}

int fillAround(int row, int col, char ch){
    if(visited[row][col] || solution[row][col] != ch) return 0;

    visited[row][col] = true;
    int ans {1};
    for(int tRow = max(0,row-1);tRow<=min(rows-1,row+1);++tRow){
        for(int tCol = max(0,col-1);tCol<=min(cols-1,col+1);++tCol){
            ans += fillAround(tRow,tCol,ch);
        }
    }
    return ans;
}


int main(){
    int nCases;

    scanf("%d\n",&nCases);
    while(nCases--){
        int dPoints;
        memset(grid,-1,sizeof(grid));

        //get solution data
        scanf("%d %d %d\n",&rows,&cols,&dPoints);
        while(dPoints--){
            scanf("%d %d %d\n",&row,&col,&val);
            grid[row][col] = val;
        }

        //get solution
        for(int i=0;i<rows;++i){
            scanf("%s\n",&solution[i]);
        }
        
        bool solved {true};

        //check if all shades are connected
        memset(visited,false,sizeof(visited));
        int nAreas {0};
        for(int row=0;row<rows;++row){
            for(int col=0;col<cols;++col){
                if(!visited[row][col] && solution[row][col] == '#'){
                    nAreas++;
                    fillEdge(row,col,'#');
                }               
            }
        }
        if(nAreas > 1){
            solved = false;
        }

        //check numbered spaces
        if(solved){
            memset(visited,false,sizeof(visited));
            for(int row=0;solved && row<rows;++row){
                for(int col=0;solved && col<cols;++col){
                    if(grid[row][col] != -1){
                        if(grid[row][col] == 0){
                            solved = false;
                        } else {
                            int size {fillEdge(row,col,'.')};
                            if(size != grid[row][col]){
                                solved = false;
                            }
                        }
                    }
                }
            }

            if(solved){
                //check that all blank areas have been visited
                for(int row=0;solved && row<rows;++row){
                    for(int col=0;solved && col<cols;++col){
                        if(solution[row][col] == '.' && !visited[row][col]){
                            solved = false;
                        }
                    }
                }
            }
        }

        //make sure path to edge exists
        if(solved){
            //dfs from edges
            memset(visited,false,sizeof(visited));
            for(int row=0;row<rows;row+=(rows-1)){
                for(int col=0;col<cols;++col){
                    if(!visited[row][col] && solution[row][col] == '.'){
                        fillAround(row,col,'.');
                    }                
                }
            }

            for(int row=1;row<rows;row++){
                for(int col=0;col<cols;col+=(cols-1)){
                    if(!visited[row][col] && solution[row][col] == '.'){
                        fillAround(row,col,'.');
                    }                
                }
            }

            //check if no cell was left
            for(int row=0;solved && row<rows;++row){
                for(int col=0;solved && col<cols;++col){
                    if(solution[row][col] == '.' && !visited[row][col]){
                        solved = false;
                    }
                }
            }
        }

        if(solved){
            
            for(int row=1;solved && row<rows;++row){
                bool filled[100] {};
                for(int col=0;col<cols;++col){
                    if(solution[row][col] == '#' && solution[row-1][col] == '#'){
                        filled[col] = true;
                    }
                }

                for(int col=1;solved && col<cols;++col){
                    if(filled[col-1] && filled[col]){
                        solved = false;
                    }
                }
            }
        }

        if(solved){
            printf("solved\n");
        } else {
            printf("not solved\n");
        }

    }
}