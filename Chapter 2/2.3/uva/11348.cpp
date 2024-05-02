#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<iomanip>

using namespace std;

int main(){
    int numCases;
    cin >> numCases;
    for(int tc=1;tc<=numCases;tc++){
        int numFriends;
        cin >> numFriends;
        long uniqueStickers[50] {};
        long totalUnique {};
        long curr;

        for(int i=0;i<numFriends;i++){
            uniqueStickers[i] = 0;
        }


        //get data
        unordered_map<long, unordered_set<int>> owners {};
        for(int i=0;i<numFriends;i++){
            int numStickers;
            cin >> numStickers;

            for(int j=0;j<numStickers;j++){
                cin >> curr;

                if(owners.count(curr) == 0){
                    unordered_set<int> temp {};
                    owners[curr] = temp;
                }

                owners[curr].emplace(i);
            }
        }

        //summarize
        for(auto it:owners){
            if(it.second.size() == 1){
                totalUnique++;
                uniqueStickers[*(it.second.begin())]++;
            }
        }

        //print
        cout << "Case " << tc << ":";
        for(int i=0;i<numFriends;i++){
            cout << ' ' << setprecision(6) << fixed << 100.0 * uniqueStickers[i]/totalUnique << '%';
        }
        cout << '\n';
    }
}