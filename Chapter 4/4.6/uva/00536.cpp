#include<iostream>
#include<memory>

using namespace std;

struct Node {
    char root;
    string preOrder {};
    string inOrder {};
    Node* left {nullptr};
    Node* right {nullptr};

    Node(string _pre, string _in){
        preOrder = _pre;
        inOrder = _in;

        root = preOrder.at(0);
        auto pos {inOrder.find(root)};

        string leftPre {};
        string leftIn {};
        string rightPre {};
        string rightIn {};

        //left nod exists
        if(pos > 0){
            leftPre = preOrder.substr(1,pos);
            leftIn = inOrder.substr(0,pos);
            left = new Node(leftPre, leftIn);
        }

        if(pos < (inOrder.length()-1)){
            rightPre = preOrder.substr(pos+1);
            rightIn = inOrder.substr(pos+1);

            right = new Node(rightPre, rightIn);
        }
    }

    ~Node(){
        delete left;
        delete right;
    }

    void printPost(){
        if(left != nullptr){
            left->printPost();
        }

        if(right != nullptr){
            right->printPost();
        }
        cout << root;
    }
};

int main(){
    string preOrd, inOrd;
    while(cin >> preOrd >> inOrd){
        Node curr {preOrd, inOrd};
        curr.printPost();
        cout << '\n';
    }
}