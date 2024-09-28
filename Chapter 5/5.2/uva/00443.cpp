#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

string getSuffix(int num){
    int part {num % 100};

    if(part >= 10 && part <= 20){
        return "th";
    }

    part%=10;
    switch(part){
        case 1:
            return "st";
        case 2:
            return "nd";
        case 3:
            return "rd";
        default:
            return "th";
    }
}

int main(){
    vector<long long> values {};
    int factors[4] {2,3,5,7};
    priority_queue<long long,vector<long long>,greater<long long>> q {};

    q.push(1);

    values.reserve(5842);
    long long prev {-1};
    while(values.size() < 5842){
        long long curr = q.top();
        q.pop();

        if(curr == prev) continue;

        values.push_back(curr);
        for(int factor: factors){
            long long nxt {curr*factor};
            if(nxt > 0){
                q.push(nxt);
            }
        }

        prev = curr;
    }

    int pos;
    while(cin >> pos, pos > 0){
        cout << "The " << pos << getSuffix(pos) << " humble number is " << values[pos-1] << ".\n";
    } 
}