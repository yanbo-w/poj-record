#include <iostream>
#include <map>
#include <math.h>

using namespace std;

int main(void) {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int case_num = 0;
    while(1){
        case_num ++;
        int n;
        cin >> n;
        if(n==0) break;
        double adj[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adj[i][j] = 0.0;
            }
        }
        map<string, int> id;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            id[s] = i;
        }
        int m;
        cin >> m;
        for(int i=0;i<m;i++){
            string s1, s2;
            double rate;
            cin >> s1 >> rate >> s2;
            adj[id[s1]][id[s2]] = log(rate);
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j] = adj[i][j] > adj[i][k] + adj[k][j] ? adj[i][j] : adj[i][k] + adj[k][j];
                }
            }
        }

        bool flag = false;
        for(int i=0;i<n;i++){
            if(adj[i][i]>0){
                cout << "Case " << case_num << ": Yes" << endl; 
                flag = true; 
                break;
            }
        }
        if(!flag) cout << "Case " << case_num << ": No" << endl;
    }

    return 0;
}