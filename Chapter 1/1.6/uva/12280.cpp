#include<iostream>
#include<bitset>
#include<vector>

using namespace std;

int getWeight(char ch){
    int num {ch};

    if (num==0){
        return 0;
    }

    int totalWeight {0};
    bitset<8> bt {bitset<8>(num)};
    for(int i=0;;i++){
        int basis {1 << i};
        if(num < basis){
            break;
        }

        if(bt.test(i)){
            totalWeight+=2;
        } else {
            totalWeight+=1;
        }
    }
    return totalWeight;
}

int getWeight(string s){    
    int ans {};
    for(char ch:s){
        ans += getWeight(ch);
    }
    return ans;
}

void initScale(int pos, char ptr[8][8], string content){
    
    //initialize everything
    for(int row=0;row<7;row++){
        for(int col=0;col<8;col++){
            ptr[row][col] = '.';
        }
    }

    //generate scale
    for(int i=0;i<4;i++){
        ptr[pos+i][3-i] = '/';
        ptr[pos+i][4+i] = '\\';
    }
    ptr[pos+4][0] = '\\';
    ptr[pos+4][7] = '/';
    for(int i=1;i<7;i++){
        ptr[pos+4][i] = '_';
    }

    //add objects
    for(int i=0;i<content.size();i++){
        ptr[pos+3][i+1] = content.at(i);
    }
}

void printScales(char grid1[8][8], char grid2[8][8]){
    for(int row=0;row<7;row++){

        for(int col=0;col<8;col++){
            cout << grid1[row][col];
        }
        cout << "||";
        for(int col=0;col<8;col++){
            cout << grid2[row][col];
        }
        cout << '\n';
    }
}

int main(){
    int nCases {};
    string s;
    cin >> nCases;

    for(int tc=1;tc<=nCases;tc++){
        if(tc==183){
            cout << "" ;
        }
        
        vector<string> rawData {};
        for(int i=0;i<8;i++){
            cin >> s;
            rawData.push_back(s);
        }

        int posLeft {};
        int posRight {};

        while(true){
            if(rawData[posLeft].substr(0,8).find('/') == -1){
                posLeft++;
            } else {
                break;
            }
        }
        posRight = 2 - posLeft;

        
        string contLeft {};
        string contRight {};

        if(contLeft == "ZFXTWL"){
            cout << ' ';
        }

        contLeft = rawData[posLeft+3].substr(1,6);
        contRight = rawData[posRight+3].substr(11,6);
    
        if(contLeft.find('.') != -1){
            contLeft = contLeft.substr(0,contLeft.find('.'));
        }
        
        if(contRight.find('.') != -1){
            contRight = contRight.substr(0,contRight.find('.'));
        }
    
        int wLeft {getWeight(contLeft)};
        int wRight{getWeight(contRight)};

        cout << "Case " << tc << ":\n";
        if ((wLeft > wRight && posLeft > posRight) ||
            (wLeft == wRight && posLeft == posRight) ||
            (wLeft < wRight && posLeft < posRight)){
                cout <<"The figure is correct.\n";
        } else {
            if(wLeft > wRight){
                posLeft = 2;
                posRight = 0;
            } else if (wLeft < wRight){
                posLeft = 0;
                posRight = 2;
            } else {
                posLeft = 1;
                posRight = 1;
            }

            char gridLeft[8][8] {};
            char gridRight[8][8] {};

            initScale(posLeft,gridLeft,contLeft);
            initScale(posRight,gridRight,contRight);
            printScales(gridLeft,gridRight);
        }
    
    }
}