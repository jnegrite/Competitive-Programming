#include<iostream>
#include<unordered_map>
#include<set>

using namespace std;

long catNum{0};

struct Cat{
    string name {};
    long infectionLevel {};
    long order {};

    Cat(){}
    Cat(string _name, long _infection){
        name = _name;
        infectionLevel = _infection;
        order = ++catNum;
    }

    const bool operator<(const Cat& o) const {
        if(infectionLevel != o.infectionLevel){
            return infectionLevel > o.infectionLevel;
        } else {
            return order < o.order;
        }
    }
};

int main(){
    unordered_map<string,Cat> cats {};
    set<Cat> catsQueue {};
    long nCommands;
    int code;
    string name;
    long infectionLevel;
    cin >> nCommands;

    for(long cmd=0;cmd<nCommands;cmd++){
        cin >> code;
        //cout << cmd << "==>" << code << '\n';
        Cat curr;
        set<Cat>::iterator ptr;
        switch(code){
            case 0:
                cin >> name >> infectionLevel;
                curr = Cat(name,infectionLevel);
                cats[name] = curr;
                catsQueue.emplace(curr);
                break;
            case 1:
                cin >> name >> infectionLevel;
                curr = cats[name];
                ptr = catsQueue.find(curr);
                catsQueue.erase(ptr);
                curr.infectionLevel += infectionLevel;
                cats[name] = curr;
                catsQueue.emplace(curr);
                break;
            case 2:
                cin >> name;
                curr = cats[name];
                catsQueue.erase(catsQueue.find(curr));
                cats.erase(name);
                break;
            case 3:
                if(catsQueue.empty()){
                    cout << "The clinic is empty\n";
                } else {
                    cout << catsQueue.begin()->name << '\n';
                }
                break;
        }
    }
}