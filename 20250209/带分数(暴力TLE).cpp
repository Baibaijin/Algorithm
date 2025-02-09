# include <iostream>
# include <algorithm>
# include <cmath>
using namespace std;

int n;
bool used[10];
int res = 0;

//2.分隔a,b,c;
//3.判断a+b/c是否等于n
void abc(int num) {
    for (int i = 1; i < 9; i++) { // 分隔a,b
        for (int j = i + 1; j < 9; j++) { // 分隔b,c
            int a = num / pow(10, 9 - i);
            int b = (num % (int)pow(10, 9 - i)) / (int)pow(10, 9 - j);
            int c = num % (int)pow(10, 9 - j);
            if (c != 0 && (b % c == 0)&& (a + b / c) == n ) {//判断，分母c不能为0且b必须被c整除 
                res++;
            }
        }
    }
}
//1.全排列数字1-9；
void dfs(int u, int num) {
    if (u > 9) {
        abc(num);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (!used[i]) {
            used[i] = true;
            dfs(u + 1, num * 10 + i);
            used[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1, 0);
    cout << res << endl;
    return 0;
}
