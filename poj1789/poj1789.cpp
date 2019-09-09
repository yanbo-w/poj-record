#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char code[2010][10];
int adj[2010][2010];

int dist(char *a, char *b){
    int dis = 0;
    for(int i=0;i<strlen(a);i++){
        if(a[i]!=b[i]) dis++;
    }
    return dis;
}

int main(){

    // freopen("data.in", "r", stdin);
    
    int N;
    while(1){
        cin >> N;
        if(N==0) break;
        for(int i=0;i<N;i++){
            scanf("%s", code[i]);
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i<j) adj[i][j] = dist(code[i],code[j]);
                else if(i==j) adj[i][j] = 0;
                else adj[i][j] = adj[j][i];
            }
        }

        int Q = 0;
        bool traveled[N];
        int min_from[N];
        min_from[0] = 0;
        traveled[0] = true;
        for(int i=1;i<N;i++){
            traveled[i] = false;
            min_from[i] = adj[0][i];
        }
        for(int i_1=1;i_1<N;i_1++){
            int min_dist = N+1;
            int min_node = 0;
            for(int i=0;i<N;i++){
                if(!traveled[i] && min_dist>min_from[i]){
                    min_dist = min_from[i];
                    min_node = i;
                }
            }
            Q = Q + min_dist;
            traveled[min_node] = true;
            for(int i=0;i<N;i++){
                if(!traveled[i] && adj[min_node][i]<min_from[i]){
                    min_from[i] = adj[min_node][i];
                }
            }
        }
        cout << "The highest possible quality is 1/" << Q << "." << endl;
    }
    
    return 0;
}