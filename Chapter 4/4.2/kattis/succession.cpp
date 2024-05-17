#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<algorithm>

using namespace std;

struct BloodComp {
    long long num {0LL};
    long long denom{1LL};

    bool operator<(const BloodComp& o) const {
        if(denom <= o.denom){
            long long factor {o.denom/denom};
            return num*factor < o.num;
        } else {
            long long factor {denom/o.denom};
            return num < factor*o.num;
        }
    }

    BloodComp operator+(const BloodComp &o){
        long long nNum;
        long long nDenom;
        if(denom <= o.denom){
            long long factor {o.denom/denom};
            nNum = num*factor + o.num;
            nDenom = (o.denom<<1);
        } else {
            long long factor {denom/o.denom};
            nNum = num + factor*o.num;
            nDenom = (denom<<1);
        }
        long long gcd {__gcd(nNum,nDenom)};
        return {nNum/gcd, nDenom/gcd}; 
    }
};

vector<string> names {};
unordered_map<string,int> mapNames {};
vector<vector<int>> parents {};
vector<BloodComp> bloodComponents{};

int getId(const string &s){
    auto it {mapNames.find(s)};
    if(it!=mapNames.end()){
        return it->second;
    }

    int ans = mapNames[s] = names.size();
    parents.push_back({});
    bloodComponents.push_back({-1LL,1LL});
    names.push_back(s);
    return ans;
}

BloodComp getBlood(int pos){
    BloodComp temp {bloodComponents[pos]};
    if(temp.num != -1){
        return temp;
    }

    if(parents[pos].size()==0){
        bloodComponents[pos].num = 0LL;
        return bloodComponents[pos];
    }

    BloodComp b1 {getBlood(parents[pos][0])};
    BloodComp b2 {getBlood(parents[pos][1])};
    return b1+b2;
}

int main(){
    int nRelations, nClaimants;
    cin >> nRelations >> nClaimants;
    string s, s1, s2;
    int iChild, i1, i2;

    //founder
    cin >> s;
    getId(s);
    bloodComponents[0].num = 1;

    //others
    for(int i=0;i<nRelations;i++){
        cin >> s >> s1 >> s2;
        iChild = getId(s);
        i1 = getId(s1);
        i2 = getId(s2);
        parents[iChild].push_back(i1);
        parents[iChild].push_back(i2);
    }

    //nClaimants
    cin >> s;
    int bestClaimant {getId(s)};
    BloodComp bestBlood {getBlood(bestClaimant)};
    for(int i=1;i<nClaimants;i++){
        cin >> s;
        int tempC {getId(s)};
        BloodComp temp {getBlood(tempC)};
        if(bestBlood < temp){
            bestBlood=temp;
            bestClaimant=tempC;
        }
    }
    cout << names[bestClaimant] << '\n';
}