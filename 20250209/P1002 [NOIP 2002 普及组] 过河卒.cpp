# include <iostream>
using namespace std;

const int N=21;
long long f[N][N];//题目数量太大 
int n,m,x,y;
bool st[N][N];
int res=0;
int dx[9]={1,1,-1,-1,2,2,-2,-2,0},dy[9]={2,-2,2,-2,1,-1,1,-1,0};//定义马的坐标和本体 

int main(){
	
	cin>>n>>m>>x>>y;
	
	//马的坐标标记为不可到达 
	for(int i=0;i<9;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a>=0&&a<=n&&b>=0&&b<=m){
			st[a][b]=true;
		}
	}
	
	f[0][0]=1;//初始化能走到就说明至少有一条路 

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(st[i][j]) continue;
			if (i>0&&!st[i - 1][j]) f[i][j]+=f[i-1][j];//从上面来 
			if (j>0&&!st[i][j - 1]) f[i][j]+=f[i][j-1];//从左边来	
		}
	}
	
	
	cout<<f[n][m]<<endl;
	return 0;
}
