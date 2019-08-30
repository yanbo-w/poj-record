#include <iostream>
#include <map>

using namespace std;

map<char,int> create_map()
{
  map<char,int> m;
  m['K'] = 0;
  m['Q'] = 1;
  m['R'] = 2;
  m['B'] = 3;
  m['N'] = 4;
  m['P'] = 5;
  m['k'] = 6;
  m['q'] = 7;
  m['r'] = 8;
  m['b'] = 9;
  m['n'] = 10;
  m['p'] = 11;
  return m;
}

map<char,int> piece_kind = create_map();

int main(void) {
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int ***chess;
    chess = new int **[12];
    int chess_num[12] = {0};
    for(int i =0; i<12; i++){
        chess[i] = new int *[10];
    }

    for(int row_tr=0; row_tr<8; row_tr++){
        char buf[40];
        cin >> buf;
        cin >> buf;
        // cout << buf <<endl;
        for(int column_tr=0; column_tr<8; column_tr++){
            // cout << buf[column_tr*4+2] << endl;
            if(buf[column_tr*4+2]==':' || buf[column_tr*4+2]=='.') continue;
            int piece_kind_t = piece_kind[buf[column_tr*4+2]];
            chess[piece_kind_t][chess_num[piece_kind_t]] = new int[2];
            chess[piece_kind_t][chess_num[piece_kind_t]][0] = row_tr;
            chess[piece_kind_t][chess_num[piece_kind_t]][1] = column_tr;
            chess_num[piece_kind_t]++;
        }
    }

    char piece_name[13] = "KQRBNPKQRBNP";
    piece_name[5] = '\0';
    piece_name[11] = '\0';
    char column_name[9] = "abcdefgh";
    char row_name[9] = "87654321";

    cout << "White: ";

    for(int i =0; i<5; i++){
        int turn[8][10] = {0};
        int turn_num[8] = {0};
        for(int j=0; j<chess_num[i]; j++){
            turn[chess[i][j][0]][turn_num[chess[i][j][0]]] = chess[i][j][1];
            turn_num[chess[i][j][0]]++;
        }
        for(int j=7; j>-1; j--){
            for(int k=0;k<turn_num[j]; k++){
                cout << piece_name[i] << column_name[turn[j][k]] << row_name[j] << ',';
            }
        }
    }

    int turn[8][10] = {0};
    int turn_num[8] = {0};
    int total_num = 0;
    for(int j=0; j<chess_num[5]; j++){
        turn[chess[5][j][0]][turn_num[chess[5][j][0]]] = chess[5][j][1];
        turn_num[chess[5][j][0]]++;
        total_num++;
    }
    int tr_num = 0;
    for(int j=7; j>-1; j--){
        for(int k=0;k<turn_num[j]; k++){
            cout << column_name[turn[j][k]] << row_name[j];
            tr_num++;
            if(tr_num!=total_num)  cout << ',';
        }
    }
    
    cout << endl;

    cout << "Black: ";

    for(int i =6; i<11; i++){
        for(int j=0; j<chess_num[i]; j++){
            cout << piece_name[i] << column_name[chess[i][j][1]] << row_name[chess[i][j][0]] << ',';
        }
    }
    for(int j=0; j<chess_num[11]; j++){
        cout << column_name[chess[11][j][1]] << row_name[chess[11][j][0]];
        if(j!=(chess_num[11]-1)) cout << ',';
        }

    cout << endl;
        
    
    return 0;
}