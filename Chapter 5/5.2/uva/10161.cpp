#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    int val;
    int baseIdx;
    int row, col;

    while(cin >> val, val > 0){
        baseIdx = static_cast<int>(sqrt(val));
        long long rem {val - baseIdx*baseIdx};
        if(rem==0){
            row = baseIdx;
            col = 1;

            if((baseIdx%2)==1){
                swap(row,col);
            }
        } else {
            baseIdx++;
            
            if(rem <= baseIdx){
                row = rem;
                col = baseIdx;
            } else {
                col = (baseIdx<<1) - rem;
                row = baseIdx;
            }

            if(baseIdx%2){
                swap(row,col);
            }
        }

        cout << row << ' ' << col << '\n';
    }
}
