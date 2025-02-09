#include <iostream>
#include <vector>
using namespace std;

const int N = 5010;
int n;
vector<int> f[N]; // f[k] �洢�� k ��̨�׵��߷������߾��ȱ�ʾ��

// �߾��ȼӷ�
vector<int> add(vector<int>& a, vector<int>& b) {
    vector<int> c;
    int t = 0; // ��λ
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10); // ��ǰλ
        t /= 10; // ��λ
    }
    if (t) c.push_back(t); // �������λ��λ
    return c;
}

int main() {
    cin >> n;

    // ��ʼ��
    f[1] = {1}; // �� 1 ��̨���� 1 ���߷�
    f[2] = {2}; // �� 2 ��̨���� 2 ���߷�

    // ���Ƽ���
    for (int k = 3; k <= n; k++) {
        f[k] = add(f[k - 1], f[k - 2]); // f[k] = f[k-1] + f[k-2]
    }

    // �����������������
    for (int i = f[n].size() - 1; i >= 0; i--) {
        cout << f[n][i];
    }
    cout << endl;

    return 0;
}
