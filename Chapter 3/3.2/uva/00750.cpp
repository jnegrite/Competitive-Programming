#include<cstdio>

using namespace std;

int maskRow {};
int maskD1 {};
int maskD2 {};
int solutions {};
int ans[9] {};

void backtrack(int col){
    if(col==9){
        printf("%2d     ",++solutions);
        for(int i=1;i<=8;i++){
            printf(" %d",ans[i]);
        }
        printf("\n");
        return;
    }

    if(ans[col] != 0){
        backtrack(col+1);
    } else {
        for(int row=1;row<=8;row++){
            if((maskRow & (1<<row))==0 && (maskD1 & (1<<(row+col)))== 0 && (maskD2 & (1<<(col-row+8)))==0){
                ans[col] = row;
                maskRow ^= (1<<row);
                maskD1 ^= (1<<(row+col));
                maskD2 ^= (1<<(col-row+8));

                backtrack(col+1);

                maskRow ^= (1<<row);
                maskD1 ^= (1<<(row+col));
                maskD2 ^= (1<<(col-row+8));
                ans[col] = 0;
            }
        }
    }
}

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    int a, b;
    for(int tc=0;tc<nCases;tc++){
        scanf("%d %d\n",&a,&b);
        solutions = 0;

        maskRow = (1<<a);
        maskD1 = (1<<(a+b));
        maskD2 = (1<<(b-a+8));
        
        for(int i=1;i<=8;i++){
            ans[i] = 0;
        }
        ans[b] = a;

        if(tc>0){
            printf("\n");
        }
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(1);
    }
}