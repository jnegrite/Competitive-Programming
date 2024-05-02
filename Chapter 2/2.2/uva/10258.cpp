#include<iostream>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

struct Submission{

};

struct Team {
    int num {};
    int numSolved {0};
    long penalty {0};
    map<int,int> trials{};
    set<int> solved {};

    Team(){}
    Team(int _num){
        num = _num;
    }

    void submit(int problem, long time, char code){
        
        if(solved.find(problem) != solved.end()){
            return;
        }
        
        switch(code){
            case 'I':
                if(trials.find(problem) == trials.end()){
                    trials[problem] = 1;
                } else {
                    trials[problem]++;
                }
                break;
            case 'C':
                numSolved++;
                solved.emplace(problem);
                penalty += time;
                auto au = trials.find(problem);
                if(au != trials.end()){
                    penalty += (20l * au->second);
                }
            break;
        }
    }
    
    
    bool operator<(const Team o){
        if(numSolved != o.numSolved){
            return numSolved > o.numSolved;
        } else if (penalty != o.penalty){
            return penalty < o.penalty;
        } else {
            return num < o.num;
        }
    }
};

int main(){
    int numCases;
    string s;
    getline(cin,s);
    auto strIn {stringstream(s)};
    strIn >> numCases;
    int team, problem;
    char code;
    long time;
    Team curr;

    getline(cin,s);
    for(int tc=0;tc<numCases;tc++){
        //get input
        map<int,Team> teams {};
    
        while(getline(cin,s)){
            if(s.length() == 0){
                break;
            }
            auto strIn {stringstream(s)};
            strIn >> team >> problem >> time >> code;

            auto au {teams.find(team)};
            if(au == teams.end()){
                curr = Team(team);
            } else {
                curr = au->second;
            }

            curr.submit(problem,time,code);
            teams[team] = curr;
        }

        vector<Team> vTeams {};
        for(auto au:teams){
            vTeams.push_back(au.second);
        }

        sort(vTeams.begin(),vTeams.end());
        
        if(tc > 0){
            cout << '\n';
        }
        for(Team t: vTeams){
            cout << t.num << ' ' << t.numSolved << ' ' << t.penalty  << '\n';
        }


    }
}