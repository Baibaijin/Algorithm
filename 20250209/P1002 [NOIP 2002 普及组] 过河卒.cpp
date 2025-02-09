# include <iostream>
using namespace std;

const int N=21;
long long f[N][N];//��Ŀ����̫�� 
int n,m,x,y;
bool st[N][N];
int res=0;
int dx[9]={1,1,-1,-1,2,2,-2,-2,0},dy[9]={2,-2,2,-2,1,-1,1,-1,0};//�����������ͱ��� 

int main(){
	
	cin>>n>>m>>x>>y;
	
	//���������Ϊ���ɵ��� 
	for(int i=0;i<9;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a>=0&&a<=n&&b>=0&&b<=m){
			st[a][b]=true;
		}
	}
	
	f[0][0]=1;//��ʼ�����ߵ���˵��������һ��· 

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(st[i][j]) continue;
			if (i>0&&!st[i - 1][j]) f[i][j]+=f[i-1][j];//�������� 
			if (j>0&&!st[i][j - 1]) f[i][j]+=f[i][j-1];//�������	
		}
	}
	
	
	cout<<f[n][m]<<endl;
	return 0;
}
