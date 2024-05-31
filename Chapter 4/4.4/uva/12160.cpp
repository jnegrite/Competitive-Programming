#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int L, U, R;
vector<int> keys {};

int main(){
    int tc {};
    while(cin >> L >> U >> R, L!=0 || U != 0 || R!= 0){
        keys.assign(R,0);
        int distance[10000] {};
        memset(distance,-1,sizeof(distance));
        
        for(int i=0;i<R;++i){
            scanf("%d",&keys[i]);
        }

        queue<int> q {};

        distance[L] = 0;
        q.push(L);

        int ans {-1};
        if(L==U){
            ans = 0;
        } else {
            while(!q.empty() && ans < 0){
                int curr {q.front()};
                q.pop();
                //printf("Processing %d\n",curr);
                int temp;
                for(auto &nxt:keys){
                    temp = (curr+nxt)%10000;

                    if(distance[temp] >= 0) continue;

                    distance[temp] = distance[curr]+1;
                    q.push(temp);

                    if(temp==U){
                        ans = distance[U];
                        break;
                    }
                }

            }
        }

        cout << "Case " << ++tc << ": ";
        if(ans < 0){
            cout << "Permanently Locked";
        } else {
            cout << ans;
        }
        cout << '\n';
    }
}