#include <cstdio>
#include<bits/stdc++.h>

using namespace std;

#include<bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<long,null_type,less<long>,rb_tree_tag,
    tree_order_statistics_node_update> ost;
    
int main() {
    ost numbers {};
    
    printf("Starting\n");
    long i {0};

    while(i<2000000){
        for(int iter=0;iter<2;iter++,i+=2){
            numbers.insert(i);
        }
        i+=2;
    }
    long idx {2};
    
    long div = *tree.find_by_order(idx);
    while(div <= numbers.size()){
        printf("Divisor is %d\n",div)
        long curr = div * (numbers.size()/div) - 1;
        while(curr >= 0){
            numbers.erase(tree.find_by_order(curr));
            curr -= div;
        }
        div = *tree.find_by_order(++idx);
    }
    printf("Done");
}