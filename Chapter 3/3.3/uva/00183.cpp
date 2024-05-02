#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

long rows;
long cols;
string opCode;
string code;
int grid[200][200] {};

struct Area {
    int rFrom{};
    int rTo{};
    int cFrom{};
    int cTo{};

    Area(int _rFrom, int _rTo, int _cFrom, int _cTo){
        rFrom = _rFrom;
        rTo = _rTo;
        cFrom = _cFrom;
        cTo = _cTo;
    }

    vector<Area> getSegments(){
        int mRow {(rFrom + rTo)>>1};
        int mCol {(cFrom + cTo)>>1};

        vector<Area> ans {};
        ans.push_back(Area{rFrom, mRow,cFrom,mCol});
        
        if(mCol != cTo){
            ans.push_back(Area{rFrom, mRow, mCol+1,cTo});
        }
        if(mRow != rTo){
            ans.push_back(Area{mRow+1,rTo, cFrom, mCol});

            if(mCol != cTo){
                ans.push_back(Area{mRow+1,rTo, mCol+1, cTo});
            }
        }
        return ans;
    }

    void propagate(){
        char ch;
        cin >> ch;
        int val;
        switch(ch){
            case '0': case '1':
                val = ch - '0';
                for(int row=rFrom;row<=rTo;row++){
                    for(int col=cFrom;col<=cTo;col++){
                        grid[row][col] = val;
                    }
                }
                
                break;
            case 'D':
                for(auto subArea: getSegments()){
                    subArea.propagate();
                }
        }
    }

    string getRepr(){
        bool isOk {true};
        string repr {};
        int baseVal {grid[rFrom][cFrom]};
        for(int row=rFrom;isOk && row<=rTo;row++){
            auto currRow {grid[row]};
            for(int col=cFrom;isOk && col<=cTo;col++){
                if(currRow[col] != baseVal){
                    isOk = false;
                }
            }
        }

        if(isOk){
            return to_string(baseVal);
        } else {
            repr = "D";
            for(auto au: getSegments()){
                repr += au.getRepr();
            }
            return repr;
        }
    }
};

int main(){
    while(cin >> opCode,opCode!="#"){
        cin >> rows >> cols;
        Area area {0,rows-1,0,cols-1};
        if(opCode=="B"){
            code = "";
            string temp;
            while(code.length() < rows*cols){
                cin >> temp;
                code += temp;
            }
            for(int row=0;row<rows;row++){
                int base {row * cols};
                for(int col=0;col<cols;col++){
                    grid[row][col] = code.at(base + col) - '0';
                }
            }
            cout << 'D' << right << setw(4) << rows << right << setw(4) << cols << '\n';
            string repr {area.getRepr()};
            for(long i=0;i<repr.length();i+=50){
                cout << repr.substr(i,min(50L,static_cast<long>(repr.length())-i)) << '\n'; 
            }
        } else {
            area.propagate();
            cout << 'B'<< right << setw(4) << rows << right << setw(4) << cols << '\n';
            for(int row=0;row<rows;row++){
                for(int col=0;col<cols;col++){
                    cout << grid[row][col];
                    if(((row*cols)+col)%50==49 || (row==rows-1 && col==cols-1)){
                        cout << '\n';
                    }
                }
            }
        }
    }
}