#include<cstdio>
#include<set>
#include<queue>

using namespace std;

int main(){
    long numValues;
    long curr;
    scanf("%ld\n",&numValues);
    set<long> genePool {};
    multiset<long> innerNodes {};
    queue<long> q {};
    for(long i=1;i<=numValues;i++){
        genePool.emplace(i);
    }
    genePool.emplace(numValues+1);

    for(long i=0;i<numValues;i++){
        scanf("%ld",&curr);
        
        auto it {genePool.find(curr)};
        if(it != genePool.end()){
            genePool.erase(it);
        }
        innerNodes.emplace(curr);
        q.emplace(curr);
    }
    
    queue<long> output {};
    bool isOk {true};
    if(curr != numValues+1){
        printf("ERROR\n");
    } else {
        while(!q.empty()){
            curr = q.front();
            q.pop();

            auto it = innerNodes.find(curr);
            long valRemoved {*genePool.begin()};
            
            printf("%ld\n",valRemoved);
            genePool.erase(genePool.begin());
            innerNodes.erase(it);

            if(innerNodes.count(curr) == 0){
                genePool.emplace(curr);
            }
        }
    }
};