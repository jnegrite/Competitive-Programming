#include<cstdio>
#include<vector>
#include<algorithm>
#include<bitset>

using namespace std;

const long long MAXVAL = 2000000;

vector<long> primes {};
bitset<MAXVAL+1> isPrime {};

int numPF(long long N){
    int ans = 0;
    for(int i=0; (i<(int)primes.size()) && (primes[i]*primes[i] <= N); ++i){
        while(N%primes[i] == 0){
            N /= primes[i];
            ++ans;
        }
    }
    return ans + (N!=1);
}

struct Node {
    int numPF {};
    long value {};

    Node(int _numPF, long _value){
        numPF = _numPF;
        value = _value;
    }

    bool operator<(const Node &o) const {
        if (numPF != o.numPF){
            return numPF < o.numPF;
        } else {
            return value < o.value;
        }
    }
};

int main(){
    isPrime.set();

    //generate set of primes
    for(long long factor=2;factor<=MAXVAL;++factor){
        if(!isPrime.test(factor)){
            continue;
        }

        primes.push_back(factor);

        long long increment {(factor == 2LL) ? factor : (factor << 1)};
        for(long long i=factor*factor; i <= MAXVAL; i+=increment){
            isPrime.reset(i);
        }
    }

    vector<Node> nodes {};
    nodes.reserve(MAXVAL);

    for(long i=1;i<=MAXVAL;++i){
        nodes.emplace_back(numPF(i),i);
    }

    sort(nodes.begin(),nodes.end());

    long value;
    int nCase {};
    while(scanf("%ld\n",&value), value != 0){
        printf("Case %d: %ld\n",++nCase,nodes[value-1].value);
    }
}