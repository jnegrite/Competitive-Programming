#include<cstdio>
#include<vector>

using namespace std;
int nHosts {}, nConnections{};
int nGroups {};
vector<int> org {};
vector<vector<int>> links {};
int counts[2] {};
bool isBipartite;

void process(int pos, int orgNum){
    org[pos] = orgNum;
    for(int &nxt: links[pos]){
        if(org[nxt] == -1){
            process(nxt,1-orgNum);
        } else if(org[nxt] == orgNum){
            isBipartite = false;
        }
    }
}

int main(){
    scanf("%d %d\n",&nHosts,&nConnections);
    org.assign(nHosts+1,-1);
    links.assign(nHosts+1,{});

    int a, b;   
    while(nConnections--){
        scanf("%d %d\n",&a,&b);
        links[a].push_back(b);
        links[b].push_back(a);
    }

    for(int i=1;i<=nHosts;++i){
        if(org[i] == -1){
            isBipartite = true;
            process(i,0);

            if(isBipartite){
                counts[1]++;
            } else {
                counts[0]++;
            }
        }
    }

    if(counts[0] > 0){
        nGroups = counts[0] + counts[1] - 1;
    } else {
        nGroups = counts[1];
    }
    printf("%d\n",nGroups);
}