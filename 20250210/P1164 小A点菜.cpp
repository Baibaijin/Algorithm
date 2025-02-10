# include <iostream>
using namespace std;

const int N=1e3+10,M=1e4+10;
int a[N];
int n,m;
int f[N][M]={0};//买前i种菜品刚好花光j元的情况总数 

int main(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j<a[i]) f[i][j]=f[i-1][j];  //买不起第i个菜品，只能不买 
			if(j>a[i]) f[i][j]=f[i-1][j]+f[i-1][j-a[i]];  //买完第i个菜品钱还有多，总数就等于买第i个菜品加上不买第i个菜品的和 
			if(j==a[i]) f[i][j]=f[i-1][j]+1;	//钱刚好够，买 
		}
	}
	
	cout<<f[n][m]<<endl;	
	return 0;
}
