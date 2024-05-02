#include<cstdio>
#include<set>

using namespace std;

int main(){
    set<int> scores {};
    for(int i=1;i<=20;i++){
        for(int j=1;j<=3;j++){
            scores.emplace(i*j);
        }
    }
    scores.emplace(0);
    scores.emplace(50);

    int target;
    while(scanf("%d\n",&target),target > 0){
        long combinations {};
        long permutations {};
        for(auto i=scores.begin();i!=scores.end();++i){
            for(auto j=i;j!=scores.end();++j){
                for(auto k=j;k!=scores.end();++k){
                    if(*i + *j + *k == target){
                        ++combinations;

                        if(*i == *k){
                            permutations++;
                        } else if (*i==*j || *j==*k){
                            permutations+=3;
                        } else {
                            permutations+=6;
                        }
                    }
                }
            }
        }

        if(combinations==0){
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",target);
        } else {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %ld.\n",target,combinations);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %ld.\n",target,permutations);
        }
        printf("**********************************************************************\n");
    }
    printf("END OF OUTPUT\n");
}