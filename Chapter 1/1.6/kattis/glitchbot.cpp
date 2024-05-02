#include<iostream>
#include<vector>

using namespace std;

int dX[4] {0,1,0,-1};
int dY[4] {1,0,-1,0};
vector<string> commandList {
    "Forward", "Left", "Right"
};

struct State{
    int x {0};
    int y {0};
    int dir {0};

    State(){};

    State(int _x, int _y, int _dir){
        x = _x;
        y = _y;
        dir = _dir;
    }

    void mvForward(){
        x += dX[dir];
        y += dY[dir];
    }

    void mvBackward(){
        x -= dX[dir];
        y -= dY[dir];
    }

    void mvLeft(){
        dir+=3;
        dir%=4;
    }

    void mvRight(){
        dir+=1;
        dir%=4;
    }

    bool samePoint(State o){
        return x == o.x && y == o.y;
    };

    State apForward(State nd){
        return State{nd.x+dX[dir],nd.y+dY[dir],nd.dir};
    }

    State apBackward(State nd){
        return State{nd.x-dX[dir],nd.y-dY[dir],nd.dir};
    }

    State pivotLeft(State nd){
        int dfx {nd.x - x};
        int dfy {nd.y - y};
        return State{x - dfy, y + dfx, (dir+3)%4};
    }

    State pivotRight(State nd){
        int dfx {nd.x - x};
        int dfy {nd.y - y};
        return State{x + dfy, y - dfx, (dir+1)%4};
    }
};




int main(){

    State curr {0,0,0};
    
    //get target values
    int tX, tY;
    int nCommands;
    State endState;
    string s;
    cin >> tX >> tY >> nCommands;
    State target(tX, tY, 0);

    //simulate movement
    vector<State> states {};
    vector<string> commands {};
    states.push_back(curr);

    for(int i=0;i<nCommands;i++){
        cin >> s;
        commands.push_back(s);

        if(s == "Forward"){
            curr.mvForward();
        } else if (s == "Left"){
            curr.mvLeft();
        } else if (s == "Right"){
            curr.mvRight();
        } else {
            cout << "ERROR";
        }
        states.push_back(curr);
        
        if(i==nCommands-1){
            endState = curr;
        }
    }

    //test movements
    bool ansFound {false};
    for(int i=0;!ansFound && (i<nCommands);i++){
        s = commands[i];
        State tst {states[i]};
        State posEnd {};

        //undo previous
        if(s == "Forward"){
            tst = tst.apBackward(endState);
        } else if (s == "Left"){
            tst = tst.pivotRight(endState);
        } else if (s == "Right"){
            tst = tst.pivotLeft(endState);
        }
        
        //actual test
        for(string cmd: commandList){
            if(cmd == s){
                continue;
            }

            if (cmd=="Forward") {
                posEnd = states[i].apForward(tst);
            } else if (cmd=="Left") {
                posEnd = states[i].pivotLeft(tst);
            } else if (cmd=="Right"){
                posEnd = states[i].pivotRight(tst);
            }
            
            if(posEnd.samePoint(target)){
                cout << i+1 << ' ' << cmd << '\n';
                ansFound = true;
                break;
            }
        }
    }
}