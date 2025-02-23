# include <iostream>
using namespace std;

const int N=1e5+10;
int n,k;

//用结构体存储每一块巧克力 
struct Chocolate{
	int l,h;
}chocolate[N];

bool check(int mid){
	
	int num=0;
	for(int i=0;i<n;i++){
		num+=(chocolate[i].l/mid)*(chocolate[i].h/mid);
	}
	//mid越大,num越小。 
	//如果 check(mid) 返回 true，说明当前 mid 是一个可行的解，但可能存在更大的解，因此需要向右搜索
	//如果 check(mid) 返回 false，说明当前 mid 不可行，需要向左搜索。
	if(num>=k) return true;
	return false;
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>chocolate[i].l>>chocolate[i].h;
	}
	
	int l=1,r=1e5;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)){
			l=mid;		
		}
		else r=mid-1;
	}
	cout<<r<<'\n';
	return 0; 
}
