#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std;

int nPeople;
vector<string> names {};
unordered_map<string,int> mapNames {};
vector<vector<int>> paths {};
vector<vector<int>> pathsRev {};
stack<int> ts {};
stack<int> circle {};
vector<bool> visited {};

int getNum(const string &s){
    auto it {mapNames.find(s)};
    if(it!=mapNames.end()){
        return it->second;
    }

    int ans = mapNames[s] = names.size();
    names.push_back(s);
    return ans;
}

void kosaraju(int pos, bool forwards){
    visited[pos] = true;
    vector<int> *curr;
    stack<int> *cs;

    if(forwards){
        curr = &(paths[pos]);
        cs = &ts;
    } else {
        curr = &(pathsRev[pos]);
        cs = &circle;
    }

    for(int nxt: *curr){
        if(!visited[nxt]){
            kosaraju(nxt,forwards);
        }
    }
    cs->push(pos);
}

int main(){
    int nCalls;
    int tc {0};
    string s1, s2;
    int id1, id2;
    bool isFirst {true};

    while(cin >> nPeople >> nCalls, nPeople!=0 || nCalls!=0){
        paths.assign(nPeople, {});
        pathsRev.assign(nPeople, {});

        names.clear();
        names.reserve(nPeople);
        mapNames.clear();

        while(nCalls--){
            cin >> s1 >> s2;
            id1 = getNum(s1);
            id2 = getNum(s2);
            
            paths[id1].push_back(id2);
            pathsRev[id2].push_back(id1);
        }

        //forwards
        visited.assign(nPeople,false);
        while(!ts.empty()){
            ts.pop();
        }
        for(int i=0;i<nPeople;++i){
            if(!visited[i]){
                kosaraju(i,true);
            }
        }

        //backwards
        visited.assign(nPeople,false);
        while(!circle.empty()){
            circle.pop();
        }

        if(isFirst){
            isFirst=false;
        } else {
            cout << "\n";
        }

        cout << "Calling circles for data set " << ++tc << ":\n";
        while(!ts.empty()){
            int curr {ts.top()};
            ts.pop();

            if(!visited[curr]){
                kosaraju(curr,false);

                //printing out
                while(!circle.empty()){
                    cout << names[circle.top()];
                    circle.pop();

                    if(circle.empty()){
                        cout << '\n';
                    } else {
                        cout << ", ";
                    }
                }
            }
        }
    }
}
