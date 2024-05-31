#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
vector<int> buttons {};
int minPresses[3601] {};
int target;

int main(){
    int nCases;
    cin >> nCases;

    while(nCases--){
        buttons.clear();
        int nButtons;
        int value;

        cin >> nButtons >> target;
        buttons.assign(nButtons,0);
        for(int i=0;i<nButtons;i++){
            cin >> buttons[i];
        }

        memset(minPresses,-1,sizeof(minPresses));
        minPresses[0] = 0;
        queue<int> q {};
        q.push(0);

        while(!q.empty() && minPresses[target] == -1){
            int curr {q.front()};
            q.pop();

            for(int delta:buttons){
                int temp = curr + delta;

                temp = min(max(temp,0),3600);

                if(minPresses[temp] >= 0) continue;

                minPresses[temp] = minPresses[curr] + 1;
                q.push(temp);
            }
        }

        for(int i=0;target+i<=3600;i++){
            if(minPresses[target+i] != -1){
                cout << minPresses[target+i] << ' ' << i << '\n';
                break;
            }
        }
    }    
}