#include<iostream>
#include<queue>

using namespace std;

int main(){
    string s;
    long d, n;
    while(cin >> n >> d, d!=0 && n!=0){
        cin >> s;
        
        deque<char> chars {};
        for(char ch: s){
            while(!chars.empty() && d > 0 && ch > chars.back()){
                chars.pop_back();
                --d;
            }
            chars.push_back(ch);
        }

        while(d--){
            chars.pop_back();
        }

        while(!chars.empty()){
            cout << chars.front();
            chars.pop_front();
        }
        cout << '\n';

    }
}