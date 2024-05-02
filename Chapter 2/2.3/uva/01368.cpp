#include<iostream>
#include<vector>

using namespace std;

int main(){
    int numCases;
    string s;
    int m, n;
    string order {"ACGT"};
    cin >> numCases;
    while(numCases--){
        cin >> m >> n;
        vector<string> codes {};
        long errors {};
        for(int i=0;i<m;i++){
            cin >> s;
            codes.push_back(s);
        }

        char consensus[1001] {};
        //evaluate per position
        for(int pos=0;pos<n;pos++){
            int counts[4] {};
            for(int i=0;i<m;i++){
                int currOrder = order.find(codes[i].at(pos));
                counts[currOrder]++;
            }

            int maxCount {0};
            for(int i=0;i<4;i++){
                if(counts[i] > maxCount){
                    consensus[pos] = order.at(i);
                    maxCount = counts[i];
                }
            }
            errors += (m-maxCount);
        }
        consensus[n] = '\0';
        cout << consensus << '\n';
        cout << errors << '\n';
    }
}