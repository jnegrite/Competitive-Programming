#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Job {
    long t {};
    long s {};
    int idx {};

    Job(long _t, long _s, int _idx){
        t = _t;
        s = _s;
        idx = _idx;
    }

    bool operator<(const Job &o) const {
        long cmp {t * o.s - o.t*s};
        if(cmp!=0){
            return cmp < 0;
        } else {
            return idx < o.idx;
        }
    }
};

int main(){
    int nCases;
    cin >> nCases;
    
    int nValues;
    long a, b;
    vector<Job> jobs {};
    for(int tc=0;tc<nCases;tc++){
        jobs.clear();

        cin >> nValues;
        jobs.reserve(nValues);
        for(int i=1;i<=nValues;i++){
            cin >> a >> b;
            jobs.push_back({a,b,i});
        }
        sort(jobs.begin(),jobs.end());

        if(tc!=0){
            cout << '\n';
        }
        cout << jobs[0].idx;
        for(int i=1;i<nValues;i++){
            cout << ' ' << jobs[i].idx;
        }
        cout << '\n';
    }
}