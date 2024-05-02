#include<iostream>
#include<string>
#include<stack>
#include<sstream>

using namespace std;

int main(){
    string s;   
    while(getline(cin,s)){
        auto strIn {stringstream(s)};
        stack<long> pieces {};
        stack<long> sums {};
        long curr;
        bool isOk {true};
        sums.emplace(0);
        while(strIn >> curr){
            if(curr < 0){
                pieces.emplace(curr);
                sums.emplace(0);
            } else {
                if(pieces.empty() || (pieces.top() + curr !=0) || (sums.top() >= curr)){
                    isOk = false;
                    break;
                } else {
                    pieces.pop();
                    sums.pop();
                    sums.top() += curr;
                }
            }
            if(!isOk){
                break;
            }
        }

        if(isOk && pieces.empty()){
            cout << ":-) Matrioshka!\n";
        } else {
            cout << ":-( Try again.\n";
        }
    }
}