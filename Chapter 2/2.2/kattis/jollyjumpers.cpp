#include<iostream>
#include<sstream>
#include<cmath>

using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        auto strIn {stringstream(s)};
        bool isUsed[3000] {};
        bool isOk {true};
        int nValues{};
        long prev {};
        long curr {};
        long diff {};

        strIn >> nValues;

        if(nValues == 0){
            cout << "Not jolly\n";
        }
        strIn >> prev;

        for(int i=1;isOk && i<nValues;i++){
            strIn >> curr;
            diff = abs(curr-prev);
            if(diff < 0 || diff >= nValues || isUsed[diff]){
                isOk = false;
            }
            isUsed[diff] = true;
            prev = curr;
        }

        cout << (isOk?"Jolly":"Not jolly") << '\n';
    }
}