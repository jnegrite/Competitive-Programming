#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q {};
    int nValues;
    int curr;
    while(cin >> nValues, nValues != 0){
        while(nValues--){
            cin >> curr;
            if(curr != 0){
                q.emplace(curr);
            }
        }

        if(q.empty()){
            cout << "0\n";
        } else {
            cout << q.front();
            q.pop();
            while(!q.empty()){
                cout << ' ' << q.front();
                q.pop();
            }
            cout << '\n';
        }
    }
}