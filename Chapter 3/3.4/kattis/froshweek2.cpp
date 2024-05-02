#include<iostream>
#include<algorithm>


using namespace std;

int main(){
    long nTasks, nQuiet;
    long tasks[200000];
    long quiet[200000];

    cin >> nTasks >> nQuiet;
    for(long i=0;i<nTasks;i++){
        cin >> tasks[i];
    }

    for(long i=0;i<nQuiet;i++){
        cin >> quiet[i];
    }

    sort(tasks,tasks+nTasks);
    sort(quiet,quiet+nQuiet);

    long idxTask {nTasks-1};
    long idxQuiet {nQuiet-1};
    long ans {};

    while(idxTask>=0 && idxQuiet >= 0){
        if(tasks[idxTask] <= quiet[idxQuiet]){
            --idxQuiet;
            ++ans;
        }
        --idxTask;
    }
    cout << ans << '\n';
}