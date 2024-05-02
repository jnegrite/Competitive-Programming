#include<iostream>
#include<string>
#include<sstream>

using namespace std;
string grid[100] {};

int m, n, q, r, c;

int rFrom, rTo, cFrom, cTo;

bool isValid(){
    if(rFrom <0 || rTo >= m || cFrom<0 || cTo >= n){
        return false;
    }

    char basis {grid[r].at(c)};

    //main rows
    for(int row=rFrom;row<=rTo;row++){
        for(int col=cFrom;col<=cTo;){
            
            if(grid[row].at(col) != basis){
                return false;
            }

            if(row==rFrom || row==rTo){
                ++col;
            } else {
                col = max(cTo,col+1);
            }
        }
    }
    return true;

}
int main(){
    string s;
    int nCases;
    getline(cin,s);
    nCases = stoi(s);

    while(nCases--){
        getline(cin,s);

        auto strIn {stringstream(s)};
        strIn >> m >> n >> q;

        cout << m << ' ' << n << ' ' << q <<'\n';
        for(int i=0;i<m;i++){
            getline(cin,grid[i]);
        }

        //perform queries
        while(q--){
            getline(cin,s);
            auto strIn {stringstream(s)};
            strIn >> r >> c;

            rFrom = r-1;
            rTo = r+1;
            cFrom = c-1;
            cTo = c+1;

            int ans {};
            if(r < 0 || r >= m || c < 0 || c >= n){
                ans = 1;
            } else {
                while(isValid()){
                    rFrom--;
                    rTo++;
                    cFrom--;
                    cTo++;
                }

                ans = 2*(r-rFrom) - 1;
            }
            cout << ans << '\n';
        }
    }
}