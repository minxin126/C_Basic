//
// Created by minx wang on 2020/6/25.
//
#include "iostream"
#include "stdio.h"
#include <vector>

using namespace std;

//int GetResult(int num, int[] pInput, List pResult) {
//
//}

int main() {
    int N;
    while (cin >> N) {
        vector<int> Data(N, 0);
        vector<int> Dp(N, 1);// all atom as 1
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            cin >> Data[i];//first to save all.
            for (int j = 0; j < i; ++j) {
                if (Data[i] > Data[j])//compare all  front atom.  last big than front.
                    Dp[i] = max(Dp[i], Dp[j] + 1);//i do not know why add 1.
                //another meaning that is dp is data
            }
            ret = max(ret, Dp[i]);// always to compare dp.
        }
        cout << ret << endl;
    }
    return 0;
}

