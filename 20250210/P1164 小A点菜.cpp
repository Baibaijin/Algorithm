# include <iostream>
using namespace std;

const int N=1e3+10,M=1e4+10;
int a[N];
int n,m;
int f[N][M]={0};//��ǰi�ֲ�Ʒ�պû���jԪ��������� 

int main(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j<a[i]) f[i][j]=f[i-1][j];  //�����i����Ʒ��ֻ�ܲ��� 
			if(j>a[i]) f[i][j]=f[i-1][j]+f[i-1][j-a[i]];  //�����i����ƷǮ���ж࣬�����͵������i����Ʒ���ϲ����i����Ʒ�ĺ� 
			if(j==a[i]) f[i][j]=f[i-1][j]+1;	//Ǯ�պù����� 
		}
	}
	
	cout<<f[n][m]<<endl;	
	return 0;
}
