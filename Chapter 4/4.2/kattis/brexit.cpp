#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> partners {};
vector<int> currStat {};
vector<int> treshholds {};
vector<bool> visited {};
int nCountries;
int homeCountry;
int firstExit;
int a,b;


bool topsort(int pos){
    if(pos==homeCountry){
        return true;
    }
    //printf("%d left: %d:%d\n",pos,currStat[pos],treshholds[pos]);
    visited[pos] = true;
    // adjust all partners
    for(int nxt: partners[pos]){
        if(!visited[nxt]){
            if((--currStat[nxt]) <= treshholds[nxt]){
                if(topsort(nxt)){
                    return true;
                }
            }
        }
    }

    return false;
}

int main(){
    int nPartnerships;
    scanf("%d %d %d %d\n",&nCountries,&nPartnerships,&homeCountry,&firstExit);
    partners.assign(nCountries+1,{});
    currStat.assign(nCountries+1,0);
    treshholds.assign(nCountries+1,0);
    visited.assign(nCountries+1,false);
    while(nPartnerships--){
        scanf("%d %d\n",&a,&b);
        partners[a].push_back(b);
        partners[b].push_back(a);
    }

    //get tresholds
    for(int i=1;i<=nCountries;i++){
        currStat[i] = partners[i].size();
        treshholds[i] = ((partners[i].size())>>1);
    }

    if(topsort(firstExit)){
        printf("leave\n");
    } else {
        printf("stay\n");
    }
}