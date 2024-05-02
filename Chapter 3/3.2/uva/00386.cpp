#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct cmp_vector{
    bool operator()(const vector<int> &a, const vector<int> &b) const {
        for(int i=0;i<4;i++){
            if(i==3 || a[i] != b[i]){
                return a[i] < b[i];
            }
        }
    }
};

long cube(long x){
    return x*x*x;
}

int main(){

    //precalculate
    unordered_map<long,int> cubes {};
    for(long i=1;i<=200;i++){
        cubes[cube(i)] = i;
    }
    long maxVal {cube(200)};

    vector<vector<int>> ans {};
    //do looping
    for(long b=2;b<=200;++b){
        long cubeB {cube(b)};
        long upperBound {(1+maxVal-cubeB)>>1};
        for(long c=b;;c++){
            long cubeC {cube(c)};
            if(cubeC > upperBound){
                break;
            }

            for(long d=c;;d++){
                long cubeD {cube(d)};
                long total {cubeB+cubeC+cubeD};

                if(total > maxVal){
                    break;
                }

                auto it {cubes.find(total)};
                if(it != cubes.end()){
                    ans.push_back(vector<int>{it->second,b,c,d});
                }
            }
        }
    }

    sort(ans.begin(), ans.end(),cmp_vector());
    for(auto au:ans){
        printf("Cube = %d, Triple = (%d,%d,%d)\n",au[0],au[1],au[2],au[3]);
    }
}