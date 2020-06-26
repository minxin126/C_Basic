//
// Created by minx wang on 2020/6/18.

//
#include "iostream"
#include "list"
#include "InputString.h"
#include "string"


using namespace std;
typedef list<string> list;

int inputString() {
    string string1 = "I am a student";
    unsigned int iSize = string1.size();

    cout << iSize << endl;
    cout << string1.length() << endl;

    unsigned int i = 0;
    int iCount = 0;

    for (int i = 0; i < iSize; ++i) {
        if (' ' == string1[i]) {
            iCount++;
        }
    }
    cout << iCount << endl;

    return 0;
}

void substr() {
    string string1;
    getline(cin, string1);
    int len = string1.length();
    string strout[100];
    for (int i = 0; i <= len; ++i) {
        strout[i] = string1.substr(len - i, 1);
    }
    for (auto y:strout) {
        cout << y;
    }
}

int maina() {
    substr();
    return 0;
}