#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

int weights[10] {};
int s;
int c;

int main(){
    int tc {0};
    while(cin >> c >> s){
        double imbalance {0.0};
        double totalWeight {};
        double aveWeight {};
        int c2 {c<<1};
        for(int i=0;i<s;i++){
            cin >> weights[i];
            totalWeight += weights[i];
        }
        aveWeight = totalWeight/c;
        for(int i=s;i<c2;i++){
            weights[i] = 0;
        }

        sort(weights,weights+c2);
        
        cout << "Set #" << ++tc<< '\n';
        for(int i=0;i<c;i++){
            cout << ' ' << i << ':';

            if(weights[i] != 0){
                cout << ' ' << weights[i];
            }
            if(weights[c2-1-i] != 0){
                cout << ' ' << weights[c2-1-i];
            }
            cout << '\n';
            imbalance += (abs(aveWeight - (weights[i] + weights[c2-1-i])));
        }
        cout << "IMBALANCE = " << fixed << setprecision(5) << imbalance << "\n\n";
    }
}