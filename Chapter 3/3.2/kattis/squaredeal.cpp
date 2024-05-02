#include<cstdio>
#include<algorithm>

using namespace std;

int boxes[3][2] {};
int dims[2][2] {};

bool backtrack(int pos){
    if(pos==3){
        //all in first col
        if(dims[1][0] == 0 && dims[0][0] == dims[0][1]){
            return true;
        }

        if(dims[0][1] == dims[1][1] && dims[0][1] == (dims[0][0] + dims[1][0])){
            return true;
        }

        return false;
    }

    int maxConfig {pos==0?1:2};

    for(int col=0;col<maxConfig;++col){
        int width, height;

        int prevWidth {dims[col][0]};
        int prevHeight {dims[col][1]};

        width = boxes[pos][0];
        height = boxes[pos][1];

        for(int config=0;config<2;config++){
                
            if(dims[col][0] == 0 || width == dims[col][0]){
                dims[col][0] = width;
                dims[col][1] += height;

                if(backtrack(pos+1)){
                    return true;
                }

                dims[col][0] = prevWidth;
                dims[col][1] = prevHeight;
            }
            swap(width,height);
        }
    }

    return false;
}


int main(){
    //get data
    for(int row=0;row<3;++row){
        for(int col=0;col<2;++col){
            scanf("%d",&boxes[row][col]);
        }
    }

    if(backtrack(0)){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}