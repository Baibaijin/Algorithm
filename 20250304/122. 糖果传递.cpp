# include <iostream>
# include <algorithm>
using namespace std;

const int N=1e6+10;
int a[N];
long long c[N];
int n;

int main(){
	
	cin>>n;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	long long sum=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	long long avg=sum/n;
	
	for(int i=n;i>1;i--){
		c[i]=c[i+1]+avg-a[i];
	}
	c[1]=0;
	
	sort(c+1,c+n+1);
	
	long long res=0;
	for(int i=1;i<=n;i++){
		res+=abs(c[i]-c[(n+1)/2]);
	}
	
	cout<<res;
	
	return 0;
}
