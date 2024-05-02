#include<cstdio>
#include<cmath>
#include<set>
#include<vector>

using namespace std;

int main(){
    int nNumbers;
    int nQueries;
    long curr;
    vector<long> numbers {};
    set<long> sums {};
    int tc {};

    while(scanf("%d\n",&nNumbers),nNumbers != 0){
        printf("Case %d:\n",++tc);
        numbers.clear();
        numbers.reserve(nNumbers);
        sums.clear();

        for(int i=0;i<nNumbers;i++){
            scanf("%ld\n",&curr);

            for(int prev:numbers){
                sums.emplace(prev+curr);
            }
            numbers.push_back(curr);
        }

        scanf("%d\n",&nQueries);
        
        for(int i=0;i<nQueries;i++){
            scanf("%ld\n",&curr);
            long distance = 1000000000;
            long currDist;
            long ans = 0;

            auto it = sums.lower_bound(curr);
            if(it != sums.end()){
                currDist = abs(*it - curr);
                if(currDist < distance){
                    ans = *it;
                    distance = currDist;
                }
            }

            if(it != sums.begin()){
                --it;
                currDist = abs(*it - curr);
                if(currDist < distance){
                    ans = *it;
                    distance = currDist;
                }
            }
            
            printf("Closest sum to %ld is %ld.\n",curr,ans);

        }
    }
}