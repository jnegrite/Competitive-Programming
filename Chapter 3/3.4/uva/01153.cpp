#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct Job {
    long q {};
    long d {};

    Job(long _q, long _d){
        q = _q;
        d = _d;
    }
};

struct cmpJobQ{
    bool operator()(const Job &a, const Job &b) const {
        return a.q < b.q;
    }
};

struct cmpJobD{
    bool operator()(const Job &a, const Job &b) const {
        return a.d < b.d;
    }
};

int main(){
    long nCases;
    cin >> nCases;
    long nJobs;
    long q, d;
    for(long tc=0;tc<nCases;tc++){
        cin >> nJobs;
        vector<Job> jobs {};
        jobs.reserve(nJobs);
        for(long i=0;i<nJobs;i++){
            cin >> q >> d;
            jobs.push_back({q,d});
        }
        sort(jobs.begin(), jobs.end(),cmpJobD());

        long runningCost {};
        priority_queue<Job, vector<Job>, cmpJobQ> q;
        for(Job curr:jobs){
            //check if ok
            if(runningCost + curr.q <= curr.d){
                q.emplace(curr);
                runningCost += curr.q;
            } else if (!q.empty()){
                //check if this costs less than the top
                long change {curr.q - q.top().q};
                
                //if better
                if(change < 0){
                    q.pop();
                    q.emplace(curr);
                    runningCost += change;
                }
            }
        }

        if(tc > 0){
            cout << '\n';
        }

        cout << q.size() << '\n';
    }
}