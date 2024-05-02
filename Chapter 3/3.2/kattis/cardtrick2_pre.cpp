#include<iostream>
#include<queue>

using namespace std;

int cards[14] {};

int main(){
    int curr;
    for(int cardsUsed=1;cardsUsed<=13;++cardsUsed){
        queue<int> q {};

        for(int i=1;i<=cardsUsed;++i){
            q.push(i);
        }

        //simulate
        for(int i=1;i<=cardsUsed;++i){
            
            //movement
            for(int j=1;j<=i;++j){
                q.push(q.front());
                q.pop();
            }

            //draw
            curr = q.front();
            q.pop();
            cards[curr] = i;
        }

        //printing out 
        cout << '\"' << cards[1];
        for(int i=2;i<=cardsUsed;i++){
            cout << ' ' << cards[i];
        }
        cout << "\"," << endl;
    }
}