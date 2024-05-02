#include<iostream>
#include<vector>
#include<malloc.h>

using namespace std;

vector<vector<int>> neighbors {
    {1,3},
    {0,2,4},
    {1,5},
    {0,4,6},
    {1,3,5,7},
    {2,4,8},
    {3,7},
    {4,6,8},
    {5,7}
};

int main(){
    int *mainGrid;
    long numCases;
    string s;

    mainGrid = (int*)malloc(9*sizeof(int));
    
    cin >> numCases;
    for(long tc=0;tc<numCases;tc++){
        for(int i=0;i<9;i+=3){
            cin >> s;
            for(int j=0;j<3;j++){
                mainGrid[i+j] = s.at(j) - '0';
            }
        }

        int numIterations {0};

        while(true){
            bool isEmpty {true};
            for(int i=0;isEmpty && i<9;i++){
                if(mainGrid[i] == 1){
                    isEmpty = false;
                }
            }

            if(isEmpty){
                break;
            }

            //apply function
            int *holderGrid;
            holderGrid = (int*)malloc(9*sizeof(int));
            numIterations++;

            for(int i=0;i<9;i++){
                holderGrid[i] = 0;
                for(auto n:neighbors[i]){
                    holderGrid[i] += mainGrid[n];
                }
                holderGrid[i] &= 1;
            }

            free(mainGrid);
            mainGrid = holderGrid;
        }

        cout << numIterations-1 << '\n';
    }
}