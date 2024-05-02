#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main(){
    int numCases;
    string s;
    getline(cin,s);
    numCases = stoi(s);
    while(numCases--){
        int numCosts;
        long totalCost {};
        char ch;
        string s;
        getline(cin,s);


        long costs[256] {};
        for(int i=0;i<256;i++){
            costs[i] = 0;
        }
        numCosts = stoi(s);
        while(numCosts--){
            getline(cin,s);
            int ch {static_cast<int>(s.at(0))};
            long cost {stol(s.substr(2))};
            costs[ch] = cost; 
        }

        getline(cin,s);
        long numRows {stol(s)};
        while(numRows--){
            getline(cin,s);
            for(char ch:s){
                int pos = static_cast<int>(ch);
                if(ch >= 0 && ch <256){
                   totalCost += costs[ch];
                }
            }
        }       
        cout << totalCost/100 << "." << setfill('0') << setw(2) << totalCost%100 << "$\n";
    }
}