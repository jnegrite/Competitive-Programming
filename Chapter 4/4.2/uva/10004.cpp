#include<cstdio>
#include<vector>

using namespace std;

int nNodes;
vector<int> color {};
vector<vector<int>> paths {};
bool isOk {true};

void colorNode(int pos, int shade){
    color[pos] = shade;
    auto &links {paths[pos]};
    int nxtShade {1-shade};
    for(int i=0;i<links.size() && isOk; ++i){
        if(color[links[i]] == -1){
            colorNode(links[i],nxtShade);
        } else if (color[links[i]] != nxtShade){
            isOk = false;
        }
    }
}

int main(){
    while(scanf("%d\n",&nNodes),nNodes != 0){
        paths.assign(nNodes,{});
        color.assign(nNodes,-1);

        int nEdges, a, b;
        scanf("%d\n",&nEdges);
        while(nEdges--){
            scanf("%d %d\n",&a,&b);
            paths[a].push_back(b);
            paths[b].push_back(a);
        }

        isOk = true;
        colorNode(0,0);

        if(!isOk){
            printf("NOT ");
        }
        printf("BICOLORABLE.\n");
    }
}