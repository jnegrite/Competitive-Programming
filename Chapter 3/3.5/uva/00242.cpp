#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int memo[10][1000][10] {};
vector<int> currDenoms{};

int dp(int pos, int value, int stamps){
    if(pos == currDenoms.size() || stamps == 0){
        return 0;
    }

    if(value == currDenoms[pos]){
        return 1;
    }

    auto &curr {memo[pos][value][stamps]};

    if(curr!=-1){
        return curr;
    }

    curr = 0;
    //check if possible to use
    if(value > currDenoms[pos]){
        curr = dp(pos,value-currDenoms[pos],stamps-1);
        if(curr == 1){
            return curr;
        }
    }

    return curr = dp(pos+1,value,stamps);
}

bool isBetter(const vector<int> &a, const vector<int> &b) {
    if(a.size() != b.size()){
        return a.size() < b.size();
    }

    for(int i=a.size()-1;i>=0;--i){
        if(a[i] != b[i]){
            return a[i] < b[i];
        }
    }
    return false;
}

int main(){
    int nStamps {};
    while(scanf("%d\n",&nStamps),nStamps!=0){
        int nGroups {};
        scanf("%d\n", &nGroups);
        int bestCover {-1};
        vector<int> bestDenoms {};
        
        while(nGroups--){
            int nDenoms;
            scanf("%d",&nDenoms);
            
            currDenoms.clear();
            currDenoms.assign(nDenoms,0);
            for(int i=0;i<nDenoms;++i){
                scanf("%d",&currDenoms[i]);
            }

            sort(currDenoms.begin(), currDenoms.end());

            memset(memo,-1,sizeof(memo));
            int currCover {1};
            for(currCover=1;currCover<=1000;++currCover){
                if(dp(0,currCover,nStamps)==0){
                    break;
                }
            }

            if(currCover > bestCover || 
                    (currCover == bestCover && isBetter(currDenoms,bestDenoms))){
                bestDenoms.assign(currDenoms.size(),0);
                copy(currDenoms.begin(),currDenoms.end(),bestDenoms.begin());
                bestCover = currCover;
            }
        }

        printf("max coverage =%4d :",bestCover-1);
        for(int d:bestDenoms){
            if(d==100){
                printf(" 100");
            } else {
                printf("%3d",d);
            }
        }
        printf("\n");
    }
}