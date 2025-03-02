# include <iostream>
using namespace std;
const int N=51,MOD=1000000007;
int value[N][N];//每个格子中的宝物价值 
int n,m,k;
			//行  列   当前宝物最大值  宝物数量 
int action(int x,int y,int valueMax,int cnt){
	
	if(x>n||y>m||cnt>k) return 0;//判断边界
	
	
	if(x==n&&y==m){//到达终点
		if(cnt==k||(value[n][m]>valueMax&&cnt+1==k)){//满足方案 
			return 1;//将1返回给下一次action中的res， 
		}
	}
	long long res=0;
	if(value[x][y]>valueMax){
		res+=action(x+1,y,value[x][y],cnt+1);//拿宝物向下走
		res+=action(x,y+1,value[x][y],cnt+1);//拿宝物向右走
		res+=action(x+1,y,valueMax,cnt);//不拿宝物向下走 
		res+=action(x,y+1,valueMax,cnt);//不拿宝物向右走 
	}
	else{
		res+=action(x+1,y,valueMax,cnt);//不拿宝物向下走 
		res+=action(x,y+1,valueMax,cnt);//不拿宝物向右走 		
	}
	return res;
}

int main(){
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>value[i][j];
		}
	}

	cout<<action(1,1,-1,0)%MOD;
	
	return 0;
}
