#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>

using namespace std;

string s;
unordered_map<long,long> pars {};

pair<long,long> evaluate(long from, long to){
    pair<long,long> ans {0,0};

    bool negate {false};

    long end;
    pair<long,long> temp {};
    for(long i=from;i<=to;++i){
        switch(s.at(i)){
            case '-':
                negate = true;
                break;
            case '(':
                end = pars[i];
                temp = evaluate(i+1,end-1);
                if(negate){
                    swap(temp.first,temp.second);
                }
                ans.first += temp.first;
                ans.second += temp.second;
                i=end;
                negate=false;
                break;
            case 'x':
                if(negate){
                    ans.second++;
                    negate = false;
                } else {
                    ans.first++;
                }
                break;
        }
    }
    //cout << s.substr(from,to+1-from) << '\n';
    //cout << from << ':' << to << " --> " << ans.first << ':' << ans.second << '\n';
    return ans;
}

int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        cin >> s;
        pars.clear();
        
        stack<long> openBrackets {};

        for(long i=0;i<s.length();++i){
            switch(s.at(i)){
                case '(':
                    openBrackets.push(i);
                    break;
                case ')':
                    pars[openBrackets.top()] = i;
                    openBrackets.pop();
                    break;            
            }
        }

        long nValues {};
        long curr;
        cin >> nValues;
        priority_queue<long> vals {};
        
        while(nValues--){
            cin >> curr;
            vals.emplace(curr);
        }

        pair<long,long> stats {evaluate(0,s.length()-1)};
        long ans {0};
        for(long i=0;i<stats.first;i++){
            ans += vals.top();
            vals.pop();
        }

        while(!vals.empty()){
            ans-=vals.top();
            vals.pop();
        }

        cout << ans << '\n';
    }
}

