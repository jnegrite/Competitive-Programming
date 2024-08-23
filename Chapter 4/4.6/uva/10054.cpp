#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_set>
#include<stack>

using namespace std;

vector<unordered_multiset<int>> colors {};

int main(){
    int nCases;
    cin >> nCases;

    int nBeads;
    for(int tc=1;tc<=nCases;++tc){

        //get data
        cin >> nBeads;
        int seed {51};
        colors.assign(51,{});

        int a, b;
        for(int i=0;i<nBeads;++i){
            cin >> a >> b;
            colors[a].emplace(b);
            colors[b].emplace(a);

            seed = min(seed,a);
        }

        vector<int> ans {};
        stack<int> st {};

        st.push(seed);

        while(!st.empty()){
            int u = st.top();
            if(colors[u].size() > 0){
                int nxt {*colors[u].begin()};
                st.push(nxt);
                colors[nxt].erase(colors[nxt].find(u));
                colors[u].erase(colors[u].find(nxt));
            } else {
                ans.push_back(u);
                st.pop();
            }
        }

        //printing
        cout << "Case #" << tc << '\n';
        if(ans.size() <= nBeads || (ans[0] != ans[ans.size()-1])){
            cout << "some beads may be lost\n";
        } else {
            for(int i=0;i<nBeads;++i){
                cout << ans[i] << ' ' << ans[i+1] << '\n';
            }
        }
        cout << '\n';
    
    }
}