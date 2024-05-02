#include<iostream>
#include<vector>

using namespace std;

vector<int> decompose(int len){
    int rows {1};
    int cols {len};
    int testNum {2};
    vector<int> output {};

    while(true){
        if(len % testNum == 0){
            int testCols = len/testNum;
            if(testCols < testNum){
                break;
            } else {
                rows = testNum;
                cols = testCols;
            }
        }
        testNum++;
    }

    output.push_back(rows);
    output.push_back(cols);

    return output;
}


int main(){
    string message;
    
    cin >> message;

    vector<int> dims {decompose(message.length())};

    if(dims[0] == 1){
        cout << message << '\n';
    } else {
        char data[100][100] {};
        
        int pos{};
        for(int col=0;col<dims[1];col++){
            for(int row=0;row<dims[0];row++){
                data[row][col] = message.at(pos++);
            }
        }

        for(int row=0;row<dims[0];row++){
            for(int col=0;col<dims[1];col++){
                cout << data[row][col];
            }
        }

        
    }

}