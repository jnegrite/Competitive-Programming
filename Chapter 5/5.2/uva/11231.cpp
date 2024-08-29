#include<iostream>

using namespace std;

int main(){
    int nRows, nCols, usableRows, usableCols, flag;

    while(cin >> nRows >> nCols >> flag, nRows != 0 || nCols != 0 || flag != 0){
        usableRows = nRows - 7;
        usableCols = nCols - 7;

        //compute for original first
        long long ans {};
        if((usableCols%2)==0){
            ans = usableRows * (usableCols>>1);
        } else {
            long long evenRows = ((usableCols+1)>>1) * ((usableRows+1)>>1);
            long long oddRows = (usableCols>>1) * (usableRows>>1);
            ans = evenRows + oddRows;
        }

        if(flag == 0){
            ans = usableRows * usableCols - ans;
        }
        
        cout << ans << '\n';
    }
}