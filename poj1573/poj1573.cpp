#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int rows, columns, entry;
    cin >> rows >> columns >> entry;
    while(rows>0 && columns >0 && entry>0){
        char instructions[rows][columns];
        for(int rows_tr=0;rows_tr<rows;rows_tr++){
            for(int columns_tr=0;columns_tr<columns;columns_tr++){
                cin >> instructions[rows_tr][columns_tr];
            }
        }
        //cout << instructions[0][0];
        vector<vector<int> > map(rows,vector<int>(columns));
        //int (*map)[rows] = new int[rows][columns];
        //int map[rows][columns] = {0};
        int rows_tr= 1;
        int columns_tr = entry;
        int steps = 0;
        int flag = 0;
        while(rows_tr>0 && rows_tr<=rows && columns_tr>0 && columns_tr<=columns){
            if(map[rows_tr-1][columns_tr-1]==0) map[rows_tr-1][columns_tr-1] = steps+1;
            else{
                flag = 1;
                break;
            }
            steps = map[rows_tr-1][columns_tr-1];
            switch(instructions[rows_tr-1][columns_tr-1]){
                case 'N': rows_tr--; break;
                case 'S': rows_tr++; break;
                case 'E': columns_tr++; break;
                case 'W': columns_tr--; break;
            }
        }

        if(flag==1){
            cout << map[rows_tr-1][columns_tr-1]-1 << " step(s) before a loop of " << steps-map[rows_tr-1][columns_tr-1]+1 <<" step(s)"<< endl;
        }
        else cout << steps << " step(s) to exit" << endl;

        cin >> rows >> columns >> entry;
    }

    return 0;
}