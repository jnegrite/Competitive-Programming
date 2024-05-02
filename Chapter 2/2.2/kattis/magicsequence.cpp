#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int numCases;
unsigned long N;
unsigned long A, B, C, curr;
unsigned long X, Y;

int main(){
    
    
    cin >> numCases;
    for(int tc=0;tc<numCases;tc++){
        cin >> N
            >> A >> B >> C
            >> X >> Y;

        vector<vector<unsigned long>> data {};
        unsigned long lastIdx {sqrt(C)+1};
        for(unsigned long i=0;i<=lastIdx;i++){
            vector<unsigned long> temp {};
            data.push_back(temp);
        }

        if(A<C){
            data[A/lastIdx].push_back(A);
        }

        curr = A;
        for(unsigned long i=1;i<N;i++){
            curr = (curr * B + A)%C;
            data[curr/lastIdx].push_back(curr);
            //cout << "=> " << curr << '\n';
        }

        unsigned long v {0};
        //cout << "-----------\n";
        for(unsigned long i=0;i<=lastIdx;i++){
            sort(data[i].begin(),data[i].end());
            for(auto au:data[i]){
                v = (v*X + au)% Y;
                //cout << v << '\n';
            }
        }
        //cout << "-----------\n";

        if(A >= C){
            v = (v*X+A)%Y;
        }
        cout << v << '\n';
    }
}