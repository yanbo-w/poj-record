#include <iostream> // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <queue>
#include <limits.h>

using namespace std; // since cin and cout are both in namespace std, this saves some text

int convert_to_int(int x, int y, int n){
    return 1 << (x*n+y);
}

void get_diagonal(vector<int> &diagonal, int n){
    for(int i = 0; i < n; i++){
        int total = 0;
        int j = 0;
        int k = i;
        while(k >= 0){
            // cout << k << "  " << j << endl;
            total += convert_to_int(k, j, n);
            k--;
            j++;
        }
        diagonal.push_back(total);
    }
    for(int j = 1; j < n; j++){
        int total = 0;
        int i = n-1;
        int k = j;
        while(k < n){
            // cout << i << "  " << k << endl;
            total += convert_to_int(i, k, n);
            i--;
            k++;
        }
        diagonal.push_back(total);
    }
    // cout << "---------" << endl;
    for(int i = n-1; i >= 0; i--){
        int total = 0;
        int j = 0;
        int k = i;
        while(k < n){
            // cout << k << "  " << j << endl;
            total += convert_to_int(k, j, n);
            k ++;
            j ++;
        }
        diagonal.push_back(total);
    }
    for(int j = 1; j < n; j++){
        int total = 0;
        int i = 0;
        int k = j;
        while(k < n){
            // cout << i << "  " << k << endl;
            total += convert_to_int(i, k, n);
            i ++;
            k ++;
        }
        diagonal.push_back(total);
    }
}

void floyd(vector<vector<int>> &e, int n){
    int i,j,k;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(e[i][j]>e[i][k]+e[k][j])
                     e[i][j]=e[i][k]+e[k][j];
}

int main() {

    freopen("kickstart/ks2.in", "r", stdin);

    int t, n;
    char tmp;
    cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int tt = 1; tt <= t; ++tt) {
        cin >> n; 

        vector<int> diagonal;
        get_diagonal(diagonal, n);

        vector<vector<int>> map(1<<(n*n));
        for(int i = 0; i < (1<<(n*n)); i++){
            for(int j = 0; j < (1<<(n*n)); j++) map[i].push_back(1000);
        }

        for(int i = 0; i<(1<<(n*n)); i++){
            for(int tr = 0; tr < diagonal.size(); tr++){
                map[i][i ^ diagonal[tr]] = 1;
            }
            map[i][i] = 0;
        }

        floyd(map,(1<<(n*n)));

        int start = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                tmp = getchar();
                if(tmp == '.') start += convert_to_int(i,j,n);
            }
            getchar();
        }

        cout << map[start][0] << endl;


        
    }
    
    return 0;
}