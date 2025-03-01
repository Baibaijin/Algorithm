# include <iostream>
# include <algorithm>
using namespace std;

const int N=1e3+10;
int a[N];
int f[N];//存放以i结尾的数的 最长上升子序列 

int main(){
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int i=0;i<n;i++){
		f[i]=1;
		for(int j=0;j<i;j++){
			if(a[i]>a[j]) f[i]=max(f[i],f[j]+1);
		}
	}
	
	int res=f[0];
	for(int i=0;i<n;i++) res=max(f[i],res);
	
	cout<<res;
	
	return 0;
}
