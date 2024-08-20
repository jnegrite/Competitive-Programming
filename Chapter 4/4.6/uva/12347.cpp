#include<iostream>
#include<vector>

using namespace std;

vector<int> values {};

struct Node {
    int from;
    int to;
    int val;
    Node *left {nullptr};
    Node *right {nullptr};

    ~Node(){
        delete left;
        delete right;
    }

    Node(int from, int to){
        val = values[from];

        int leftTo = from-1;
        while(leftTo<to){
            if(values[leftTo+1]>val){
                break;
            }
            ++leftTo;
        }

        if(from < leftTo){
            left = new Node(from+1,leftTo);
        }

        if(leftTo < to){
            right = new Node(leftTo+1,to);
        }
    }

    void printPost(){
        if(left != nullptr){
            left->printPost();
        }

        if(right != nullptr){
            right->printPost();
        }

        cout << val << '\n';
    }
};

int main(){
    int val;
    while(cin>>val){
        values.push_back(val);
    }

    Node *root = new Node(0,values.size()-1);
    root->printPost();
    delete root;
}