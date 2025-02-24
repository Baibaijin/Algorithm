# include <iostream>
# include <cstring>
using namespace std;

const int N=1e5+10;
int s[N],a[N];

int main(){
		
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	a[0]=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		memset(s,0,sizeof s);
		for(int j=i;j<=n;j++){
			s[j]=s[j-1]+a[j];
			if(s[j]%k==0){	
				cnt++;
			}
		}
	}
	cout<<cnt<<'\n';
	
	return 0;
}
