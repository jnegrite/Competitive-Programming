#include<iostream>

using namespace std;

int main(){
    int n, l, c;
    string s;

    while(cin >> n >> l >> c){
        int nLines {1};
        ++c;
        int currLen{0};
        int wordLen {};
        int tempLen {};
        for(int i=0;i<n;i++){
            cin >> s;
            wordLen = s.length()+1;
            tempLen = currLen + wordLen;
            //check if can still fit in current line
            if(tempLen<= c){
                currLen = tempLen;
            } else {
                ++nLines;
                currLen = wordLen;
            }
        }
        int nPages {nLines/l};
        if(nLines%l != 0){
            ++nPages;
        }
        cout << nPages << '\n';
    }
}
