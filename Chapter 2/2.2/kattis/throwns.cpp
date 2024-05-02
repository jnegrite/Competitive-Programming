#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    stack<int> positions {};
    int n, k;
    string s;
    long throwDist;
    positions.emplace(0);
    cin >> n >> k;
    for(int i=0;i<k;i++){
        cin >> s;
        if(s=="undo"){
            cin >> s;
            throwDist = stol(s);
            while(throwDist-- > 0){
                positions.pop();
            }
        } else {
            throwDist = stol(s);
            if(throwDist >= 0){
                throwDist %= n;
            } else {
                throwDist = ((-throwDist)%n);
                throwDist = n-throwDist;
            }
            positions.emplace((positions.top() + throwDist)%n);
        }
    }

    cout << positions.top() << '\n';

}