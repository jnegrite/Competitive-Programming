#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

long long combinations[14][14] {};

int numbers[13] {};

int main(){

    for(int size=1;size<=13;size++){
        //clear up answers
        for(int i=1;i<=size;i++){
            for(int j=1;j<=size;j++){
                combinations[i][j] = 0;
            }
        }

        for(int i=0;i<size;i++){
            numbers[i] = i;
        }

        do{
            int cntFront {};
            int cntBack {};

            int curr {-1};
            for(int i=0;i<size;++i){
                if(numbers[i] > curr){
                    curr = numbers[i];
                    ++cntFront;
                }
            }

            curr = -1;
            for(int i=size-1;i>=0;--i){
                if(numbers[i] > curr){
                    curr = numbers[i];
                    ++cntBack;
                }
            }

            ++combinations[cntFront][cntBack];
        } while(next_permutation(numbers,numbers+size));

        int baseN {size << 8};
        for(int row=1;row<=size;++row){
            int baseRow {row<<4};
            for(int col=row;col<=size;++col){
                if(combinations[row][col] != 0){
                    cout << '{' << (baseN|baseRow|col) << ',' << combinations[row][col] << "}," << endl;
                }
            }
        }
    }
}