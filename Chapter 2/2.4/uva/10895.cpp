#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef vector<long> vi;
typedef pair<vi,vi> pvi;
typedef vector<pvi> vpvi;

int main(){
    long rows, cols;
    long numValues;
    long curr;
    queue<long> q {};
    while(cin >> rows >> cols){

        //initialize the vector
        vpvi ans {};
        ans.reserve(cols);
        for(long i=0;i<cols;i++){
            ans.push_back(pvi {});
        }

        for(long col=1;col<=rows;col++){
            cin >> numValues;
            for(long i=0;i<numValues;i++){
                cin >> curr;
                q.emplace(curr-1);
            }
            for(long i=0;i<numValues;i++){
                cin >> curr;
                ans[q.front()].first.push_back(col);
                ans[q.front()].second.push_back(curr);
                q.pop();
            }
        }

        cout << cols << ' ' << rows << '\n';
        for(pvi currRow: ans){
            cout << currRow.first.size();
            for(long v:currRow.first){
                cout << ' ' << v;
            }
            cout << '\n';

            for(long i=0;i<currRow.second.size();i++){
                if(i!=0){
                    cout << ' ';
                }
                cout << currRow.second[i];
            }
            cout << '\n';
        }
    }
}