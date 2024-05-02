#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,string>> knownStudents {};

int main(){
    int numStudents;
    cin >> numStudents;

    string s;
    for(int i=1;i<=numStudents;i++){
        cin >> s;
        if(s != "?"){
            pair<int,string> temp {i,s};
            knownStudents.push_back(temp);
        }
    }

    //queries
    int numQueries;
    cin >> numQueries;
    int q;

    int firstKnown {knownStudents[0].first};
    int lastKnown {knownStudents[knownStudents.size()-1].first};

    for(int i=0;i<numQueries;i++){
        cin >> q;
        
        //check if before first
        if(q <= firstKnown){
            for(int j=q;j<firstKnown;j++){
                cout << "left of ";
            }
            cout << knownStudents[0].second;
        } else if (q >= lastKnown){
            for(int j=lastKnown;j<q;j++){
                cout << "right of ";
            }
            cout << knownStudents[knownStudents.size()-1].second;
        } else {
            //get between which 2 known

            int pos {0};
            while(knownStudents[pos+1].first <= q){
                pos++;
            }

            //exact match
            if(knownStudents[pos].first == q){
                cout << knownStudents[pos].second;
            } else if(knownStudents[pos+1].first - q == q - knownStudents[pos].first){
                cout << "middle of " << knownStudents[pos].second << " and " << knownStudents[pos+1].second;
            } else if(knownStudents[pos+1].first - q < q - knownStudents[pos].first){
                for(int j=q;j<knownStudents[pos+1].first;j++){
                    cout << "left of ";
                }
                cout << knownStudents[pos+1].second;
            } else {
                for(int j=knownStudents[pos].first;j<q;j++){
                    cout << "right of ";
                }
                cout << knownStudents[pos].second;
            }
        }
        cout << '\n';
    }
}