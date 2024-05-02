#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int nCases;
    int students[300] {};
    cin >> nCases;
    int nTeams;
    int nStudents;
    while(nCases--){
        cin >> nTeams;
        nStudents = 3*nTeams;
        for(int i=0;i<nStudents;i++){
            cin >> students[i];
        }
        sort(students,students+nStudents,greater<int>());

        int ans {};
        nStudents = (nTeams << 1);
        for(int i=1;i<nStudents;i+=2){
            ans += students[i];
        }
        cout << ans << '\n';


    }   

}