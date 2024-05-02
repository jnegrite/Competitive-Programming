#include<cstdio>
#include<vector>

using namespace std;

struct Node {
    long from {};
    long to{};
    long lazy {};
    long rangeMax {};
    long rangeMin {};
    Node* childLeft {};
    Node* childRight {};

    Node(long _from, long _to){
        from = _from;
        to = _to;
        
        if(from == to){
            rangeMin = rangeMax = from;
        } else {
            long mid = (from + to)/2;
            childLeft = new Node(from, mid);
            childRight = new Node(mid+1,to);
            reconcile();
        }
    }
    
    ~Node(){
        delete childLeft;
        delete childRight;
        //printf("DELETING %d:%d\n",from,to);
    }
    
    void propagateLazy(){
        if(lazy != 0){
            rangeMax += lazy;
            rangeMin += lazy;

            if(childLeft){
                childLeft->lazy += lazy;
                childRight->lazy += lazy;
            }
            lazy = 0;
        }
    }

    long getPos(long pos){
        propagateLazy();
        if(from == to){
            return rangeMax;
        }

        if(pos <= childLeft->to){
            return childLeft->getPos(pos);
        } else {
            return childRight->getPos(pos);
        }
    }

    void reconcile(){
        if(childLeft){
            rangeMax = max(childLeft->rangeMax, childRight->rangeMax);
            rangeMin = min(childLeft->rangeMin, childRight->rangeMin);
        }
    }

    void adjust(long adFrom, long adTo, long value){
        propagateLazy();
        if(adFrom <= rangeMin && rangeMax <= adTo){
            rangeMax += value;
            rangeMin += value;
            if(childLeft){
                childLeft->lazy += value;
                childRight->lazy += value;
            }
        } else if (rangeMax < adFrom || adTo < rangeMin){

        } else {
            childLeft->adjust(adFrom, adTo, value);
            childRight->adjust(adFrom, adTo, value);
            reconcile();
        }
    }
    
};

int main(){
    int nCases;
    scanf("%d\n",&nCases);
    long nItems, nQueries;
    long lastIdx;
    for(int tc=0;tc<nCases;tc++){
        scanf("%ld %ld\n",&nItems,&nQueries);
        
        Node* root = new Node(1, nItems);

        for(long qNum = 0;qNum < nQueries; qNum++){
            long curr;
            scanf("%ld",&curr);
            long pos = root->getPos(curr);
            if(qNum != 0){
                printf(" ");
            }
            printf("%ld",pos-1);

            root->adjust(pos,pos,-pos);
            root->adjust(0,pos-1,1);
        }
        printf("\n");
        
        delete root;
    }
}