//
// Created by minx wang on 2020/6/19.
//

//#include "negativeNumber.h"
#include "iostream"
#include <iomanip>
#include "stdio.h"

using namespace std;
int numin[100];
int negative[10];
int negFlat = 0;
int positiveFlag = 0;


double sum(int n) {
    if (n == 0)
        return numin[0];
        //when n=0,i can not return ,so i have to deal with it.
    else
        return numin[n] + sum(n - 1);
}

int main() {
    int i = 0;
    int l = 0;
    int m = 0;
    //int negative[10];
    char c;
    // cin >> a;
    while (i < 2000) {
        c = getchar();//get input
        if ((c >= '0' && c <= '9')) {
            ungetc(c, stdin);//every time4`
            cin >> numin[l++];
            i++;
            positiveFlag = l;
            //but now i have to deal one problem.the number of number.
        } else if (c == '-') {
            ungetc(c, stdin);
            cin >> negative[m++];//i++ equals to i=i+1;
            negFlat = m;
            i++;
        } else if (c == '\n') {
            break;
        }
    }
    //just for test
//    for (int j = 0; j < i; j++) {
//        cout << "a[" << j << "]:" << numin[j] << endl;
//    }
//    for (int y: negative) {
//        cout << y << " ";
//    }
//    cout << endl;
    cout << negFlat << endl;
    // sum(bigFlat);
    if (positiveFlag != 0) {
        cout << setprecision(1) << fixed << sum(positiveFlag) / positiveFlag;
    } else {
        cout << "0.0";
    }
}

