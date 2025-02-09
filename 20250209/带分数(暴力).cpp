# include <iostream>
# include <algorithm>
using namespace std;

int n;
bool used[10];
int res = 0;

//2.�ָ�a,b,c;
//3.�ж�a+b/c�Ƿ����n
void abc(int num) {
	//������洢pow(10,x)�������ظ�����pow()��������ֹ��ʱ 
	int pow10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000}; 
    for (int i = 1; i < 7; i++) { // �ָ�a,b  ��Ŀ���������1e7,���Ե�����λ 
		int a = num / pow10[9-i];
		if(a>n) break;//��֦�Ż������a�Լ���n���ˣ����Բ������
        for (int j = i + 1; j < 9; j++) { // �ָ�b,c
            int b = (num % pow10[9-i]) /pow10[9-j];
            int c = num % pow10[9-j];
            if (c != 0 && (b % c == 0)&& (a + b / c) == n ) {//�жϣ���ĸc����Ϊ0��b���뱻c����
            	//cout<<a<<"+"<<b<<"/"<<c<<endl;
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
