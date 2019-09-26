# include <iostream>
# include <string.h>

using namespace std;

struct hashnode{
    // hashnode(int now)
	// {
	// 	this->now=now;
	// 	this->next=NULL;
	// };
    int now;
    hashnode* next;
};

int found[10002];
unsigned int dict[10002];
char dict_str[10002][20];
hashnode ht[10000];

int dict_num;

// BKDR Hash Function
int BKDRHash(char *str)
{
    int seed = 131; // 31 131 1313 13131 131313 etc..
    int hash = 0;
    
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
    hash = hash & 0x7FFFFFFF;
    if(hash >0) return hash%10000;
    else return (-hash)%10000;
}

char* del_char(char *str, int i){
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
char* rep_char(char *str, int i, char r){
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
char* insert_char(char *str, int i, char r){
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


    for(int i = 0; i < length;i++){
        char *tmp = del_char(str, i);
        hashnode *node_tmp = &ht[BKDRHash(tmp)];
        while(node_tmp != NULL && node_tmp->now != 0){
            if(!strcmp(tmp,dict_str[node_tmp->now])){
                found[node_tmp->now] = 1;
                break;
            }
            node_tmp = node_tmp->next;
        }
    }

    for(int i = 0; i < length;i++){
        for(char c = 'a'; c<='z'; c++){
            char *tmp = rep_char(str,i,c);
            hashnode *node_tmp = &ht[BKDRHash(tmp)];
            while(node_tmp != NULL && node_tmp->now != 0){
                if(!strcmp(tmp,dict_str[node_tmp->now])){
                    found[node_tmp->now] = 1;
                    break;
                }
                node_tmp = node_tmp->next;
            }
        }
    }

    for(int i = 0; i < length+1;i++){
        for(char c = 'a'; c<='z'; c++){
            char *tmp = insert_char(str,i,c);
            hashnode *node_tmp = &ht[BKDRHash(tmp)];
            while(node_tmp != NULL && node_tmp->now != 0){
                if(!strcmp(tmp,dict_str[node_tmp->now])){
                    found[node_tmp->now] = 1;
                    break;
                }
                node_tmp = node_tmp->next;
            }
        }
    }

    for(int i = 1; i<=dict_num; i++){
        if(found[i]) cout  << " " << dict_str[i];
    }
    cout << endl;

}



int main(){

    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    dict_num = 0;
    char tmp[20];

    while(cin.getline(tmp, 20)){
        if(tmp[0] == '#') break;
        // cout << tmp << endl;
        strcpy(dict_str[++dict_num], tmp);
        // cout << BKDRHash(tmp) << endl;
        hashnode *node_tmp = &ht[BKDRHash(tmp)];
        while(node_tmp->next != NULL) node_tmp = node_tmp->next;
        if(node_tmp->now == 0) node_tmp->now = dict_num;
        else{
            hashnode *new_node = new hashnode();
            new_node->now = dict_num;
            node_tmp->next = new_node;
        }
    }
    while(cin.getline(tmp, 20)){
        if(tmp[0] == '#') break;
        cout << tmp;
        hashnode *node_tmp = &ht[BKDRHash(tmp)];
        bool flag = true;
        while(node_tmp != NULL && node_tmp->now != 0){
            if(!strcmp(tmp,dict_str[node_tmp->now])){
                flag = false;
                cout << " is correct" << endl;
                break;
            }
            node_tmp = node_tmp->next;
        }
        if(flag) find(tmp);
    }
    return 0;

}

