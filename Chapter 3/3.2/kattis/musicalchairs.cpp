#include<iostream>
#include<queue>

using namespace std;

int main(){
    long nFaculty;
    cin >> nFaculty;

    queue<long> q {};
    vector<long> values {};
    values.reserve(nFaculty);
    long curr;
    for(int i=0;i<nFaculty;i++){
        cin >> curr;
        q.emplace(i);
        values.push_back(curr);
    }

    while(q.size()>1){
        long k = (values[q.front()]-1)%q.size();

        for(int i=1;i<=k;i++){
            q.emplace(q.front());
            q.pop();
        }

        q.pop();
    }

    cout << 1+q.front() << '\n';
}