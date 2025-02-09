# include <iostream>
using namespace std;

int n;
int st[16];

void dfs(int u){
	if(u>n){
		for(int i=1;i<=n;i++){
			if(st[i]==1) cout<<i<<" ";
		}
		cout<<endl;
		return ;
	}
	st[u]=false;
	dfs(u+1);
	
	st[u]=true;
	dfs(u+1);
	
}

int main(){
	
	cin>>n;
	
	dfs(1);
	
	return 0;
}
