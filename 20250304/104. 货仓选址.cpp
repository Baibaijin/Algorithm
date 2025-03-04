# include <iostream>
# include <algorithm>
using namespace std;

const int N=1e5+10;
int a[N],c[N];
int n;

int main(){
	
	cin>>n;
	
	for(int i=0;i<n;i++) cin>>a[i];
	
	int sum=0;
	for(int i=0;i<n;i++) sum+=a[i];
	int avg=sum/n;
	
	for(int i=n-1;i>=0;i--){
		c[i]=c[i+1]+avg-a[i];
	}
	c[0]=0;
	
	sort(c,c+n);
	
	long long res=0;
	for(int i=0;i<n;i++){
		res+=abs(c[i]-c[n/2]);
	}
	
	cout<<res;
	
	return 0;
}
