#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int group[501];
int h[501];
int node[501];
int N;
int edgenum;

struct edge{
    int node_1;
    int node_2;
    int w;
};
edge p[501*501];

void init(){
    for(int i=0;i<N;i++){
        group[i] = i;
        h[i] = 0;
        node[i] = 1;
    }
}

int findset(int x){
    if(group[x]!=x) group[x] = findset(group[x]);
    return group[x];
}

int uniteset(int x, int y){
    x = findset(x);
    y = findset(y);
    if(x==y) return x;
    if(h[x]>h[y]){
        node[x] = node[x] + node[y];
        group[y] = x;
        return x;
    }
    else{
        node[y] = node[x] + node[y];
        group[x] = y;
        if(h[x]==h[y]) h[y]++;
        return y;
    }
}

int cmp( const void *a ,const void *b) 
{ 
return (*(edge *)a).w > (*(edge *)b).w ? 1 : -1; 
} 

int main(){

    freopen("data2.in", "r", stdin);
    freopen("data2.out", "w", stdout);
    
    int T;
    cin >> T;
    for(int T_t=0; T_t<T; T_t++){
        cin >> N;
        edgenum = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int weight;
                scanf("%d", &weight);
                if(i>j){
                    p[edgenum].node_1 = i;
                    p[edgenum].node_2 = j;
                    p[edgenum].w = weight;
                    edgenum++;
                }
            }
        }
        init();
        qsort(p, edgenum, sizeof(p[0]), cmp);
        int p_tr = 0;
        while(1){
            edge tmp = p[p_tr];
            p_tr++;
            if(node[uniteset(tmp.node_1, tmp.node_2)]==N){
                cout << tmp.w <<endl;
                break;
            }
        }
    }
}
