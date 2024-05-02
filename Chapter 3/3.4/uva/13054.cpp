#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int nCases;
    cin >> nCases;
    long nHippos;
    long h, ta, td, curr;
    vector<long> hippos {};
    long totalTime {};
    for(int tc=1;tc<=nCases;tc++){
        cin >> nHippos >> h >> ta >> td;
        
        hippos.clear();
        hippos.reserve(nHippos);
        totalTime = 0;
        for(long i=0;i<nHippos;i++){
            cin >> curr;

            if(curr >= h){
                totalTime += ta;
            } else {
                hippos.push_back(curr);
            }
        }
        if(td >= (ta<<1)){
            totalTime = nHippos * ta; 
        } else {
            sort(hippos.begin(),hippos.end());
            long idxFront {0};
            long idxBack {hippos.size()-1};
            while(idxFront <= idxBack){
                if(idxFront < idxBack && hippos[idxFront] + hippos[idxBack] < h){
                    totalTime += td;
                    ++idxFront;
                } else{
                    totalTime += ta;
                }
                --idxBack;
            }
        }
        cout << "Case " << tc << ": " << totalTime << '\n';
    }
}