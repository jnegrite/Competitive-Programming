#include<iostream>
#include<queue>

using namespace std;
int N;

bool isValid(int m){
    //populate
    queue<int> q {};
    for(int i=1;i<=N;i++){
        q.emplace(i);
    }

    int curr;
    for(int i=1;i<N;i++){
        curr = q.front();
        q.pop();
        if(curr == 13){
            return false; 
        }

        for(int j=1;j<m;j++){
            q.emplace(q.front());
            q.pop();
        }
    }

    return true;
}

int main(){
    while(cin >> N, N!=0){
        int ans {0};
        while(true){
            if(isValid(++ans)){
                break;
            }
        }
        cout << ans << '\n';
    }
}
