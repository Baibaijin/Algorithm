# include <iostream>
using namespace std;
const int N=55,MOD=1000000007;
int n,m,k;
int value[N][N];
//   行 列 个数 价值 
int f[N][N][13][14];//表示所有从[1][1]到[i][j]的取了k件物品且最大价值为c的所有合法方案数 
int main(){
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>value[i][j];
			value[i][j]++; 
		}
	}
	
	f[1][1][1][value[1][1]]=1;//取第一个的方案数 
	f[1][1][0][0]=1;//不取第一个的方案数
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			for(int u=0;u<=k;u++){//个数 
				for(int v=0;v<=13;v++){//价值 
					int &val=f[i][j][u][v];
					//不取的方案 
					val=(val+f[i-1][j][u][v])%MOD;//从上往下走
					val=(val+f[i][j-1][u][v])%MOD;//从左往右走
					//取了的方案 
					if(v==value[i][j]){
						for(int c=0;c<v;c++){
							val=(val+f[i-1][j][u-1][c])%MOD;
							val=(val+f[i][j-1][u-1][c])%MOD;
						}
					}
				}
			}
		}
	}
	int res=0;
	for(int i=0;i<=13;i++) res=(res+f[n][m][k][i])%MOD;
	cout<<res;
	return 0;
}
