#include<cstdio>
#include<vector>

using namespace std;

vector<long> p, rk, sz, contents;

long getParent(long i){
    return p[i] == i ? i : p[i]=getParent(p[i]);
}

int main(){
    long nItems, nDrawers;
    long a, b, p1, p2;
    scanf("%ld %ld\n", &nItems, &nDrawers);
    
    p.reserve(nItems+1);
    for(long i=0;i<=nDrawers;i++){
        p.push_back(i);
    }
    
    sz.assign(nDrawers+1,1);
    rk.assign(nDrawers+1,0);
    contents.assign(nDrawers+1,0);
    for(long item=0;item<nItems;++item){
        scanf("%ld %ld\n",&a,&b);
        
        p1 = getParent(a);
        p2 = getParent(b);

        //link if not part of the same tree
        if(p1 != p2){
            if(rk[p1] < rk[p2]){
                swap(p1,p2);
            } else if(rk[p1] == rk[p2]){
                ++rk[p1];
            }

            p[p2] = p1;
            sz[p1] += sz[p2];
            sz[p2] = 0;
            contents[p1] += contents[p2];
            contents[p2] = 0;
        }

        if(sz[p1] > contents[p1]){
            //this tree has space
            ++contents[p1];
            printf("LADICA\n");
        } else {
            printf("SMECE\n");
        }

    }
}