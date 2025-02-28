# include <iostream>
# include <algorithm>
using namespace std;

const int N=1e5+10;
struct Order{
	int time;
	int shop;
	bool operator < (const Order&other) const{
		return time<other.time;
	}
}order[N];

int n,m,t;
bool st[N]={false};//存储店铺n是减少优先级还是增加优先级 
int cnt[N]={0};//存储店铺n的优先级 
int res=0;
int main(){
	
	cin>>n>>m>>t;
	
	for(int i=1;i<=m;i++){
		cin>>order[i].time>>order[i].shop;
	}
	
	sort(order+1,order+m+1);
	
	for(int i=1;i<=m;i++){
		cnt[order[i].shop]+=3;
		//所有店铺优先级-1操作
		st[order[i].shop]=true;//店铺标记true，是加的。
		for(int j=1;j<=n;j++){//遍历所有商店 

			if(cnt[j]==0){	//如果是0，不执行-1操作。 
				continue;
			}
			else cnt[j]--;//每个都减一
			//st[j]=false;
			cout<<"shop"<<j<<":"<<cnt[order[j].shop]<<endl;
		}	 

		
		//cout<<"执行+2命令的shop:"<<order[i].shop<<endl<<"shop"<<order[i].shop<<"优先级："<<cnt[order[i].shop]<<endl;
		if(order[i].time>t||i==t){
			if((cnt[order[i].shop]>=5&&st[order[i].shop]==true)||(cnt[order[i].shop]>=3&&st[order[i].shop]==false)){
				res++;
			}
		}
	}
	
	cout<<res<<'\n';
	
	return 0;
}
