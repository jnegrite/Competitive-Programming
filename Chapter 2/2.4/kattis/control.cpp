#include<cstdio>
#include<vector>
#include<unordered_map>
using namespace std;

vector<long> p {};
vector<long> rk {};
vector<long> sz {};

long getParent(long i){
    return p[i] == i ? i : p[i]=getParent(p[i]);
}

int main(){

    const long nIngredients {500001};
    //prepare data
    p.reserve(500001);
    for(long i=0;i<nIngredients;i++){
        p.push_back(i);
    }
    rk.assign(nIngredients,0);
    sz.assign(nIngredients,1);

    //process
    long nRecipes;
    scanf("%ld\n", &nRecipes);
    long recipesMade {};
    while(nRecipes--){
        long nIngredients;
        long curr, currP;
        scanf("%ld",&nIngredients);
        unordered_map<long,long> rawMat {};

        //get ingredients from this
        while(nIngredients--){
            scanf(" %ld",&curr);
            currP = getParent(curr);
            auto it = rawMat.find(currP);
            if(it == rawMat.end()){
                rawMat[currP] = 1;
            } else {
                ++(it->second);
            }
        }

        //check if stars align for these ingredients
        bool isOk{true};
        for(auto it=rawMat.begin(); it != rawMat.end();++it){
            if(sz[it->first] != it->second){
                isOk = false;
                break;
            }
        }

        if(!isOk){
            continue;
        }

        //merge if ok
        ++recipesMade;

        long p1, p2;
        auto it = rawMat.begin();
        p1 = it->first;
        
        ++it;
        while(it != rawMat.end()){
            p2 = it->first;
            if(rk[p1] < rk[p2]){
                swap(p1,p2);
            } else if(rk[p1] == rk[p2]){
                ++rk[p1];
            }

            p[p2] = p1;
            sz[p1] += sz[p2];
            sz[p2] = 0;
            ++it;
        }

    }
    printf("%ld\n",recipesMade);
}