#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>

using namespace std;

map<char,int> find_pos(char *name)
{
  map<char,int> m;
  m[name[0]] = 0;
  m[name[1]] = 1;
  m[name[2]] = 2;
  m[name[3]] = 3;
  m[name[4]] = 4;
  m[name[5]] = 5;
  m[name[6]] = 6;
  m[name[7]] = 7;
  return m;
}

int main(void) {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    char column_name[9] = "abcdefgh";
    char row_name[9] = "87654321";
    map<char,int> get_column = find_pos(column_name);
    map<char,int> get_row = find_pos(row_name); 
    char chess[8][8] = {'\0'};

    char buf[100];

    cin >> buf;
    cin >> buf;
    char *p;
    p = strtok(buf, ",");
    while (p != NULL){
        if(strlen(p)==3) chess[get_row[p[2]]][get_column[p[1]]] = p[0];
        else if(strlen(p)==2) chess[get_row[p[1]]][get_column[p[0]]] = 'P';
        p = strtok (NULL, ",");
    }

    cin >> buf;
    cin >> buf;
    p = strtok(buf, ",");
    while (p != NULL){
        if(strlen(p)==3) chess[get_row[p[2]]][get_column[p[1]]] = p[0]+32;
        else if(strlen(p)==2) chess[get_row[p[1]]][get_column[p[0]]] = 'p';
        p = strtok (NULL, ",");
    }
    
    cout << "+---+---+---+---+---+---+---+---+" << endl;
    for(int row_tr=0;row_tr<8;row_tr++){
        cout << "|";
        for(int column_tr=0;column_tr<8;column_tr++){
            char color;
            if((column_tr+row_tr)%2==0) color = '.';
            else color = ':';
            if(chess[row_tr][column_tr]!='\0') cout << color << chess[row_tr][column_tr] << color << '|';
            else cout << color << color << color << '|';
        }
        cout << endl;
        cout << "+---+---+---+---+---+---+---+---+" << endl;
    }
    


    
    return 0;
}