#include<iostream>

using namespace std;

int main(){
    int nCases;
    cin >> nCases;

    for(int tc=1;tc<=nCases;++tc){
        int gridSize;
        int lastIdx;
        int cnt[101] {};
        
        cin >> gridSize;
        lastIdx = gridSize * gridSize;

        bool isOk {true};
        int val;
        for(int i=0;i<lastIdx;++i){
            cin >> val;
            if((++cnt[val]) > gridSize){
                isOk = false;
            }
        }

        cout << "Case " << tc << ": " << (isOk?"yes":"no") << '\n';
    }
}