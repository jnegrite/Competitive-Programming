#include<iostream>
#include<queue>
#include<stack>

using namespace std;

deque<long> front {};
deque<long> back {};
long totalSize {};

void rebalance(){
    while(front.size() >= back.size()+2){
        back.push_front(front.back());
        front.pop_back();
    }

    while(back.size() > front.size()){
        front.push_back(back.front());
        back.pop_front();
    }
}

int main(){
    string s;
    long val;
    long numCommands{};
    cin >> numCommands;
    front.clear();
    back.clear();

    while(numCommands-- > 0){
        cin >> s >> val;
        if(s == "push_back"){
            back.push_back(val);
            totalSize++;
        } else if(s == "push_front"){
            front.push_front(val);
            totalSize++;
        } else if(s == "push_middle"){
            rebalance();
            if(totalSize%2==1){
                back.push_front(val);
            } else {
                front.push_back(val);
            }
            totalSize++;
        } else {
            //get function;
            long offset {};
            deque<long> *ref;

            if(val >= front.size()){
                offset = front.size();
                ref = &back;
            } else {
                offset = 0;
                ref = &front;
            }

            cout << (*ref)[val-offset] << '\n';
        }
    }
}