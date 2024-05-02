#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
using ii = pair<long,long>;

struct cmp{
    bool operator()(const ii &a, const ii &b) const {
        if(a.second != b.second){
            return a.second < b.second;
        } else {
            return a.first > b.first;
        }
    }
};

int main(){
    long nActivities, nClassrooms;
    cin >> nActivities >> nClassrooms;
    vector<ii> activities {};
    multiset<long long> classrooms {};

    activities.reserve(nActivities);
    
    for(long long i=0;i<nClassrooms;i++){
        classrooms.emplace(0);
    }

    //get activities
    for(long i=0;i<nActivities;i++){
        long s,f;
        cin >> s >> f;
        activities.push_back(ii{s,f});
    }
    sort(activities.begin(),activities.end(),cmp());

    long long ans {};
    for(auto it{activities.begin()};it!=activities.end();it++){
        long long start {it->first};
        auto au {classrooms.lower_bound(start)};

        if(au != classrooms.begin()){
            --au;
            classrooms.erase(au);
            classrooms.emplace(it->second);
            ans++;
        }
    }
    cout << ans << '\n';
}