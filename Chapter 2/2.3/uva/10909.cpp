#include <bits/stdc++.h>
using namespace std;
#include <bits/extc++.h> // pbds
#include<malloc.h>

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, splay_tree_tag,
tree_order_statistics_node_update> ost;

int main() {
    int n = 2000000;
    
    ost tree;
    for (int i = 1; i <= n; i+=2) // O(n log n)
        tree.insert(i);

    int currPos {1};
    //process tree
    auto it {++tree.begin()};
    while(true){
        int currD {*it};
        
        if(currD >= tree.size()){
            break;
        }
        currD--;
        
        for(int i {currD}; i< tree.size(); i+=currD){
            tree.erase(tree.find_by_order(i));
        }
    
        ++it;
    }
    
    bool isLucky[n] {};
    for(auto it {tree.begin()};it!=tree.end();++it){
        isLucky[*it]=true;
    }
    
    int* dp = (int*)calloc(n+1,sizeof(int));
    
    
    int val;
    while (cin >> val) {
		if (val & 1) {
			cout << val << " is not the sum of two luckies!\n";
		} else {
		    if(dp[val] == 0){
		        dp[val] = -1;
		        
		        for(int i=val/2;i>=1;--i){
		            if(isLucky[i] && isLucky[val-i]){
		                dp[val] = i;
		                break;
		            }
		        }
		    }
		    
            if(dp[val]==-1){
                cout << val << " is not the sum of two luckies!\n";
            } else {
		        cout << val << " is the sum of " << dp[val] << " and " << val-dp[val] << ".\n";
            }
		}
	}
	cout << flush;
}