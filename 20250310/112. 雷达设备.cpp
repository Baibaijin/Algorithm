# include <iostream>
# include <cmath>
# include <algorithm>
using namespace std;

const int N=1010;

struct Dist{
	double l,r;
	bool operator < (const Dist&other) const{
		return r<other.r;
	}
}dist[N];

int main(){
	
	int n,d;
	cin>>n>>d;
	bool failed=false;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		if(y>d) failed=true;
		else{
			double len=sqrt(d*d-y*y);
			dist[i].l=x-len;
			dist[i].r=x+len;		
		}
	}
	
	if(failed){
		cout<<"-1"<<'\n';
	}else{
		sort(dist,dist+n);
		int cnt=0;
		double last=-0x3f3f3f3f;
		for(int i=0;i<n;i++){
			if(last<dist[i].l){
				cnt++;
				last=dist[i].r;
			}
		}
		cout<<cnt<<'\n';
	}
	
	return 0;
} 
