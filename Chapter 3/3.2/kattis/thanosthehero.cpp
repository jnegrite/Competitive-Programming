#include<iostream>
#include<stack>

using namespace std;

int main(){
    bool possible {true};
    stack<long> populations {};
    long nWorlds;
    cin >> nWorlds;
    long curr;

    while(nWorlds--){
        cin >> curr;
        populations.push(curr);
    }

    //simulate moving back
    long prev = populations.top();
    populations.pop();
    long killed {};
    while(possible && !populations.empty()){
        curr = populations.top();
        populations.pop();

        //kill only if curr is higher
        if(curr >= prev){
            killed += (curr - (prev-1));
            prev--;
        } else {
            prev = curr;
        }

        if(prev < 0){
            possible = false;
        }
    }

    if(!possible){
        killed = 1;
    }

    cout << killed << '\n';
}