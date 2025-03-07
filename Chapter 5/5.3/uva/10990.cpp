#include<iostream>
#include<vector>

using namespace std;

const long MAXVAL = 2000000;
vector<long> eulerPhi {};
vector<long> depth {};

long get_depth(long value){

    long &ans {depth[value]};
    if(ans != -1){
        return ans;
    }

    ans = get_depth(eulerPhi[value]) + 1;
    return ans;
}

struct Node {
    long from;
    long to;
    long total;
    Node *leftChild {nullptr};
    Node *rightChild {nullptr};

    Node(long _from, long _to){
        from = _from;
        to = _to;

        if(from == to){
            total = get_depth(from);
        } else {
            long mid {(from + to)>>1};
            leftChild = new Node(from, mid);
            rightChild = new Node(mid+1, to);
            total = leftChild->total + rightChild->total;
        }
    }

    ~Node(){
        if(from != to){
            delete leftChild;
            delete rightChild;
        }
    }

    long getSum(long sFrom, long sTo){
        if(sFrom <= from && to <= sTo){
            return total;
        } else if (sTo < from || to < sFrom){
            return 0;
        } else {
            return leftChild->getSum(sFrom, sTo) + rightChild->getSum(sFrom, sTo);
        }
    }
};

int main(){
    eulerPhi.reserve(MAXVAL+1);
    for(long i=0;i<=MAXVAL;++i){
        eulerPhi.push_back(i);
    }

    for(int i=2;i<=MAXVAL;++i){
        if(eulerPhi.at(i) == i){
            for(int j=i;j<=MAXVAL;j+=i){
                eulerPhi[j] = (eulerPhi[j]/i) * (i-1);
            }
        }
    }

    depth.assign(MAXVAL+1,-1);
    depth[1] = 0;

    Node *root = new Node(1,2000000);
    int nCases;
    cin >> nCases;
    long a, b;
    while(nCases--){
        cin >> a >> b;
        cout << root->getSum(a,b) << '\n';
    }

    delete root;

}