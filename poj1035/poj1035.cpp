# include <iostream>
# include <string.h>

using namespace std;

int found[10002];
unsigned int dict[10002];
char dict_str[10002][20];
int ht[20000];

int dict_num;

// BKDR Hash Function
int BKDRHash(char *str_old)
{
    char *str = str_old;
    int seed = 131; // 31 131 1313 13131 131313 etc..
    int hash = 0;
    
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
 
    return ((hash%20000+20000)%20000);
}

char* del_char(char *str_old, int i){
    char *str = str_old;
    int tr = 0;
    char *tmp = new char[20];
    char *p = tmp;
    while(*str){
        if(tr != i){
            *p = *str;
            p++;
        }
        str++;
        tr++;
    }
    *p = *str;
    // cout << tmp << endl;
    return tmp;
}
char* rep_char(char *str_old, int i, char r){
    char *str = str_old;
    int tr = 0;
    char *tmp = new char[20];
    char *p = tmp;
    while(*str){
        if(tr != i) *p = *str;
        else *p = r;
        p++;
        str++;
        tr++;
    }
    *p = *str;
    // cout << tmp << endl;
    return tmp;
}
char* insert_char(char *str_old, int i, char r){
    char *str = str_old;
    int tr = 0;
    char *tmp = new char[20];
    char *p = tmp;
    while(*str || tr<=i){
        if(tr != i){
            *p = *str;
            p++;
            str++;
        }
        else{
            *p = r;
            p++;
        }
        tr++;
    }
    *p = *str;
    // cout << tmp << endl;
    return tmp;
}
void find(char *str){
    cout << ":";

    memset(found, 0, sizeof(found));
    int length = 0;
    char *p = str;
    while(*p){
        p++;
        length++;
    }

    int candidate;

    for(int i = 0; i < length;i++){
        char *tmp = del_char(str, i);
        candidate = ht[BKDRHash(tmp)];
 
        if(candidate != 0 && !strcmp(tmp,dict_str[candidate])) found[candidate] = 1;
    }

    for(int i = 0; i < length;i++){
        for(char c = 'a'; c<='z'; c++){
            char *tmp = rep_char(str,i,c);
            candidate =  ht[BKDRHash(tmp)];
            if(candidate != 0 && !strcmp(tmp,dict_str[candidate])) found[candidate] = 1;
        }
    }

    for(int i = 0; i < length+1;i++){
        for(char c = 'a'; c<='z'; c++){
            char *tmp = insert_char(str,i,c);
            candidate =  ht[BKDRHash(tmp)];
            if(candidate != 0 && !strcmp(tmp,dict_str[candidate])) found[candidate] = 1;
        }
    }

    for(int i = 1; i<=dict_num; i++){
        if(found[i]) cout  << " " << dict_str[i];
    }
    cout << endl;

}



int main(){

    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    dict_num = 0;
    char tmp[20];

    memset(ht, 0, sizeof(ht));
    while(cin.getline(tmp, 20)){
        if(tmp[0] == '#') break;
        // cout << tmp << endl;
        strcpy(dict_str[++dict_num], tmp);
        ht[BKDRHash(tmp)] = dict_num;
    }
    while(cin.getline(tmp, 20)){
        if(tmp[0] == '#') break;
        cout << tmp;
        if(ht[BKDRHash(tmp)] && !strcmp(tmp,dict_str[ht[BKDRHash(tmp)]])) cout << " is correct" << endl;
        else find(tmp);
    }
    return 0;

}

