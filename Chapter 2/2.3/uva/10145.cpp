#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<sstream>

using namespace std;

int main(){
    long numCases;
    string s;
    getline(cin,s);
    numCases = stol(s);
    getline(cin,s);

    unordered_map<long,long> exclusiveLock {};
    unordered_map<long,unordered_set<long>> allLocks {};
    unordered_set<long> blocked {};

    //processing per request
    while(numCases){
        getline(cin, s);

        if(s.length() == 0){
            exclusiveLock.clear();
            allLocks.clear();
            blocked.clear();
            cout << '\n';
            continue;
        } else if(s=="#"){
            numCases--;
            continue;
        }

        auto strIn {stringstream(s)};
        char lock;
        long transId;
        long itemId;
        strIn >> lock >> transId >> itemId;

        if(blocked.count(transId) != 0){
            cout << "IGNORED\n";
        } else if ((exclusiveLock.count(itemId) != 0 && exclusiveLock[itemId] != transId) ||
                   (lock == 'X' && allLocks.count(itemId) != 0 && (allLocks[itemId].size() - allLocks[itemId].count(transId) > 0))){
            cout << "DENIED\n";
            blocked.emplace(transId);
        } else {
            if(allLocks.count(itemId) == 0){
                unordered_set<long> temp {};
                allLocks[itemId] = temp;
            }
            allLocks[itemId].emplace(transId);
            if(lock == 'X'){
                exclusiveLock[itemId] = transId;
            }
            cout << "GRANTED\n";
        }
    }
}