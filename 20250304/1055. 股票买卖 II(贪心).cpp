# include <iostream>
using namespace std;

const int N=1e5+10;
int value[N];
int n;

int main(){
	
	cin>>n;
	
	for(int i=1;i<=n;i++) cin>>value[i];
	
	int res=0;
	for(int i=1;i<n;i++){
		if(value[i+1]>value[i]) res+=value[i+1]-value[i];
	}
	cout<<res;
	
	return 0;
}
