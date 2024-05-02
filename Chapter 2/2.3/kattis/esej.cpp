#include<iostream>
#include<vector>

using namespace std;

vector<string> a {};
vector<string> b {};

vector<string> *currSet {&a};
vector<string> *holderSet {&b};
long pos = 0;
long chPos = 0;

void restructure(){
    vector<string> *temp = currSet;
    currSet = holderSet;
    holderSet = temp;
    holderSet->clear();
}

string generateWord() {
    if(pos >= currSet->size()){
        restructure();
        pos = 0;
        chPos = 0;
    }

    string output = (*currSet)[pos] + static_cast<char>('a' + (chPos++));
    holderSet->push_back(output);

    if(chPos == 26){
        chPos = 0;
        pos++;
    }
    return output;
}

int main(){
    long a, b;
    cin >> a >> b;
    a = max(a,b/2 + 1);
    holderSet->push_back("");

    cout << generateWord();
    for(long i=1;i<a;i++){
        cout << ' ' << generateWord();
    }
    cout << '\n';
}