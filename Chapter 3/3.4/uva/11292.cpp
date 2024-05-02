#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main(){
    long n, m, curr;
    while(cin >> n >> m, n!= 0 && m!=0){
        vector<long> dragons {};
        vector<long> knights {};

        dragons.reserve(n);
        knights.reserve(m);
        for(long i=0;i<n;i++){
            cin >> curr;
            dragons.push_back(curr);
        }

        for(long i=0;i<m;i++){
            cin >> curr;
            knights.push_back(curr);
        }
        long totalPaid {-1};
        
        if(m>=n){
            totalPaid = 0;
            sort(dragons.begin(),dragons.end(),greater<long>());
            sort(knights.begin(),knights.end(),greater<long>());

            long idxD {n-1};
            long idxK {m-1};

            while(idxD >= 0 && idxK >= idxD){
                //check if knight can slay
                if(dragons[idxD] <= knights[idxK]){
                    totalPaid += knights[idxK];
                    --idxD;
                }
                --idxK;
            }
            if(idxD>=0){
                totalPaid = -1;
            }
        }

        if(totalPaid==-1){
            cout << "Loowater is doomed!\n";
        } else {
            cout << totalPaid << '\n';
        }

    }
}