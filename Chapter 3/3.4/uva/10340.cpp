#include<iostream>
#include<string>

using namespace std;

int main(){
    string s, t;
    unsigned long long prev;
    while(cin >> s >> t){
        prev = -1;
        bool isOk {true};
        for(char ch:s){
            ++prev;
            if(prev==t.length()){
                isOk = false;
                break;
            }
            prev = t.find_first_of(ch,prev);
            if(prev == -1){
                isOk = false;
                break;
            }
        }
        cout << (isOk?"Yes":"No") << '\n';
    }
}