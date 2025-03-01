# include <iostream>
using namespace std;

const int N=1010,MOD=1e8+7;
int f[N][N];

int getmod(int a,int b){
	return (a%b+b)%b;//��֤ȡ��ģ����һ�������� 
}

int main(){
	
	int n,s,a,b;
	cin>>n>>s>>a>>b;
	
	f[0][0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			//ģ����ļӼ����Ƿ�յġ�����(C+i*a)%n=j��C=(j-i-a)%n��ͬ
			//��nȡģ����Ϊͬ��ԭ��,(C+i*a)%n==s%n������(C+i*a)%n����ת���õ� 
			f[i][j]=(f[i-1][getmod(j-a*(n-i),n)]+f[i-1][getmod(j+b*(n-i),n)])%MOD;
		}
	}
	
	cout<<f[n-1][getmod(s,n)];//һ����n���һ����δ֪�ģ�����������Ҫ����+a����-b�Ĳ���ֻ�к����n-1��
	
	return 0;
}
