#include<cstdio>
#include<unordered_map>

using namespace std;

int z, i, m, l;
int t, h;

int f(int prev){
    return (z*prev+i)%m;
}

int main(){

    int nCases {0};

    while(scanf("%d %d %d %d",&z,&i,&m,&l), z!= 0 || i!=0 || m!=0 || l!=0){
        int currStep {0};
        unordered_map<int,int> mp {};

        while(true){
            l = f(l);
            
            auto it {mp.find(l)};
            
            if(it == mp.end()){
                mp[l] == ++currStep;
            } else {
                printf("Case %d: %d\n", ++nCases, (currStep-(it->second)));
                break;
            }
        }
    }
}