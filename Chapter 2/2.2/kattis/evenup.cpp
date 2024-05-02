#include<iostream>
#include<stack>

using namespace std;

int main(){
    long numCards;
    cin >> numCards;
    stack<int> cards {};
    int curr;
    for(long i=0;i<numCards;i++){
        cin >> curr;
        if(!cards.empty() && (cards.top()%2 == curr%2)){
            cards.pop();
        } else {
            cards.emplace(curr);
        }
    }
    cout << cards.size() << '\n';
}