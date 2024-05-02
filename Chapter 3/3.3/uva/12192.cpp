#include<cstdio>
#include<cmath>

using namespace std;

int rows, cols;
long lowerBound, upperBound;

long grid[500][500] {};


bool testValue(int size){
    for(int row=0;row+size<=rows;row++){
        int low {0};
        int high {cols-size};
        int mid;

        while(low<high){
            mid = (low+high)>>1;
            if(grid[row][mid] < lowerBound){
                low = mid+1;
            } else {
                high = mid;
            }
        }

        if(grid[row][low] >= lowerBound && grid[row+size-1][low+size-1] <= upperBound){
            return true;
        }
    }
    return false;
}

int main(){
    while(scanf("%d %d\n", &rows, &cols),rows != 0 || cols != 0){
        for(int row=0;row<rows;++row){
            for(int col=0;col<cols;++col){
                scanf("%ld",&grid[row][col]);
            }
        }

        long nQueries;
        scanf("%ld\n",&nQueries);

        while(nQueries--){
            scanf("%ld %ld\n",&lowerBound, &upperBound);

            int low {0};
            int high {rows<cols?rows:cols};

            while(low<high){
                int mid {(low+high+1)>>1};
                if(testValue(mid)){
                    low = mid;
                } else {
                    high = mid-1;
                }
            }
            printf("%d\n",low);
        }
        printf("-\n");
    }
}