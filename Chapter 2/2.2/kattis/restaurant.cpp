#include<iostream>

using namespace std;

int main(){
    string s;
    long curr {};
    int numCommands;
    bool firstCase {true};
    while(cin>>numCommands,numCommands>0){
        long piles[2] {0,0};

        if(firstCase){
            firstCase = false;
        } else {
            cout << '\n';
        }

        while(numCommands--){
            cin >> s >> curr;
            if(s == "DROP"){
                cout << "DROP 2 " << curr << '\n';
                piles[1] += curr;
            } else if (s == "TAKE"){
                long maxAvail {min(curr,piles[0])};

                if(maxAvail > 0){
                    cout << "TAKE 1 " << maxAvail << '\n';
                    piles[0] -= maxAvail;
                    curr -= maxAvail;
                }

                if(curr>0){
                    cout << "MOVE 2->1 " << piles[1] << '\n';
                    piles[0] += piles[1];
                    piles[1] = 0;

                    cout << "TAKE 1 " << curr << '\n';
                    piles[0] -= curr;
                }

            }
        }
    }
}