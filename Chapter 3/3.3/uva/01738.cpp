#include<cstdio>
#include<unordered_set>
#include<string>

using namespace std;

struct Node {
    long value;
    Node *left {};
    Node *right {};

    Node(int _value){
        value = _value; 
    }
    
    ~Node(){
        delete left;
        delete right;
    }

    void insert(int _val){
        if(_val < value){
            if(left == nullptr){
                left = new Node(_val);
            } else {
                left->insert(_val);
            }
        } else {
            if(right == nullptr){
                right = new Node(_val);
            } else {
                right->insert(_val);
            }
        }
    }

    string getRepr(){
        if(left == nullptr && right==nullptr){
            return "x";
        }

        string output {"x("};
        if(left!=nullptr){
            output += left->getRepr();
        }
        output += ",";
        if(right!=nullptr){
            output += right->getRepr();
        }
        output += ")";
        return output;
    }

};

unordered_set<string> reprs {};

int main(){
    int nPrototypes;
    int nLayers;

    long curr;
    
    while(scanf("%d %d\n",&nPrototypes,&nLayers)!=EOF){
        reprs.clear();
        while(nPrototypes--){
            scanf("%ld",&curr);
            Node root {curr};

            for(int i=1;i<nLayers;i++){
                scanf("%ld",&curr);
                root.insert(curr);
            }
            reprs.emplace(root.getRepr());
        }
        printf("%d\n",reprs.size());
    }
}
