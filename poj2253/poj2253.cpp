#include <iostream>
// #include <queue>
#include <math.h>
#include <iomanip>

using namespace std;

// struct edge{
//     edge(int a, int b, double c){
//         this->stone_1 = a;
//         this->stone_2 = b;
//         this->distance = c;
//     }
//     int stone_1;
//     int stone_2;
//     double distance;
//     bool operator < (const edge &a) const
//     {
//         return a.distance > distance;
//     }
// };

double cal_dis(int c[][2], int stone_1, int stone_2){
    return sqrt((c[stone_1][0]-c[stone_2][0])*(c[stone_1][0]-c[stone_2][0])+(c[stone_1][1]-c[stone_2][1])*(c[stone_1][1]-c[stone_2][1]));
}

int main(void) {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int scenario = 0;
    while(1){
        scenario++;
        int stone_num;
        cin >> stone_num;
        if(stone_num==0) break;
        int stone_coordinates[stone_num][2];
        for(int i=0; i< stone_num; i++){
            cin >> stone_coordinates[i][0];
            cin >> stone_coordinates[i][1];
        }
        // priority_queue <edge> edge_pq;
        // edge_pq.push(edge(0,1,cal_dis(stone_coordinates, 0, 1)));
        double road[stone_num][stone_num];
        for(int i=0; i<stone_num; i++){
            for(int j=0; j<stone_num; j++){
                road[i][j] = cal_dis(stone_coordinates,i,j);
            }
        }
        for(int k=0;k<stone_num; k++){
            for(int i=0;i<stone_num;i++){
                for(int j=0;j<stone_num;j++){
                    double max = road[i][k]>road[k][j]?road[i][k] : road[k][j];
                    road[i][j] = road[i][j] <max ? road[i][j] : max;
                }
            }
        }
        // for(int stone_tr=2; stone_tr<stone_num; stone_tr++){
        //     edge tmp = edge_pq.top();
        //     if(cal_dis(stone_coordinates, tmp.stone_1, stone_tr)<tmp.distance || cal_dis(stone_coordinates, tmp.stone_2, stone_tr)<tmp.distance){
        //         edge_pq.pop();
        //         edge_pq.push(edge(tmp.stone_1, stone_tr,cal_dis(stone_coordinates, tmp.stone_1, stone_tr)));
        //         edge_pq.push(edge(tmp.stone_2, stone_tr,cal_dis(stone_coordinates, tmp.stone_2, stone_tr)));
        //     }
        // }
        cout << "Scenario #" << scenario << endl;
        cout << "Frog Distance = " <<fixed << setprecision(3) << road[0][1] << endl << endl;
    }

    return 0;
}