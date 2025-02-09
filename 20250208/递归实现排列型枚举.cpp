# include <iostream>
using namespace std;

int n;

int state[10];
bool used[10];

void dfs(int u){
	if(u>n){
		for(int i=1;i<=n;i++)cout<<state[i]<<" ";
		cout<<endl;	
	}
	
	for(int i=1;i<=n;i++){
		if(!used[i]){
			
			state[u]=i;
			used[i]=true;
			
			dfs(u+1);
			
			//»Ö¸´ÏÖ³¡ 
			state[u]=0;
			used[i]=false;
		}
	}
	
}

int main(){
	
	cin>>n;
	dfs(1);
	
	return 0;
}
