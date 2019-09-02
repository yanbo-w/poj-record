#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct ArcNode{
    double rate;
    double commision;
    int currency_to;
    ArcNode *nextarc;
};

struct VNode{
    VNode(): firstarc(NULL){}
    int currency_type;
    ArcNode *firstarc;
};

struct Graph{
    VNode *vnode;
    int numNodes;
};

void Insert_Arc(Graph gp, int currency_1, int currency_2, double rate_12, double commision_12){
    ArcNode *tmp;
    if(gp.vnode[currency_1].firstarc!=NULL){
        tmp = gp.vnode[currency_1].firstarc;
        while(tmp->nextarc != NULL){
            tmp = tmp->nextarc;
        }
        ArcNode *n = new ArcNode;
        n->rate = rate_12;
        n->commision = commision_12;
        n->currency_to = currency_2;
        n->nextarc = NULL;
        tmp->nextarc = n;
    }
    else{
        tmp = new ArcNode;
        tmp->rate = rate_12;
        tmp->commision = commision_12;
        tmp->currency_to = currency_2;
        tmp->nextarc = NULL;
        gp.vnode[currency_1].firstarc = tmp;
    }
    
}

bool bellman_travel(Graph gp, int s, double v){
    vector<double> sum(gp.numNodes,0);
    sum[s] = v;
    vector<VNode*> travel;
    travel.push_back(&gp.vnode[s]);
    for(int i=0; i<gp.numNodes-1; i++){
        vector<VNode*> new_travel;
        for (int j=0; j< travel.size(); j++){
            VNode *node_tr = travel[j];
            ArcNode *arc_tr = node_tr->firstarc;
            while(arc_tr!=NULL){
                //cout << node_tr->currency_type << arc_tr->currency_to <<endl;
                bool found = false;
                for (int k=0; k< new_travel.size(); k++){
                    if(new_travel[k]==&gp.vnode[arc_tr->currency_to]){
                        found = true;
                        break;
                    }
                }
                if(!found) new_travel.push_back(&gp.vnode[arc_tr->currency_to]);
                // currency_1 = node_tr->currency_type;
                // currency_2 = arc_tr->currency_to;
                // rate = arc_tr->rate;
                // commision = arc_tr->commision;
                double sum_t = arc_tr->rate*(sum[node_tr->currency_type]-arc_tr->commision);
                sum[arc_tr->currency_to] = sum[arc_tr->currency_to]>sum_t?sum[arc_tr->currency_to]:sum_t;
                arc_tr = arc_tr->nextarc;
            }
        }
        travel = new_travel;
    }
    bool flag = false;

    for (int j=0; j< travel.size(); j++){
        VNode *node_tr = travel[j];
        ArcNode *arc_tr = node_tr->firstarc;
        while(arc_tr!=NULL){
            //cout << node_tr->currency_type << arc_tr->currency_to <<endl;
            // currency_1 = node_tr->currency_type;
            // currency_2 = arc_tr->currency_to;
            // rate = arc_tr->rate;
            // commision = arc_tr->commision;
            double sum_t = arc_tr->rate*(sum[node_tr->currency_type]-arc_tr->commision);
            if(sum[arc_tr->currency_to]<sum_t){
                flag = true;
                return true;
            }
            arc_tr = arc_tr->nextarc;
        }
    }
    if(!flag) return false;
}

int main(void) {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int num_currency, num_expoint, nick_currency_kind;
    double nick_currency_sum;

    cin >> num_currency >> num_expoint >> nick_currency_kind >> nick_currency_sum;

    nick_currency_kind --;
    Graph gp;
    gp.vnode = new VNode[num_currency];
    gp.numNodes = num_currency;
    for(int num_currency_tr =0; num_currency_tr < num_currency; num_currency_tr++){
        VNode vn_tr;
        vn_tr.currency_type = num_currency_tr;
        vn_tr.firstarc = NULL;
        gp.vnode[num_currency_tr] = vn_tr;
    }

    for(int num_expoint_tr=0; num_expoint_tr < num_expoint; num_expoint_tr++){
        int currency_1, currency_2;
        cin >> currency_1 >> currency_2;
        currency_1 --;
        currency_2 --;
        double rate_12, rate_21, commision_12, commision_21;
        cin >> rate_12 >> commision_12 >> rate_21 >> commision_21;
        Insert_Arc(gp, currency_1, currency_2, rate_12, commision_12);
        Insert_Arc(gp, currency_2, currency_1, rate_21, commision_21);
    }

    if(bellman_travel(gp, nick_currency_kind, nick_currency_sum)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}