#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int nFloors, holesPerFloor;

int curr[15] {};
int nxt[15] {};

int main(){
    string caseName;

    while(cin >> caseName){
        cin >> nFloors >> holesPerFloor;
        memset(curr,0,sizeof(curr));
        memset(nxt,-1,sizeof(nxt));
        int val;
        for(int floor=1;floor<nFloors;floor++){
            for(int i=0;i<holesPerFloor;i++){
                for(int j=0;j<holesPerFloor;j++){
                    cin >> val;
                    int tmp = curr[i] + val;
                    if(nxt[j] == -1 || (tmp < nxt[j]) ){
                        nxt[j] = tmp;
                    }
                }
            }
            
            swap(curr,nxt);
            memset(nxt,-1,sizeof(nxt));
        }

        int minVal {curr[0]};
        for(int i=1;i<holesPerFloor;i++){
            minVal = min(minVal, curr[i]);
        }
        cout << caseName << '\n';
        cout << (2 * (nFloors-1) + minVal) << '\n';
    }
}