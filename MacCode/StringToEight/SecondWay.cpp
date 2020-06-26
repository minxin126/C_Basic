//
// Created by minx wang on 2020/6/24.
//
#include "iostream"
#include "string"

using namespace std;

int mainsplit() {
    int n;
    string s[100];
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        for (int i = 0; i < n; ++i) {
            if (s[i].length() % 8 != 0) {
                s[i] += "00000000";
            }
            while (s[i].length() >= 8) {
                cout << s[i].substr(0, 8) << endl;
                s[i] = s[i].substr(8);
            }
        }
    }
    return 0;
}

