#include<iostream>
#include<string>

using namespace std;

int main(){
    string s1, s2;
    while(cin >> s1){
        cin >> s2;

        int l1 {s1.length()};
        int l2 {s2.length()};
        int ans {l1+l2};
        int minAns {min(l1,l2)};

        //try all configurations
        for(int offset = -l1+1;offset<l2;++offset){

            bool isOk{true};
            int m1{l1+offset};

            for(int i=max(0,offset);isOk && i<min(m1,l2);i++){
                if(s2.at(i) == '2' && s1.at(i-offset)=='2'){
                    isOk = false;
                }
            }

            if(!isOk){
                continue;
            }

            int temp {max(l2,l1+offset) - min(0,offset)};
            
            if(temp<ans){
                ans = temp;
                if(ans==minAns){
                    break;
                }
            } else if(temp > ans){
                break;
            }
        }

        cout << ans << '\n';
    }
}