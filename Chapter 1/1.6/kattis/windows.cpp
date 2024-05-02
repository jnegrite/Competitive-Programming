#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<string>

using namespace std;

long long xMax;
long long yMax;
string cmd; 
int windowNum {};

struct Window {
    int windowNum {};
    long long xFrom {};
    long long xTo {};
    long long yFrom {};
    long long yTo {};

    Window(){}
    Window(Window* o){
        windowNum = o->windowNum;
        xFrom = o->xFrom;
        xTo = o->xTo;
        yFrom = o->yFrom;
        yTo = o->yTo;
    }

    Window(int _windowNum, long long _xFrom, long long _xTo, long long _yFrom, long long _yTo){
        windowNum = _windowNum;
        xFrom = _xFrom;
        xTo = _xTo;
        yFrom = _yFrom;
        yTo = _yTo;
    }

    Window(long long _xFrom, long long _xTo, long long _yFrom, long long _yTo){
        xFrom = _xFrom;
        xTo = _xTo;
        yFrom = _yFrom;
        yTo = _yTo;
    }

    bool operator==(Window o){
        return xFrom == o.xFrom && xTo == o.xTo && yFrom == o.yFrom && yTo == o.yTo;
    }

    bool overlaps(Window o){
        if(xFrom > o.xTo || xTo < o.xFrom || yFrom > o.yTo || yTo < o.yFrom){
            return false;
        }

        return ((xFrom <= o.xTo || xTo >= o.xFrom) && (yFrom <= o.yTo || yTo >= o.yFrom));
    }

    bool isOutOfBounds();
    bool hasOverlaps();
    set<int> getOverlaps();
    long long getMaxPosMove(long long, long long);
    void move(long long, long long);
};

map<int, Window> windows {};
map<int,long long> dp {};

bool Window::isOutOfBounds(){
    return xFrom < 0 || xTo >= xMax || yFrom < 0 || yTo >= yMax;
}

bool Window::hasOverlaps(){
    for(auto au: windows){
        Window o {au.second};
        if (windowNum != o.windowNum && this->overlaps(o)){
            return true;
        }
    }
    return false;
}

set<int> Window::getOverlaps(){
    set<int> ans {};
    for(auto o: windows){
        if (this->overlaps(o.second)){
            ans.emplace(o.first);
        }
    }
    return ans;
}

long long Window::getMaxPosMove(long long dx, long long dy){

    auto it {dp.find(windowNum)};
    if( it != dp.end()){
        return it->second;
    }

    long long ans {};

    if(dx > 0){
        //move to the right

        if(xTo != xMax-1){
            Window checker {xTo+1,min(xTo+dx,xMax-1),yFrom,yTo};
            set<int> overlaps = checker.getOverlaps();

            if(overlaps.size() == 0){
                ans = min(xTo+dx,xMax-1) - xTo;
            } else {
            
                long long border {xMax-1}; 
                for(auto temp: overlaps){
                    border = min(border,windows[temp].xFrom -1  + windows[temp].getMaxPosMove((xTo + dx) - windows[temp].xFrom+1,0));
                }
                ans = border - xTo;
            }
        }
    } else if (dx < 0){
        //move to the left
        if(xFrom != 0){
            Window checker {max(0ll,xFrom+dx),xFrom-1,yFrom, yTo};
            set<int> overlaps = checker.getOverlaps();

            if(overlaps.size() == 0){
                ans = max(0ll,xFrom+dx)-xFrom;
            } else {
                long long border {0};
                for(auto temp: overlaps){
                    border = max(border, windows[temp].xTo + windows[temp].getMaxPosMove((xFrom + dx) - windows[temp].xTo - 1,0)+1);
                }

                ans = border - xFrom;
            }
        }
    } else if (dy > 0){
        //move down

        if(yTo != yMax-1){
                
            Window checker {xFrom,xTo,yTo+1,min(yTo+dy,yMax-1)};
            set<int> overlaps = checker.getOverlaps();

            if(overlaps.size() == 0){
                ans = min(yTo+dy,yMax-1) - yTo;
            } else { 
                long long border {yMax-1};
                for(auto temp: overlaps){
                    border = min(border,windows[temp].yFrom - 1 + windows[temp].getMaxPosMove(0,(yTo + dy) - windows[temp].yFrom+1));
                }

                ans= border - yTo;
            }
        }
    } else if (dy < 0) {
        //move up

        if(yFrom != 0){
            Window checker {xFrom, xTo, max(0ll,yFrom+dy), yFrom-1};
            set<int> overlaps = checker.getOverlaps();

            if(overlaps.size() == 0){
                ans = max(0ll,yFrom+dy) - yFrom;
            } else {

                long long border {0};
                for(auto temp: overlaps){
                    border = max(border, windows[temp].yTo + windows[temp].getMaxPosMove(0,(yFrom + dy ) - windows[temp].yTo-1)+1);
                }

                ans = border - yFrom;
            }
        }
    }

    dp[windowNum] = ans;
    return ans;
}

