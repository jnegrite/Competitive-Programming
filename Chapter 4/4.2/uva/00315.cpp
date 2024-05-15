#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int nPoints {};
vector<vector<int>> paths {};
vector<int> parent {};
vector<int> df_num {};
vector<int> df_low {};
vector<bool> artVertex {};
int rootNode;
int rootChildren;
int ctr;
int ans {};

void articulationPoint(int pos){
    df_num[pos] = df_low[pos] = ctr++;
    for(int &nxt: paths[pos]){
        

        if(df_num[nxt] == -1){
            parent[nxt] = pos;
            if(pos == rootNode){
                rootChildren++;
            }

            articulationPoint(nxt);

            if(df_low[nxt] >= df_num[pos]){
                artVertex[pos] = true;
            }
            
            df_low[pos] = min(df_low[pos],df_low[nxt]);
        } else if(parent[pos] != nxt){
            df_low[pos] = min(df_low[pos],df_num[nxt]);
        }
    }
}

int main(){
    while(cin >> nPoints >> ws,nPoints!=0){
        nPoints++;

        paths.assign(nPoints,{});
        parent.assign(nPoints,-1);
        df_num.assign(nPoints,-1);
        df_low.assign(nPoints,1000);
        artVertex.assign(nPoints,false);
        nPoints--;
        ans = 0;

        //get data
        string s;
        int a, b;
        while(getline(cin,s),s!="0"){
            auto strIn {stringstream(s)};
            strIn >> a;
            while(strIn>>b){
                paths[a].push_back(b);
                paths[b].push_back(a);
            }
        }

        for(int i=1;i<=nPoints;i++){
            if(df_num[i] == -1){
                rootNode = i;
                rootChildren = 0;
                ctr = 0;
                articulationPoint(i);
                artVertex[rootNode] = (rootChildren > 1);
            }
        }
        ans = 0;
        for(int i=1;i<=nPoints;i++){
            if(artVertex[i]){
                ans++;
            }
        }
        cout << ans << '\n';
    }
}