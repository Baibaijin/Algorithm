# include <iostream>
using namespace std;

const int N=1e5+10,INF=0x3f3f3f3f;
int w[N];
//��i���ʱ��,���гֹ���Ϊ0/1���������ķ����� 
int f[N][2]; 

int main(){
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	
	//f[0][1]+w[1]����f[0][1]�Ƴ����ģ���Ϊ��һ��ֻ��������߲���
	f[0][1]=-INF;
	
	for(int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]+w[i]);
		f[i][1]=max(f[i-1][1],f[i-1][0]-w[i]);
	}
	
	cout<<f[n][0];
	
	return 0;
}
