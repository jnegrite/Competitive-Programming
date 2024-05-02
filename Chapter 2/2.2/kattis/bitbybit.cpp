#include<iostream>

using namespace std;

unsigned long isSeen {0};
unsigned long value {0};

void set(int pos, bool isActive){
    unsigned long mask {1ul<<pos};
    if(isActive){
        value |= mask;
    } else {
        value &= (~mask);
    }
}

bool posSeen(int pos){
    return (isSeen & (1<<pos)) != 0;
}

bool posOn(int pos){
    return (value & (1<<pos)) != 0;
}

int main(){
    string s;
    int a, b, numCmd;
    while(cin>>numCmd,numCmd>0){
        isSeen = 0;
        value = 0;
        for(int i=0;i<numCmd;i++){
            cin >> s;
            if(s=="CLEAR"){
                cin >> a;
                set(a,false);
                isSeen |= (1<<a);
            } else if(s=="SET"){
                cin >> a;
                set(a,true);
                isSeen |= (1<<a);
            } else if (s=="OR"){
                cin >> a >> b;
                bool seenA {posSeen(a)};
                bool seenB {posSeen(b)};
                bool onA {posOn(a)};
                bool onB {posOn(b)};

                if(seenA && seenB){
                    set(a,posOn(a) || posOn(b));
                } else if (seenB && onB){
                    set(a,true);
                    isSeen |= (1<<a);
                } else if ((seenA && !onA) || (seenB && !onB)){
                    set(a,false);
                    isSeen &= (~(1<<a));
                }
            } else if (s=="AND"){
                cin >> a >> b;
                bool seenA {posSeen(a)};
                bool seenB {posSeen(b)};
                bool onA {posOn(a)};
                bool onB {posOn(b)};

                if(seenA && seenB){
                    set(a,posOn(a) && posOn(b));
                } else if (seenB && !onB){
                    set(a,false);
                    isSeen |= (1<<a);
                } else if ((seenA && onA) || (seenB && onB)){
                    set(a,false);
                    isSeen &= (~(1<<a));
                }
            }
        }

        unsigned long mask {1ul<<31};
        while(mask != 0){
            if(mask & isSeen){
                if(mask & value){
                    cout << 1;
                } else {
                    cout << 0;
                }
            } else {
                cout << '?';
            }
            mask >>= 1;
        }
        cout << '\n';
    }
}