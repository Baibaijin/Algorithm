# include <iostream>
using namespace std;

const int N=1e5+10;
int n;
int h[N];

bool check(int x){
	for(int i=1;i<=n;i++){
		x=2*x-h[i];
		if(x<0) return false;
		if(x>1e5) return true;
	}
	return true;
}

//Çó×ó¶Ëµã
void find_l(){
	int l=1,r=1e5;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d",l);
}

int main(){
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	
	find_l();
	
	return 0;
}
