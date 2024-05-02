#include<cstdio>

using namespace std;

int main(){
    for(long long a=1;a<=2000;++a){
        for(long long b=a;;++b){
            long long subB {a+b};
            if(subB > 2000){
                break;
            }

            for(long long c=b;;++c){
                long long subC {subB+c};
                
                if(subC > 2000){
                    break;
                }

                for(long long d=c;;++d){
                    long long total {subC + d};

                    if(total > 2000){
                        break;
                    }

                    long long product {a*b*c*d};
                    if(product%1000000==0 && (product/1000000 == total)){
                        //printf("%lld %lld\n",total, product);
                        printf("    printf(\"%d.%02d %d.%02d %d.%02d %d.%02d\\n\");\n",a/100,a%100,b/100,b%100,c/100,c%100,d/100,d%100);
                    }
                }
            }
        }
    }
}