#include <iostream>
#include <vector>
using namespace std;

const int N = 5010;
int n;
vector<int> f[N]; // f[k] 存储第 k 阶台阶的走法数（高精度表示）

// 高精度加法
vector<int> add(vector<int>& a, vector<int>& b) {
    vector<int> c;
    int t = 0; // 进位
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10); // 当前位
        t /= 10; // 进位
    }
    if (t) c.push_back(t); // 处理最高位进位
    return c;
}

int main() {
    cin >> n;

    // 初始化
    f[1] = {1}; // 第 1 阶台阶有 1 种走法
    f[2] = {2}; // 第 2 阶台阶有 2 种走法

    // 递推计算
    for (int k = 3; k <= n; k++) {
        f[k] = add(f[k - 1], f[k - 2]); // f[k] = f[k-1] + f[k-2]
    }

    // 输出结果（逆序输出）
    for (int i = f[n].size() - 1; i >= 0; i--) {
        cout << f[n][i];
    }
    cout << endl;

    return 0;
}
