#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

unordered_map<string,int> code {};
unordered_set<int> parents {};
vector<int> p {};
vector<int> sz {};
vector<int> rk {};

int getParent(int i){
    return p[i] == i ? i : p[i]=getParent(p[i]);
}

int main(){
    int nCreatures, nRelations;
    string s1, s2;
    while(cin >> nCreatures >> nRelations, nCreatures != 0 || nRelations != 0){
        code.clear();
        p.clear();
        parents.clear();
        parents.reserve(nCreatures);
        sz.assign(nCreatures,1);
        rk.assign(nCreatures,0);
        for(int i=0;i<nCreatures;i++){
            cin >> s1;
            code[s1] = i;
            p.push_back(i);
            parents.emplace(i);
        }

        while(nRelations--){
            cin >> s1 >> s2;
            int p1, p2;
            p1 = getParent(code[s1]);
            p2 = getParent(code[s2]);

            if(p1==p2){
                continue;
            }

            //process if not the same
            if(rk[p1] > rk[p2]){
                swap(p1,p2);
            } else if (rk[p1] == rk[p2]){
                rk[p1]++;
            }

            sz[p1] += sz[p2];
            sz[p2] = 0;

            p[p2] = p1;
            parents.erase(p2);
        }

        int maxChain {0};
        for(int val:parents){
            maxChain = max(maxChain,sz[val]);
        }
        cout << maxChain << '\n';
    }
}