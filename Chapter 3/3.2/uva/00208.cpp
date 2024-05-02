#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
int target {};
bool connected[21][21] {};
int p[21] {};
vector<bool> isUsed {};
int currPath[21] {};
int pathLength {};
int numPaths {};

int getParent(int i){
    return p[i]==i?i:p[i]=getParent(p[i]);
}

void backtrack(int node){
    if(node == target){
        ++numPaths;
        printf("1");
        for(int i=1;i<pathLength;i++){
            printf(" %d",currPath[i]);
        }
        printf("\n");
        return;
    }

    for(int curr=1;curr<21;curr++){

        if(!connected[node][curr] || isUsed[curr] || getParent(curr) != target){
            continue;
        }

        currPath[pathLength++] = curr;
        isUsed[curr] = true;
        
        backtrack(curr);

        isUsed[curr] = false;
        pathLength--;
    }
}

int main(){
    int tc {};
    while(scanf("%d\n",&target)!=EOF){
        for(int i=0;i<21;i++){
            p[i] = i;
            for(int j=i+1;j<21;j++){
                connected[i][j] = connected[j][i] = false;
            }
        }
        int a, b;
        while(scanf("%d %d\n",&a,&b),a!=0 && b!=0){
            connected[a][b] = connected[b][a] = true;

            if(a==1 || b==1){
                continue;
            }
            
            int pa {getParent(a)};
            int pb {getParent(b)};
            if (pa==target){
                p[pb] = pa;
            } else if (pb==target){
                p[pa] = pb;
            } else {
                p[pa] = pb;
            }

        }
        isUsed.assign(21, false);
        numPaths = 0;
        currPath[0] = 1;
        pathLength = 1;

        isUsed[1] = true;

        printf("CASE %d:\n",++tc);
        backtrack(1);   
        printf("There are %d routes from the firestation to streetcorner %d.\n",numPaths,target);

    }
}