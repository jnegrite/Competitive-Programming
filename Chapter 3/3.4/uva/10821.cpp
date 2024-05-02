#include<iostream>

using namespace std;

void process(int from, int to, int h){
    if(from == to){
        cout << ' ' << from;
    } else {
        int root {max(from,to-((1<<h)-1))};

        cout << ' ' << root;

        if(from != root){
            process(from,root-1,h-1);
        }

        if(to!=root){
            process(root+1,to,h-1);
        }
    } 
}

int main(){
    int n, h;
    int tc{};
    while(cin >> n >> h, n!=0 && h !=0){
        cout << "Case " << ++tc << ':';
        if(n >= (1<<h)){
            cout << " Impossible.\n";
        } else {
            process(1,n,h-1);
            cout << '\n';
        }
    }
}