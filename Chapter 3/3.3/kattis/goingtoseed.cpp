#include<iostream>

using namespace std;


int main(){
    long low {1};
    long nTrees;
    long high;
    int a, b, c;

    cin >> nTrees;
    high = nTrees;
    while(low < high){

        //case when down to 2/3 trees
        if(high-low <= 2){
            cout << "Q " << low << ' ' << low << ' ' << high << ' ' << high << '\n';
            cout.flush();
            cin >> a >> b;

            if(a==1){
                high = low;
            } else if(b==1){
                low=high;
            } else {
                ++low;
                --high;
            }
        } else {
            long mm {(low + high+2)>>1};
            long m1 {(low + mm+1)>>1};
            long m2 {(mm+high+2)>>1};
            cout << "Q " << low << ' ' << mm-1 << ' ' << m1 << ' ' << m2-1 << '\n';
            cout.flush();
            cin >> a >> b;

            if(a==1 && b==1){
                if(mm-m1==1){
                    low = m1;
                    high = m1;
                } else {
                    low = m1-1;
                    high = mm;
                }
            } else if(a==1){
                if(m1-low==1){
                    high = low;
                } else {
                    low = max(1L, low-1);
                    high = m1;
                }
            } else if(b==1){
                if(m2-mm==1){
                    low=mm;
                    high= mm;
                } else {
                    low = mm-1;
                    high = m2;
                }
            } else {
                if(m2==high){
                    low = high;
                } else {
                    low = m2-1;
                    high = min(nTrees,high+1);
                }
            }
        }
    } 

    cout << "A " << low << '\n';
    cout.flush();
}



