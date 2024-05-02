#include<iostream>
#include<vector>

using namespace std;

struct Box{
    double x1 {};
    double y1 {};
    double x2 {};
    double y2 {};
    string size {};
};

struct Peanut {
    double x {};
    double y {};
    string size {};

    bool isIn(Box b){
        return b.x1 <= x && x <= b.x2 && b.y1 <= y && y <= b.y2;
    }
};

int main(){
    bool firstTC {true};

    double nBoxes, nPeanuts;
    while(true){
        cin >> nBoxes;
        
        if(nBoxes == 0){
            break;
        }

        //get boxes
        vector<Box> boxes{};
        while(nBoxes--){
            Box bx {};
            cin >> bx.x1 >> bx.y1 >> bx.x2 >> bx.y2 >> bx.size;
            boxes.push_back(bx);
        }

        if(firstTC){
            firstTC = false;
        } else {
            cout << '\n';
        }

        cin >> nPeanuts;
        while(nPeanuts--){
            Peanut p {};
            cin >> p.x >> p.y >> p.size;
            Box *container {nullptr};

            for(Box bx: boxes){
                if(p.isIn(bx)){
                    container = &bx;
                    break;
                }
            }

            cout << p.size << ' ';
            if(container == nullptr){
                cout << "floor";
            } else if (container->size == p.size){
                cout << "correct";
            } else {
                cout << container->size;
            }
            cout << '\n';
        }

    }
}