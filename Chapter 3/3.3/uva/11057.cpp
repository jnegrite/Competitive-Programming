#include<iostream>
#include<set>

using namespace std;

int main(){
    long nBooks;

    while(cin >> nBooks){
        set<long> bookPrices {};

        long curr;
        for(long i=0;i<nBooks;i++){
            cin >> curr;
            bookPrices.emplace(curr);
        }

        long budget;
        cin >> budget;

        auto lower {bookPrices.lower_bound(budget>>1)};
        auto upper {lower};

        if(*lower > (budget>>1)){
            --lower;
        } else {
            ++upper;
        }
        
        while(true){
            long comp {*lower + *upper};
            if(comp == budget){
                break;
            } else if(comp > budget){
                --lower;
            } else {
                ++upper;
            }
        }
        
        printf("Peter should buy books whose prices are %d and %d.\n\n",*lower,*upper);
    }
}