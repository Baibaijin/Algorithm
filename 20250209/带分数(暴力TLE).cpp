# include <iostream>
# include <algorithm>
# include <cmath>
using namespace std;

int n;
bool used[10];
int res = 0;

//2.�ָ�a,b,c;
//3.�ж�a+b/c�Ƿ����n
void abc(int num) {
    for (int i = 1; i < 9; i++) { // �ָ�a,b
        for (int j = i + 1; j < 9; j++) { // �ָ�b,c
            int a = num / pow(10, 9 - i);
            int b = (num % (int)pow(10, 9 - i)) / (int)pow(10, 9 - j);
            int c = num % (int)pow(10, 9 - j);
            if (c != 0 && (b % c == 0)&& (a + b / c) == n ) {//�жϣ���ĸc����Ϊ0��b���뱻c���� 
                res++;
            }
        }
    }
}
//1.ȫ��������1-9��
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
