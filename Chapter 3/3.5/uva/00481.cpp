#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main(){
    int curr;
    int nValues;
    vector<int> values {};

    //get data
    while(scanf("%d\n",&curr)!=EOF){
        values.push_back(curr);
    }

    vector<int> L{};
    vector<int> L_id{};
    vector<int> p {};

    L.reserve(values.size());
    L_id.reserve(values.size());

    p.assign(values.size(),-1);
    int k {0}, lastIdx{0};

    for(int i=0;i<values.size();i++){
        int pos {distance(L.begin(),lower_bound(L.begin(),L.end(),values[i]))};
        
        if(pos == k){
            L.push_back(values[i]);
            L_id.push_back(i);
            p[i] = pos ? L_id[pos-1] : -1;

            ++k;
            lastIdx = i;
        } else {
            L[pos] = values[i];
            L_id[pos] = i;
            p[i] = pos ? L_id[pos-1] : -1;

            if(pos+1==k){
                lastIdx=i;
            }
        }
    }

    printf("%d\n-\n",k);

    stack<int> finVals {};
    while(lastIdx != -1){
        finVals.push(values[lastIdx]);
        lastIdx = p[lastIdx];
    }

    while(!finVals.empty()){
        printf("%d\n",finVals.top());
        finVals.pop();
    }
}