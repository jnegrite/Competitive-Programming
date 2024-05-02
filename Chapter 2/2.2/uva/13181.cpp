#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        long maxDist = 0;
        long pos {-1};

        long firstLoc {s.find('X')};
        long prev{firstLoc};
        
        while(true){        
            pos = s.find('X',prev+1);
            if(pos == -1){
                break;
            }
            maxDist = max(maxDist,(pos - prev-2)>>1);
            prev = pos;
        }

        maxDist = max(maxDist,firstLoc-1);
        maxDist = max(maxDist,static_cast<long>(s.length())-2 - prev);

        printf("%ld\n",maxDist);
    }
}