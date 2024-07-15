#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<string>
#include<cstring>

using namespace std;

int dist[500][500] {};
int p[500][500] {};

vector<string> files {};
unordered_map<string,int> mapFiles {};
vector<int> loopParents {};

int getId(string s){
    return mapFiles[s];
}

void processParent(int from, int to){
    int mid = p[from][to];

    if(from==mid){
        loopParents.push_back(from);
    } else {
        processParent(from, mid);
        processParent(mid,to);
    }
}

int main(){
    string s, sMain;
    getline(cin, s);
    int nFiles {stoi(s)};
    getline(cin, sMain);
    auto strIn {stringstream(sMain)};
    files.reserve(nFiles);
    
    while(strIn >> s){
        mapFiles[s] = files.size();
        files.push_back(s);
    }

    memset(dist,-1,sizeof(dist));
    memset(p,-1,sizeof(p));

    for(int i=0;i<nFiles;i++){
        int nReps;
        getline(cin, sMain);
        auto strIn {stringstream(sMain)};
        strIn >> s>> nReps;
        int idCurr {getId(s)};

        while(nReps--){
            getline(cin,sMain);
            strIn = stringstream(sMain);

            strIn >> s;
            //get data points
            vector<int> importedFiles {};
            while(strIn >> s){
                if(s.at(s.length()-1) == ','){
                    s = s.substr(0,s.length()-1);
                }
                importedFiles.push_back(getId(s));
            }

            for(auto imp: importedFiles){
                if(imp==idCurr){
                    dist[idCurr][idCurr] = 0;
                } else {
                    dist[idCurr][imp] = 1;
                }
                p[idCurr][imp] = idCurr;
            }
        }
    }

    //do algorithm
    for(int k=0;k<nFiles;k++){
        for(int i=0;i<nFiles;i++){
            if(dist[i][k] == -1) continue;
            for(int j=0;j<nFiles;j++){
                if(dist[k][j] == -1) continue;

                int tempDist {dist[i][k] + dist[k][j]};

                if(dist[i][j] == -1 || (dist[i][j] > tempDist)){
                    dist[i][j] = tempDist;
                    p[i][j] = k;
                }
            }
        }
    }

    //find best loop
    int smallestLoop {-1};
    int loopLoc {-1};

    for(int i=0;i<nFiles;i++){
        if(dist[i][i] == -1) continue;

        if(smallestLoop==-1 || (dist[i][i] < smallestLoop)){
            smallestLoop = dist[i][i];
            loopLoc = i;
        }
    }

    if(smallestLoop==-1){
        cout << "SHIP IT";
    } else if(smallestLoop==0){
        cout << files[loopLoc];
    } else {
        int mid {p[loopLoc][loopLoc]};
        processParent(loopLoc,mid);
        processParent(mid,loopLoc);

        cout << files[loopParents[0]];
        for(int i=1;i<loopParents.size();i++){
            cout << ' ' << files[loopParents[i]];
        }
    }
    cout << '\n';
}