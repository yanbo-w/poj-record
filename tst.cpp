# include <iostream>
# include <cstdlib>
# include <time.h>
# include <string.h>

using namespace std;



void tst(char *str){
    cout << "...." << int(str) << endl;
    str++;
    *str = 'a';
}

int main(){
    char tmp1[5] = "abcd";
    char tmp2[] = "abcdedf";
    char *tmp3;
    tmp3 = tmp1;
    char *tmp4;
    tmp4 = new char[5];
    strcpy(tmp4,tmp1);

    cout << "-------------------------" << endl;
    tst(tmp1);
    cout << int(&tmp1) << " "<< tmp1 << endl;
    cout << "-------------------------" << endl;

    tst(tmp2);
    cout << int(&tmp2) << " "<< tmp2 << endl;
    cout << "-------------------------" << endl;

    tst(tmp3);
    cout << int(&tmp3) << " "<< tmp3 << endl;
    cout << "-------------------------" << endl;

    tst(tmp4);
    cout << int(&tmp4) << " "<< tmp4 << endl;
    cout << "-------------------------" << endl;
}