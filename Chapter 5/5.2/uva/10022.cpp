#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

pair<int,int> locatePoint(int n){
    int base {sqrt(n)};
    int prod {base * base};
    if (prod == n){
        return {base-1, 2*(base-1) + 1};
    } else {
        return {base, n-prod};
    }
}

int main(){
    int nCases;
    int a, b;
    cin >> nCases;
    while(nCases--){
        cin >> a >> b;
        if (a > b ){
            swap(a,b);
        }

        int ans {0};
        auto locA {locatePoint(a)};
        auto locB {locatePoint(b)};

        if(locA.first == locB.first){
            ans = locB.second - locA.second;    
        } else {
            //check if at upper side of row
            if(locA.second%2 == 0){
                ++ans;
                //decide if left or right
                if(locB.second <= (locA.second-1)+(2*(locB.first-locA.first))){
                    --locA.second;
                } else {
                    ++locA.second;
                }
            }

            //adjust left if needed
            if(locB.second < locA.second){
                int shift {(locA.second - locB.second + 1)>>1};
                shift <<= 1;
                ans += (shift);
                locA.second-=shift;
            }

            //adjust right if needed
            int maxAbot {locA.second + ((locB.first - locA.first)<<1)};
            if(maxAbot < locB.second){
                int shift {(locB.second - maxAbot + 1)>>1};
                shift <<= 1;
                ans += shift;
                locA.second += shift;
            }

            //traverse down
            ans += ((locB.first - locA.first)<<1);

            if(locB.second%2 == 0){
                --ans;
            }
        }

        cout << ans << '\n';

        if(nCases){
            cout << '\n';
        }

    }
}