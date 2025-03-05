# include <iostream>
using namespace std;

const int N=35;
int f[N][N];//表示能走到第[i][j]格子的方案数 
int n,m;

int main(){
	
	cin>>n>>m;
	
	f[1][1]=1;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
			if(i==1&&j==1) continue;
			
			if(i%2==0&&j%2==0) f[i][j]=0;
			else{
				f[i][j]+=f[i-1][j];
				f[i][j]+=f[i][j-1];				
			}

		}
	}
	
	cout<<f[n][m];
	
	return 0;
} 
