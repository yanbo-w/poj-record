#include <iostream>
#include <vector>
#include <list>
#include <string.h>

using namespace std;

struct ArcNode{
    int time;
    int destination;
    ArcNode *nextarc;
};

struct VNode{
    VNode(): firstarc(NULL){}
    int start;
    ArcNode *firstarc;
};

struct Graph{
    VNode *vnode;
    int numNodes;
};

void Insert_Arc(Graph gp, int start, int destination, int time){
    ArcNode *tmp;
    if(gp.vnode[start].firstarc!=NULL){
        tmp = gp.vnode[start].firstarc;
        while(tmp->nextarc != NULL){
            tmp = tmp->nextarc;
        }
        ArcNode *n = new ArcNode;
        n->time = time;
        n->destination = destination;
        n->nextarc = NULL;
        tmp->nextarc = n;
    }
    else{
        tmp = new ArcNode;
        tmp->time = time;
        tmp->destination = destination;
        tmp->nextarc = NULL;
        gp.vnode[start].firstarc = tmp;
    }
    
}

bool bellman_travel(Graph gp){
    vector<int> sum(gp.numNodes,gp.numNodes*10000);
    sum[0] = 0;
    int travel[gp.numNodes];
    memset(travel, 0, sizeof(travel));
    travel[0] = 1;
    for(int i=0; i<gp.numNodes-1; i++){
        int new_travel[gp.numNodes];
        memset(new_travel, 0, sizeof(new_travel));
        for (int j=0; j< gp.numNodes; j++){
            if(travel[j]==1){
                VNode *node_tr = &gp.vnode[j];
                ArcNode *arc_tr = node_tr->firstarc;
                while(arc_tr!=NULL){
                    new_travel[arc_tr->destination] = 1;
                    // cout << node_tr->start+1 << arc_tr->destination+1 <<endl;
                    int sum_t = arc_tr->time + sum[node_tr->start];
                    sum[arc_tr->destination] = sum[arc_tr->destination]<sum_t?sum[arc_tr->destination]:sum_t;
                    arc_tr = arc_tr->nextarc;
            }
            }
            
        }
        memcpy(travel,new_travel,gp.numNodes*sizeof(int));
    }

    bool flag = false;
    for (int j=0; j< gp.numNodes; j++){
        if(travel[j]==1){
            VNode *node_tr = &gp.vnode[j];
            ArcNode *arc_tr = node_tr->firstarc;
            while(arc_tr!=NULL){
                // cout << node_tr->start+1 << arc_tr->destination+1 <<endl;
                int sum_t = arc_tr->time + sum[node_tr->start];
                if( sum[arc_tr->destination]>sum_t){
                    flag = true;
                    return true;
                }
                arc_tr = arc_tr->nextarc;
            }
        }
    }
    if(!flag) return false;
    else return true;
}

int main(void) {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int farm_num;
    cin >> farm_num;
    for(int fram_tr=0; fram_tr < farm_num; fram_tr++){
        int node, path, wormhole;
        cin >> node >> path >> wormhole;
        Graph gp;
        gp.vnode = new VNode[node];
        gp.numNodes = node;
        for(int node_tr =0; node_tr < node; node_tr++){
            VNode vn_tr;
            vn_tr.start = node_tr;
            vn_tr.firstarc = NULL;
            gp.vnode[node_tr] = vn_tr;
        }
        for(int path_tr=0; path_tr<path; path_tr++){
            int node_1, node_2, t;
            cin >> node_1 >> node_2 >> t;
            node_1--;
            node_2--;
            Insert_Arc(gp, node_1, node_2, t);
            Insert_Arc(gp, node_2, node_1, t);
        }
        for(int wormhole_tr=0; wormhole_tr<wormhole; wormhole_tr++){
            int node_1, node_2, t;
            cin >> node_1 >> node_2 >> t;
            node_1--;
            node_2--;
            Insert_Arc(gp, node_1, node_2, -t);
        }
        if(bellman_travel(gp)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}