# include <iostream>
using namespace std;

const int N=1e5+10;
int n,q;
int a[N];

void find_l(int x){
	int l=0,r=n-1;
	
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid]>=x) r=mid;
		else l=mid+1;
	}
	
	if(a[l]==x) cout<<l<<" ";
	else cout<<-1<<" "; 
	
}

void find_r(int x){
	int l=0,r=n-1;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(a[mid]<=x) l=mid;
		else r=mid-1;
	}
	if(a[r]==x) {
		cout<<r<<endl;
		return ;
	}
	else{
		cout<< "-1"<<endl;
		return ;
	}
}

int main(){
	
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	while(q--){
		int num;
		cin>>num;
		find_l(num);
		find_r(num);
	}
	
	
	return 0;
}
