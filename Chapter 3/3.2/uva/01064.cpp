#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct Packet {
    int msgId {};
    long from {};
    long to {};
    long size {};

    Packet(int _msgId, long _from, long _to){
        msgId = _msgId;
        from = _from;
        to = _to;
        size = to - from + 1;
    }

    bool operator<(const Packet &o) const {
        return from > o.from;
    }
};

vector<Packet> packets {};

long msgSizes[5] {};
int nMessages;
int nPackets;

int msgOrder[5] {};


long simulateQueue(){
    long maxBuffer {};
    long currBuffer {};

    //setups
    vector<priority_queue<Packet>> q {};
    q.assign(nMessages,priority_queue<Packet> {});
    long front[5] {};
    for(int i=0;i<nMessages;i++){
        front[i] = 1;
    }

    int orderNum {0};
    int currMsg {msgOrder[orderNum]};

    //process packets in Order
    for(Packet p:packets){
        //check if can proceed
        if(p.msgId == currMsg && front[currMsg] == p.from){
            //proceed
            front[currMsg] += p.size;

            //check if it was the last message
            if(p.to == msgSizes[currMsg]){
                currMsg = msgOrder[++orderNum];
            }

            //flush out what can be flushed
            while(orderNum < nMessages){
                if(q[currMsg].empty()){
                    break;
                }

                Packet f {q[currMsg].top()};
                
                if(f.from != front[currMsg]){
                    break;
                }

                //proceed with removal
                currBuffer -= f.size;
                q[currMsg].pop();
                front[currMsg] += f.size;

                //check if it was the last message
                if(f.to == msgSizes[currMsg]){
                    currMsg = msgOrder[++orderNum];
                }
            }
        } else {
            //put to buffer
            q[p.msgId].emplace(p);
            currBuffer += p.size;

            if(currBuffer > maxBuffer){
                maxBuffer = currBuffer;
            }
        }
    }

    return maxBuffer;
}

int main(){

    int tc {};
    while(cin >> nMessages >> nPackets, nMessages != 0 && nPackets != 0){
        
        //get messageSizes
        for(int i=0;i<nMessages;i++){
            cin >> msgSizes[i];
        }

        //get data for packets
        int msgId;
        long from, to;
        packets.clear();
        while(nPackets--){
            cin >> msgId >> from >> to;
            packets.push_back(Packet{msgId-1,from,to});
        }

        //setup priorityOrder
        long minBuffer {1000000000};
        for(int i=0;i<nMessages;i++){
            msgOrder[i] = i;
        }

        do{
            long maxBuffer = simulateQueue();
            if(maxBuffer<minBuffer){
                minBuffer = maxBuffer;
            }
        } while(next_permutation(msgOrder,msgOrder+nMessages));
        
        cout << "Case " << ++tc << ": " << minBuffer << "\n\n";
    }
    
}