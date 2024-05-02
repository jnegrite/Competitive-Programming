#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Prescription{
    string name {};
    int priority {};
    long time {};
    long freq {};

    Prescription(){}
    Prescription(string _name, int _priority, long _freq){
        name = _name;
        priority = _priority;
        freq = _freq;
        time = freq;
    }
};

struct comp_prescription{
    bool operator()(const Prescription &a, const Prescription &b){
        if(a.time != b.time){
            return a.time > b.time;
        } else {
            return a.priority > b.priority;
        }
    }
};

int main(){
    int numCases;
    cin >> numCases;
    while(numCases--){
        int n, k;
        string s;
        long freq;
        cin >> n >> k;
        Prescription curr {};
        
        priority_queue<Prescription,vector<Prescription>,comp_prescription> q {};

        for(int i=0;i<n;i++){
            cin >> s >> freq;
            Prescription p {s,i,freq};
            q.emplace(p);
        }

        while(k--){
            curr = q.top();
            cout << curr.time << ' ' << curr.name << '\n';
            curr.time += curr.freq;
            q.pop();
            q.emplace(curr);
        }
    }
}