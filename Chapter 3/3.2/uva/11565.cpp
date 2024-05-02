#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    int nCases;
    scanf("%d\n",&nCases);

    long a, b, c, z;
    while(nCases--){
        scanf("%ld %ld %ld\n", &a, &b, &c);
        bool ansFound {false};
        for(int x=-22;!ansFound && x<=22;x++){
            long tempC = x*x;
            if(x*x > c){
                if(x>0){
                    break;
                } else {
                    continue;
                }
            }

            for(int y=-100;!ansFound && y<=100;y++){
                
                if(tempC + y*y > b){
                    if(y>0){
                        break;
                    } else {
                        continue;
                    }
                }
                
                int z = a - x - y;
                
                if(x==y || x==z || y==z){
                    continue;
                }

                if(x*y*z == b && x*x + y*y + z*z == c){
                    ansFound = true;
                    printf("%d %d %d\n",x,y,z);
                }
            }
        }

        if(!ansFound){
            printf("No solution.\n");
        }
    }
}