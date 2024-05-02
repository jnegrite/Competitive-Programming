#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

#define LSOne(x) ((x) & -(x));

using namespace std;

long ft[1001] {};
long values[1001] {};
long nValues{};

long sumTo(int val){
    long output {0};
    int curr = val;
    while(curr > 0){
        output += ft[curr];
        curr -= LSOne(curr);
    }
    return output;
}

long sumRange(int from, int to){
    return sumTo(to) - sumTo(from-1);
}


struct Node {
    int root;
    int from;
    int to;
    Node *left {};
    Node *right {};

    Node(){};

    ~Node(){
        delete left;
        delete right;
    }

    void determineRoot(){
        long sumLeft {sumRange(from, to-1)};
        long sumRight {0};
        long lowestDiff {abs(sumLeft-sumRight)};
        long bestSumLeft {sumLeft};
        root = to;

        for(int pos=to-1;pos>=from;pos--){
            sumLeft -= values[pos];
            sumRight += values[pos+1];
            long currDiff {abs(sumLeft-sumRight)};

            if(values[pos] == values[pos+1]){
                continue;
            }
            if(currDiff < lowestDiff || (currDiff==lowestDiff && sumLeft > bestSumLeft)){
                lowestDiff = currDiff;
                bestSumLeft = sumLeft;
                root = pos;
            }
        }

        if(root != from){
            left = new Node(from, root-1);
        }

        if(root != to){
            right = new Node(root+1, to);
        }
    }

    Node(int _from, int _to){
        from = _from;
        to = _to;

        if(from != to){
            determineRoot();
        } else {
            root = from;
        }
    }

    string getRepr(){
        string output {to_string(values[root])};

        //both children in place
        if(left != nullptr && right != nullptr){
            output += "(" + left->getRepr() + "," + right->getRepr() + ")";
        } else if (left != nullptr){
            output += "(" + left->getRepr() + ")";
        } else if (right != nullptr){
            output += "(" + right->getRepr() + ")";
        }
        return output;
    }

};

int main(){
    int nCases;
    cin >> nCases;
    for(int tc=1;tc<=nCases;tc++){
        cin >> nValues;
        for(int i=1;i<=nValues;i++){
            cin >> values[i];
            ft[i] = 0;
        }
        sort(values+1,values+1+nValues);
        
        //initialize fenwick tree
        for(int i=1;i<=nValues;i++){
            int curr = i;
            ft[curr] += values[i];
            curr += LSOne(curr);

            if(curr <= nValues){
                ft[curr] += ft[i];
            }
        }

        Node *root = new Node(1,nValues);
        cout << "Case #" << tc << ": " << root->getRepr() << '\n';

        delete root;
    }
}