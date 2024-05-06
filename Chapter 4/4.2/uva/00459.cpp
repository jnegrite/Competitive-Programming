#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> p {};
int encode(char ch){
    return ch - 'A';
}

int getParent(int i){
    return i==p[i]? i : (p[i] = getParent(p[i]));
}

int main(){
    int nCases;
    cin >> nCases >> ws;
    string s;
    while(nCases--){
        getline(cin,s);
        int nPoints {encode(s.at(0))+1};
        int cc {nPoints};

        p.assign(nPoints,0);
        for(int i=0;i<nPoints;++i){
            p[i] = i;
        }

        //process
        while(getline(cin,s),s.length()!=0){
            int v1 {getParent(encode(s.at(0)))};
            int v2 {getParent(encode(s.at(1)))};

            if(v1 != v2){
                p[v2] = v1;
                --cc;
            }
        }

        if(nCases){
            printf("%d\n\n",cc);
        } else {
            printf("%d\n",cc);
        }
    }
}