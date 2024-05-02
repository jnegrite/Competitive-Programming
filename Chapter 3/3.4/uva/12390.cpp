#include<cstdio>
#include<vector>

using namespace std;
vector<int> populations {};
int n, b;

bool isValid(int v){
    int totalBoxes {};
    for(int i=0;i<n && totalBoxes <= b; ++i){
        totalBoxes += populations[i]/v;
        if(populations[i]%v != 0){
            totalBoxes++;
        }
    }
    return totalBoxes <= b;
}

int main(){
    while(scanf("%d %dn",&n,&b), n!=-1 && b!=-1){
        populations.assign(n,0);

        int low {1}, high {1};

        //initialize per city
        for(int i=0;i<n;i++){
            scanf("%d", &populations[i]);
            if(populations[i] > high){
                high = populations[i];
            }
        }

        while(low < high){
            int mid {(low+high)>>1};
            if(isValid(mid)){
                high = mid;
            } else {
                low = mid+1;
            }
        }

        printf("%d\n", low);
    }
}