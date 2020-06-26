//
// Created by minx wang on 2020/6/23.
//
#include "iostream"

using namespace std;

int StringToEight() {
    int num;
    string s;
    cin.get();
    while (cin >> num) {
        getline(cin, s);
        while (s.size() / 8) {
            cout << s.substr(0, 8) << endl;
            s = s.substr(8);
        }
        if (!s.empty()) {
            cout << s;
            size_t i = 8 - s.size();
            while (i--) {
                cout << '0';
            }
            s.clear();
        }
    }
    return 0;
}

int mainStr() {
    StringToEight();
}

