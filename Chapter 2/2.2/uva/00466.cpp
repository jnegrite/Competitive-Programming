#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dim;

bool isPreserved(vector<string> &src, vector<string> &dest){
    for(int row=0;row<dim;row++){
        if(src[row] != dest[row]){
            return false;
        }
    }
    return true;
}

vector<string> flipVertical(vector<string> src){
    reverse(src.begin(), src.end());
    return src;
}

bool isRotated90(vector<string> &src, vector<string> &dest){
    for(int iFrom=0,iTo=dim-1;iFrom<dim;iFrom++,iTo--){
        for(int jFrom=0;jFrom<dim;jFrom++){
            if(src[iFrom].at(jFrom) != dest[jFrom].at(iTo)){
                return false;
            }
        }
    }
    return true;
}

bool isRotated180(vector<string> &src, vector<string> &dest){
for(int iFrom=0,iTo=dim-1;iFrom<dim;iFrom++,iTo--){
        for(int jFrom=0,jTo=dim-1;jFrom<dim;jFrom++,jTo--){
            if(src[iFrom].at(jFrom) != dest[iTo].at(jTo)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    string s;
    int tc{0};
    while(cin >> dim){
        string output {""};
        vector<string> src {}, dest{};
        for(int row=0;row<dim;row++){
            cin >> s;
            src.push_back(s);
            cin >> s;
            dest.push_back(s);
        }

        if(isPreserved(src,dest)){
            output = "preserved.";
        } else if (isRotated90(src,dest)){
            output = "rotated 90 degrees.";
        } else if (isRotated180(src,dest)){
            output = "rotated 180 degrees.";
        } else if (isRotated90(dest,src)){
            output = "rotated 270 degrees.";
        } else {
            auto verticalFlip = flipVertical(src);
            
            if (isPreserved(dest,verticalFlip)){
                output = "reflected vertically."; 
            } else if(isRotated90(verticalFlip,dest)){
                output = "reflected vertically and rotated 90 degrees.";
            } else if(isRotated180(verticalFlip,dest)){
                output = "reflected vertically and rotated 180 degrees.";
            } else if(isRotated90(dest,verticalFlip)){
                output = "reflected vertically and rotated 270 degrees.";
            } else {
                output = "improperly transformed.";
            }
        }
        cout << "Pattern " << ++tc << " was " << output << '\n';
    }

}