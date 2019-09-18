# include <iostream>

using namespace std;

int adj[101][101];
int dis[101];
bool tr[101];

int main(){

    // freopen("data.in","r",stdin);
    int N;
    while(cin >> N){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> adj[i][j];
            }
        }

        for(int i=0;i<N;i++){
            dis[i] = adj[0][i];
            tr[i] = false;
        }
        tr[0] = true;
        int dis_sum = 0;

        while(1){
            int min_dis = 100000;
            int min_node = -1;
            for(int i=0;i<N;i++){
                if(!tr[i]){
                    if(min_dis > dis[i]){
                        min_dis = dis[i]; 
                        min_node = i;
                    }
                }
            }
            if(min_node != -1){
                tr[min_node] = true;
                dis_sum += min_dis;
                for(int i=0;i<N;i++){
                    if(!tr[i]&& adj[min_node][i] < dis[i]){
                        dis[i] = adj[min_node][i];
                    }
                }
            }
            else break;
        }

        cout << dis_sum << endl;
    }
    

}