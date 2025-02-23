# include <iostream>
using namespace std;

const int N=1e5+10;
int a[N],s[N];

int main(){
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	a[0]=0;
	
	for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
	
	int l,r;
	while(m--){
		cin>>l>>r;
		cout<<s[r]-s[l-1]<<'\n';
	}
	
	return 0;	
}
