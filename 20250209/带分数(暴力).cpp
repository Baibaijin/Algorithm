# include <iostream>
# include <algorithm>
using namespace std;

int n;
bool used[10];
int res = 0;

//2.分隔a,b,c;
//3.判断a+b/c是否等于n
void abc(int num) {
	//用数组存储pow(10,x)，减少重复利用pow()函数，防止超时 
	int pow10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000}; 
    for (int i = 1; i < 7; i++) { // 分隔a,b  题目数据最大是1e7,所以到第七位 
		int a = num / pow10[9-i];
		if(a>n) break;//剪枝优化，如果a以及比n大了，明显不会符合
        for (int j = i + 1; j < 9; j++) { // 分隔b,c
            int b = (num % pow10[9-i]) /pow10[9-j];
            int c = num % pow10[9-j];
            if (c != 0 && (b % c == 0)&& (a + b / c) == n ) {//判断，分母c不能为0且b必须被c整除
            	//cout<<a<<"+"<<b<<"/"<<c<<endl;
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
