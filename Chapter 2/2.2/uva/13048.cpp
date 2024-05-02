#include<iostream>

using namespace std;

int main(){
    int numCases;
    cin >> numCases;
    string s;

    for(int tc=1;tc<=numCases;tc++){
        bool hasIssues[50] {};
        cin >> s;
        int from, to;

        for(int pos=0;pos<s.length();pos++){
            switch(s.at(pos)){
                case 'D':
                    from = 0;
                    to = 0;
                    break;
                case 'B':
                    from = -2;
                    to = 0;
                    break;
                case 'S':
                    from = -1;
                    to = 1;
                    break;
                default:
                    from = -1;
                    to = -1;
            }

            if(from==-1 && to==-1){
                continue;
            }

            for(int i=max(0,pos+from);i<=min(static_cast<int>(s.length())-1,pos+to);i++){
                hasIssues[i] = true;
            }
        }

        int ans {0};
        for(int i=0;i<s.length();i++){
            if(!hasIssues[i]){
                ++ans;
            }
        }

        cout << "Case " << tc << ": " << ans << '\n';
    }
}