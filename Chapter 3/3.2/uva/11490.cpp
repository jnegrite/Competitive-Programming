#include<cstdio>

using namespace std;

using dt = long long;

//a = width of missing
//b = thickness
// S + 2*a*a = (2a + 3b) * (2b+ a)
// S + 2a^2 == 4ab + 2a^2 + 6b^2 +3ab
// S == 7ab + 6b^2
//(S - 6b^2)/7b
dt modder {100000007};
int main(){
    dt num;
    while(scanf("%lld\n",&num),num!=0){
        dt a;
        dt b {1};
        dt numer;
        bool hasAns {false};
        while(num > 6*b*b){
            numer = num - 6*b*b;
            if(numer%(7*b)==0){
                hasAns = true;
                a = (numer/(7*b))%modder;
                printf("Possible Missing Soldiers = %lld\n",(2*a*a)%modder);
            }
            b++;
        }

        if(!hasAns){
            printf("No Solution Possible\n");
        }
        printf ("\n");
    }
}