#include<iostream>
#include<queue>

using namespace std;

struct Instrument {
    long nMembers {};
    long nStands {};
    long maxCrowd {};

    Instrument(long _nMembers){
        maxCrowd = nMembers = _nMembers;
        nStands = 1;
    }

    void addStand(){
        nStands++;
        maxCrowd = nMembers/nStands;
        if(nMembers%nStands != 0){
            maxCrowd++;
        }
    }

    bool operator<(const Instrument &o) const {
        return maxCrowd < o.maxCrowd;
    }
};

int main(){
    long p, n, curr;
    while(cin >> p >> n){
        priority_queue<Instrument> instruments {};
        for(long i=0;i<n;i++){
            cin >> curr;
            instruments.push({curr});
        }

        for(long i=n;i<p;i++){
            Instrument top {instruments.top()};
            instruments.pop();

            top.addStand();
            instruments.emplace(top);
        }
        cout << instruments.top().maxCrowd << '\n';
    }
}