#include<iostream>

using namespace std;

struct Ant{
    int length;
    int width;
    int height;
    long volume;

    bool operator<(Ant o){
        if (height!=o.height){
            return height > o.height;
        } else {
            return volume > o.volume;
        }
    }

    Ant(int _length, int _width, int _height){
        length = _length;
        width = _width;
        height = _height;
        volume = length * width * height;
    }
};

int main(){
    int numAnts;
    int l, w, h;
    while(true){
        cin >> numAnts;

        if(numAnts==0){
            break;
        }

        //first ant
        cin >> l >> w >> h;
        Ant ans {l,w,h};
        for(int i=1;i<numAnts;i++){
            cin >> l >> w >> h;
            Ant curr {l,w,h};
            if (curr < ans){
                ans = curr;
            }
        }
        cout << ans.volume << '\n';
    }
}