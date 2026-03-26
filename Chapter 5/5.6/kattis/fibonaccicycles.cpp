#include<cstdio>
#include<unordered_map>

using namespace std;

int main(){
    int nQueries {};
    int divisor {};
    int p1, p2 {};

    scanf("%d",&nQueries);
    while(nQueries--){
        scanf("%d",&divisor);
        p2 = p1 = 1;
        unordered_map<int,int> seen {};
        int currIdx {1};

        while(true){
            ++currIdx;
            int v {(p1+p2)%divisor};
            
            auto it {seen.find(v)};
            if(it != seen.end()){
                printf("%d\n",it->second);
                break;
            } else {
                seen[v] = currIdx;
                p2 = p1;
                p1 = v;
            }
        }
    }
}