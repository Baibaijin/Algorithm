# include <iostream>
using namespace std;

const int N=46;
int n;
long long a[N];

void dfs(int u){
	a[0]=0,a[1]=1;//定义初始化 
	if(u==n){
		for(int i=0;i<n;i++) cout<<a[i]<<" ";
		return;
	}
	
	a[u]=a[u-2]+a[u-1];
	dfs(u+1);//递推
	
}

int main(){
	
	cin>>n;
	if(n==1) cout<<0;//边界问题 
	else dfs(2);
	
	return 0;
}
