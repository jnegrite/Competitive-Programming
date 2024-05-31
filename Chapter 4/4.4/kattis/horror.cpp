#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int nMovies, nHorror, nSimilarities;
vector<int> horrorIndex {};
vector<vector<int>> paths {};

int main(){
    cin >> nMovies >> nHorror >> nSimilarities;

    horrorIndex.assign(nMovies,-1);
    paths.assign(nMovies,{});
    queue<int> q {};
    int val;
    while(nHorror--){
        cin >> val;
        horrorIndex[val] = 0;
        q.push(val);
    }
    int a, b;
    while(nSimilarities--){
        cin >> a >> b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    
    while(!q.empty()){
        int curr {q.front()};
        q.pop();

        for(int nxt: paths[curr]){
            if(horrorIndex[nxt] != -1) continue;

            horrorIndex[nxt] = horrorIndex[curr]+1;
            q.push(nxt);
        }
    }

    int ans {-1};
    int bestHI {-1};
    for(int i=0;i<nMovies;++i){
        if(horrorIndex[i] == -1){
            ans = i;
            break;
        }

        if(horrorIndex[i] > bestHI){
            bestHI = horrorIndex[i];
            ans = i;
        }
    }
    cout << ans << '\n';
}