#include<cstdio>
#include<vector>

using namespace std;
vector<pair<int,int>> links {};
vector<vector<int>> paths {};
vector<int> org {};
int nPoints {};

void process(int pos, int orgNum){
    org[pos] = orgNum;
    for(int &nxt: paths[pos]){
        if(org[nxt] == -1){
            process(nxt,1-orgNum);
        }
    }
}

int main(){
    scanf("%d\n",&nPoints);
    paths.assign(nPoints+1,{});
    org.assign(nPoints+1,-1);

    int a, b;
    for(int i=1;i<nPoints;i++){
        scanf("%d %d\n",&a,&b);
        paths[a].push_back(b);
        paths[b].push_back(a);
        links.push_back({a,b});
    }

    process(1,0);
    for(auto pr:links){
        printf("%d\n",org[pr.first]);
    }


}