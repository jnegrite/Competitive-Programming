#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Period {
    int from {};
    int to {};

    Period(int _from, int _to){
        from = _from;
        to = _to;
    }

    bool operator<(const Period &o) const {
        if(from != o.from){
            return from < o.from;
        }

        return to < o.to;
    }
};

vector<Period> periods {};

int lastPeriod {};
int currPeriods {};
int maxPeriods {};

void backtrack(int pos){
    if(pos == periods.size()){
        if(currPeriods > maxPeriods){
            maxPeriods = currPeriods;
        }
        return;
    }

    backtrack(pos+1);

    if(periods[pos].from >= lastPeriod){
        int cachedLast {lastPeriod};
        ++currPeriods;
        lastPeriod = periods[pos].to;

        backtrack(pos+1);
        lastPeriod = cachedLast;
        --currPeriods;

    }
}

int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        int from, to;

        periods.clear();
        while(cin >> from >> to,from!=0 || to!=0){
            periods.push_back(Period{from,to});
        }
        sort(periods.begin(),periods.end());
        lastPeriod = 0;
        currPeriods = 0;
        maxPeriods = 0;

        backtrack(0);

        cout <<maxPeriods << '\n';
    }
}