# include <iostream>
# include <algorithm>
using namespace std;

const int N=5e6+10;

struct Sum{
	int s,c,d;
	bool operator <(const Sum&Other) const{
		if(s!=Other.s) return s<Other.s;
		if(c!=Other.c) return c<Other.c;
		return d<Other.d; 
	}	
}sum[N];

int main(){
	
	int n;
	int m=0;
	cin>>n;
	
	//确定c,d的值,把c*c和d*d的值保存下来 
	for(int c=0;c*c<=n;c++){
		for(int d=c;c*c+d*d<=n;d++){
			sum[m++]={c*c+d*d,c,d};
		}
	}
	
	sort(sum,sum+m);
	
	for(int a=0;a*a<=n;a++){
		for(int b=a;b*b+a*a<=n;b++){
			int t=n-a*a-b*b;//用t存储差值,也就是c*c和d*d的值
			int l=0,r=m-1;
			while(l<r){
				int mid=l+r>>1;
				if(sum[mid].s>=t) r=mid;
				else l=mid+1; 
			}
			if(sum[l].s==t){
				cout<<a<<" "<<b<<" "<<sum[l].c<<" "<<sum[l].d;
				return 0;
			}
		}
	}
	
	return 0;
}
