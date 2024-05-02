#include<iostream>
#include<queue>
#include<malloc.h>
#include<vector>

using namespace std;

vector<string> d;
vector<queue<long>> q {};

void print(long id){
    cout << d[id];
    while(!q[id].empty()){
        long curr = q[id].front();
        q[id].pop();
        print(curr);
    }
}

int main(){
    long n;
    cin >> n;
    string s;
    
    d.reserve(n+1);
    q.reserve(n+1);
    d.push_back("");
    queue<long> temp {};
    q.push_back(temp);

    //get data
    for(long i=0;i<n;i++){
        cin >> s;
        d.push_back(s);
        queue<long> temp {};
        q.push_back(temp);
    }
    
    int firstId {1};

    long a, b;
    for(long i=1;i<n;i++){
        cin >> a >> b;
        q[a].emplace(b);
        firstId = a;
    }

    print(firstId);
}