void Window::move(long long dx, long long dy){
    if(dx == 0 && dy == 0){
        return;
    }
    if(dx > 0){
        Window checker {xTo+1,xTo+dx,yFrom,yTo};
        set<int> overlaps = checker.getOverlaps();
        long long border {xTo + dx};

        bool didUpdate{true};
        while(didUpdate){
            didUpdate = false;
            overlaps = checker.getOverlaps();
            for(auto w: overlaps){
                if(windows[w].xFrom <= border){
                    windows[w].move(dx - (windows[w].xFrom - xTo) + 1,0);
                    didUpdate = true;
                }
            }
        }
    } else if(dx < 0){
        Window checker {xFrom+dx,xFrom-1,yFrom, yTo};
        set<int> overlaps = checker.getOverlaps();
        long long border {xFrom + dx};

        bool didUpdate{true};
        while(didUpdate){
            didUpdate = false;
            overlaps = checker.getOverlaps();
            for(auto w: overlaps){
                if(windows[w].xTo >=border){
                    windows[w].move(dx - (windows[w].xTo - xFrom) - 1,0);
                }
            }
        }
    } else if (dy > 0){
        Window checker {xFrom,xTo,yTo+1,yTo+dy};
        set<int> overlaps = checker.getOverlaps();
        
        long long border {yTo + dy};

        bool didUpdate{true};
        while(didUpdate){
            didUpdate = false;
            overlaps = checker.getOverlaps();
            for(auto w: overlaps){
                if(windows[w].yFrom <= border){
                    windows[w].move(0,dy-(windows[w].yFrom - yTo)+1);
                    didUpdate = true;
                }
            }
        }
    } else if (dy < 0){
        Window checker {xFrom, xTo, yFrom+dy, yFrom-1};
        set<int> overlaps = checker.getOverlaps();
        long long border {yFrom + dy};

        bool didUpdate{true};
        while(didUpdate){
            didUpdate = false;
            overlaps = checker.getOverlaps();
            for(auto w: overlaps){
                if(windows[w].yTo >= border){
                    windows[w].move(0,dy - (windows[w].yTo - yFrom) - 1);
                }
            }
        }
    }

    Window cp {windowNum,xFrom+dx,xTo+dx, yFrom+dy, yTo+dy};
    windows[windowNum] = cp;
}


int searchPixel(long long x, long long y){

    Window selector {x,x,y,y};

    for(auto curr: windows){
        if(selector.overlaps(curr.second)){
            return curr.first;
        }
    }

    return -1;
}

int main(){

    //get dimensions
    cin >> xMax >> yMax;

    long long cmdNum{};
    while(cin >> cmd){
        long long xFrom, yFrom, width, height, dx, dy;
        
        cmdNum++;
        if (cmd == "OPEN"){
            cin >> xFrom >> yFrom >> width >> height;

            Window curr {xFrom, xFrom + width-1, yFrom, yFrom + height -1};
            if (curr.isOutOfBounds() || curr.hasOverlaps()){
                cout << "Command " << cmdNum << ": OPEN - window does not fit\n";
            } else {
                curr.windowNum = ++windowNum;
                //cout << "\tOPENED " << curr.toString();
                windows[curr.windowNum] = curr;
            }
            //printMap();
        } else if (cmd == "RESIZE"){
            cin >> xFrom >> yFrom >> width >> height;
            int matchId {searchPixel(xFrom,yFrom)};

            if(matchId == -1){
                cout << "Command " << cmdNum << ": RESIZE - no window at given position\n";
            } else {
                Window match {windows[matchId]};
                Window temp {match.windowNum,match.xFrom, match.xFrom + width-1 , match.yFrom, match.yFrom + height - 1};

                if(temp.isOutOfBounds() || temp.hasOverlaps()){
                    cout << "Command " << cmdNum << ": RESIZE - window does not fit\n";
                } else {
                    windows[temp.windowNum] = temp;
                }
            }
        } else if (cmd == "CLOSE"){
            cin >> xFrom >> yFrom;
            int matchId {searchPixel(xFrom,yFrom)};

            if(matchId == -1){
                cout << "Command " << cmdNum << ": CLOSE - no window at given position\n";
            } else {
                windows.erase(matchId);
            }
        } else if (cmd == "MOVE"){
            cin >> xFrom >> yFrom >> dx >> dy;
            int matchId {searchPixel(xFrom,yFrom)};
            long long target{};
            
            if(matchId == -1){
                cout << "Command " << cmdNum << ": MOVE - no window at given position\n";
            } else {
                dp.clear();
                long long maxMovement {windows[matchId].getMaxPosMove(dx, dy)};
                if(dx != 0){
                    target=dx;
                    dx = maxMovement;
                } else if (dy != 0){
                    target=dy;
                    dy = maxMovement;
                }

                windows[matchId].move(dx,dy);

                if(target != maxMovement){
                    cout << "Command " << cmdNum << ": MOVE - moved " << abs(maxMovement) << " instead of " << abs(target) << '\n';
                }
            }
        }
    }

    cout << windows.size() << " window(s):\n";
    for(auto it: windows){
        auto sd {it.second};
        cout << sd.xFrom << ' ' << sd.yFrom << ' ' << sd.xTo - sd.xFrom + 1 << ' ' << sd.yTo - sd.yFrom + 1 << '\n';
    }

}