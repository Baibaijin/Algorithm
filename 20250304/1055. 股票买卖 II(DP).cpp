# include <iostream>
using namespace std;

const int N=1e5+10,INF=0x3f3f3f3f;
int w[N];
//第i天的时候,手中持股数为0/1的利润最大的方案数 
int f[N][2]; 

int main(){
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	
	//f[0][1]+w[1]是由f[0][1]推出来的，因为第一天只能买入或者不动
	f[0][1]=-INF;
	
	for(int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]+w[i]);
		f[i][1]=max(f[i-1][1],f[i-1][0]-w[i]);
	}
	
	cout<<f[n][0];
	
	return 0;
}
