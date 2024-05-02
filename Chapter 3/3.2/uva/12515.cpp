#include<iostream>
#include<vector>

using namespace std;

int getDistance(const string &movie, const string &clip){
    int distance {clip.length()};
    int maxOffset {movie.length() - clip.length()};

    for(int offset=0;offset<=maxOffset;++offset){
        int currDist {0};
        for(int i=0;i<clip.length();++i){
            if(movie.at(offset+i) != clip.at(i)){
                ++currDist;
            }
        }
        distance = min(distance, currDist);
    }
    return distance;
}

int main(){
    int M, Q;
    string s;
    cin >> M >> Q;
    vector<string> movies {};

    for(int i=0;i<M;i++){
        cin >> s;
        movies.push_back(s);
    }

    //queries
    for(int q=0;q<Q;q++){
        cin >> s;
        int minDistance {s.length()+1};
        int ans {0};
        for(int i=0;i<M;i++){
            if(movies[i].length() >= s.length()){
                int curr {getDistance(movies[i],s)};
                if(curr < minDistance){
                    minDistance = curr;
                    ans = i+1;
                }
            }
        }
        cout << ans << '\n';
    }
}