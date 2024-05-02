#include <iostream>
#include <string>

using namespace std;


string keys {"cdefgabCDEFGAB"};

int notesPressed[14][10] {
    {0,1,1,1,0,0,1,1,1,1},
    {0,1,1,1,0,0,1,1,1,0},
    {0,1,1,1,0,0,1,1,0,0},
    {0,1,1,1,0,0,1,0,0,0},
    {0,1,1,1,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0},
    {1,1,1,1,0,0,1,1,1,0},
    {1,1,1,1,0,0,1,1,0,0},
    {1,1,1,1,0,0,1,0,0,0},
    {1,1,1,1,0,0,0,0,0,0},
    {1,1,1,0,0,0,0,0,0,0},
    {1,1,0,0,0,0,0,0,0,0},
};

int* getKeys(char ch){
    return notesPressed[keys.find(ch)];
}

int main(){
    int numCases;
    cin >> numCases;
    string notes {};
    getline(cin,notes);
    while(numCases--){
        bool isPressed[10] {};
        int numPressed[10] {};
        
        getline(cin,notes);
        
        for(char ch: notes){
            auto notesNeeded {notesPressed[keys.find(ch)]};
            for(int i=0;i<10;i++){
                if(notesNeeded[i] == 1 && !isPressed[i]){
                    numPressed[i]++;
                }
                isPressed[i] = notesNeeded[i];
            }
        }

        cout << numPressed[0];
        for(int i=1;i<10;i++){
            cout << ' ' << numPressed[i];
        }
        cout << '\n';
    }
}
