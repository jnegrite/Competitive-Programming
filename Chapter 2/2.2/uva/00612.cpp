#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;

struct Word{
    string word;
    int inversions {};

    Word(string _word){
        word = _word;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(word.at(i) > word.at(j)){
                    ++inversions;
                }
            }
        }
    }
};

struct comparator{
    bool operator()(const Word &a, const Word &b){
        return a.inversions < b.inversions;
    }
};

int main(){
    long numCases;
    string word;
    cin >> numCases;
    for(int i=0;i<numCases;i++){
        cin >> n >> m;
        vector<Word> words {};
        for(int j=0;j<m;j++){
            cin >> word;
            Word curr {word};
            words.push_back(curr);
        }

        stable_sort(words.begin(),words.end(),comparator());

        if(i>0){
            cout << '\n';
        }
        for(Word word:words){
            cout << word.word << '\n';
        }
    }

}