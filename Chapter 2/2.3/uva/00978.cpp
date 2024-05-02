#include<iostream>
#include<set>
#include<queue>

using namespace std;

int main(){
    int curr;
    int numCases;
    cin >> numCases;

    for(int tc=0;tc<numCases;tc++){
        priority_queue<int> poolGreen {};
        priority_queue<int> poolBlue {};
        queue<int> survivorsGreen {};
        queue<int> survivorsBlue {};

        //get main parameters
        long n, sg, sb;
        cin >> n >> sg >> sb;

        for(long i=0;i<sg;i++){
            cin >> curr;
            poolGreen.emplace(curr);
        }

        for(long i=0;i<sb;i++){
            cin >> curr;
            poolBlue.emplace(curr);
        }

        //simulate the battles
        while(!poolGreen.empty() && !poolBlue.empty()){
            for(long i=0;i<n && !poolGreen.empty() && !poolBlue.empty();i++){
                //do battles
                int valGreen {poolGreen.top()};
                int valBlue {poolBlue.top()};

                poolGreen.pop();
                poolBlue.pop();

                if(valGreen > valBlue){
                    survivorsGreen.emplace(valGreen-valBlue);
                } else if (valBlue > valGreen){
                    survivorsBlue.emplace(valBlue-valGreen);
                }

            }

            //put back into the set
            while(!survivorsGreen.empty()){
                poolGreen.emplace(survivorsGreen.front());
                survivorsGreen.pop();
            }

            while(!survivorsBlue.empty()){
                poolBlue.emplace(survivorsBlue.front());
                survivorsBlue.pop();
            }
        }

        if(tc > 0){
            cout << '\n';
        }

        if(poolGreen.empty() && poolBlue.empty()){
            cout << "green and blue died\n";
        } else if (poolGreen.empty()){
            cout << "blue wins\n";
            while(!poolBlue.empty()) {
                cout << poolBlue.top() << '\n';
                poolBlue.pop();
            }
        } else if (poolBlue.empty()){
            cout << "green wins\n";
            while(!poolGreen.empty()) {
                cout << poolGreen.top() << '\n';
                poolGreen.pop();
            }
        }
    }
}

