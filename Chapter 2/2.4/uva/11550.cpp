#include<iostream>
#include<vector>
#include<malloc.h>
#include<unordered_set>

using namespace std;

int main(){
    int numCases;
    cin >> numCases;
    int curr;
    while(numCases--){
        bool isOk {true};
        int rows, cols;

        cin >> rows >> cols;
        vector<vector<int>> nodes {};
        for(int col=0;col<cols;col++){
            nodes.push_back(vector<int> {});
        }
        
        
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                cin >> curr;
                if(curr==1){
                    nodes[col].push_back(row);
                }
            }
        }
        
        vector<unordered_set<int>> pairedNodes {};
        for(int row=0;row<rows;row++){
            pairedNodes.push_back(unordered_set<int> {});
        }

        for(int col=0;col<cols;col++){
            if(nodes[col].size() != 2){
                isOk = false;
                break;
            } else {
                int p1 {nodes[col][0]};
                int p2 {nodes[col][1]};

                if(pairedNodes[p1].count(p2) != 0){
                    isOk = false;
                    break;
                } else {
                    pairedNodes[p1].emplace(p2);
                    pairedNodes[p2].emplace(p1);
                }
            }
        }

        cout << (isOk?"Yes":"No") << '\n';
    }
}