#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

struct Query{
    long time {};
    long num {};
    long period {};

    Query(long _time, long _num, long _period){
        time = _time;
        num = _num;
        period = _period;
    }

    Query(){
    }
};

struct query_comparator {
    bool operator()(const Query &a, const Query &b){
        if (a.time != b.time){
            return a.time > b.time;
        } else {
            return a.num > b.num;
        }
    }
};

int main(){
    string s, temp;
    long period;
    long qNum;
    priority_queue<Query,vector<Query>,query_comparator> q {};
    while(getline(cin,s), s != "#"){
        auto strIn {stringstream(s)};
        strIn >> temp >> qNum >> period;
        Query curr {period, qNum, period};
        q.emplace(curr);
    }

    long numQueries {};
    getline(cin,s);
    numQueries = stol(s);
    while(numQueries--){
        Query curr {q.top()};
        q.pop();

        cout << curr.num << '\n';
        curr.time += curr.period;
        q.emplace(curr);
    }
}