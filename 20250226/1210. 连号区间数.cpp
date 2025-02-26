# include <iostream>
# include <algorithm>
# include <cstring>
using namespace std;

const int N=1e4+10;
int n;
int a[N],backup[N]; 
int cnt=0;
bool flag;

int main(){
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int i=0;i<n;i++){
		int maxn=a[i];
		int minn=a[i];
		for(int j=i;j<n;j++){
			maxn=max(maxn,a[j]);
			minn=min(minn,a[j]); 
			if(maxn-minn==j-i) cnt++;
		}		
	}
	
	cout<<cnt<<'\n';
	
	return 0;
}
