#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int nNodes, nEdges;
vector<queue<int>> paths {};
vector<int> pathsIn {};

vector<int> ans {};
vector<int> st {};

int main(){
    while(cin >> nNodes >> nEdges, nNodes != 0 || nEdges !=0){
        paths.assign(nNodes,{});
        pathsIn.assign(nNodes,0);
        ans.clear();
        ans.reserve(nEdges+1);
        st.clear();
        st.reserve(nEdges+1);

        int a, b;
        for(int i=0;i<nEdges;++i){
            cin >> a >> b;
            paths[a].emplace(b);
            ++pathsIn[b];
        }

        //evaluate if valid config
        int idxStart {-1};
        int idxEnd {-1};
        bool isOk {true};

        for(int i=0;isOk && i<nNodes;++i){
            int diff {pathsIn[i] - paths[i].size()};

            if(diff == 0){
                continue;
            } else if (diff==-1){
                if(idxStart == -1){
                    idxStart = i;
                } else {
                    isOk=false;
                }
            } else if(diff==1){
                if(idxEnd==-1){
                    idxEnd = i;
                } else {
                    isOk = false;
                }
            } else {
                isOk = false;
            }
        }

        if(isOk){
            //find startIdx
            if(idxStart == -1){
                idxStart = 0;
                while(paths[idxStart].empty()){
                    ++idxStart;
                }
            }

            st.push_back(paths[idxStart].front());
            paths[idxStart].pop();

            while(!st.empty()){
                int curr {st.back()};

                if(paths[curr].empty()){
                    st.pop_back();
                    ans.push_back(curr);
                } else {
                    st.push_back(paths[curr].front());
                    paths[curr].pop();
                }
            }

            reverse(ans.begin(),ans.end());

            if(ans.size() < nEdges){
                isOk = false;
            }
        }

        if(!isOk){
            cout << "Impossible\n";
        } else {
            auto it {ans.begin()};
           cout << idxStart;
            while(it != ans.end()){
                cout << ' ' << *(it++);
            }
            cout << '\n';
        }
    }   
}