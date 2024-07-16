#include<iostream>

using namespace std;

int nLocs;

long long locs[102][2] {};

bool areNeighbors(int i, int j){
    long long dist {0};
    for(int k=0;k<2;k++){
        dist += abs(locs[i][k] - locs[j][k]);
    }

    return dist <= 1000LL; 
}

class UFDS{
private:
    int size;
    int p[102] {};

    int getParent(int i){
        return (p[i]==i) ? i : (p[i] = getParent(p[i]));
    }

public:
    UFDS(int _size){
        size=_size;
        for(int i=0;i<size;i++){
            p[i] = i;
        }
    }

    bool sameSet(int i, int j){
        return getParent(i) == getParent(j);
    }

    void join(int i, int j){
        int p1 {getParent(i)};
        int p2 {getParent(j)};

        p[p2] = p1;
    }
};

int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        cin >> nLocs;
        nLocs+=2;

        UFDS u {nLocs};

        for(int i=0;i<nLocs;i++){
            cin >> locs[i][0] >> locs[i][1];
        }

        for(int i=0;i<nLocs;i++){
            for(int j=i+1;j<nLocs;j++){
                if(!u.sameSet(i,j) && areNeighbors(i,j)){
                    u.join(i,j);
                }
            }
        }

        if (u.sameSet(0,nLocs-1)){
            cout << "happy\n";
        } else {
            cout << "sad\n";
        }
    }
}