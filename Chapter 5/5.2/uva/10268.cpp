#include<iostream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;
using tp = long long;

int main(){
    string s;
    tp val, temp;    
    while(getline(cin,s)){
        val = stoll(s);
        getline(cin,s);
        auto strIn {stringstream(s)};
        stack<tp> st {};

        while(strIn >> temp){
            st.push(temp);
        }

        st.pop();
        tp currFactor {1LL};
        tp currDegree {1LL};

        tp ans {0};
        while(!st.empty()){
            ans += st.top() * currDegree * currFactor;
            ++currDegree;
            currFactor*=val;
            st.pop();
        }

        cout << ans << '\n';
    }
}