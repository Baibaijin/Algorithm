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
bool st[N]={false};//�洢����n�Ǽ������ȼ������������ȼ� 
int cnt[N]={0};//�洢����n�����ȼ� 
int res=0;
int main(){
	
	cin>>n>>m>>t;
	
	for(int i=1;i<=m;i++){
		cin>>order[i].time>>order[i].shop;
	}
	
	sort(order+1,order+m+1);
	
	for(int i=1;i<=m;i++){
		cnt[order[i].shop]+=3;
		//���е������ȼ�-1����
		st[order[i].shop]=true;//���̱��true���Ǽӵġ�
		for(int j=1;j<=n;j++){//���������̵� 

			if(cnt[j]==0){	//�����0����ִ��-1������ 
				continue;
			}
			else cnt[j]--;//ÿ������һ
			//st[j]=false;
			cout<<"shop"<<j<<":"<<cnt[order[j].shop]<<endl;
		}	 

		
		//cout<<"ִ��+2�����shop:"<<order[i].shop<<endl<<"shop"<<order[i].shop<<"���ȼ���"<<cnt[order[i].shop]<<endl;
		if(order[i].time>t||i==t){
			if((cnt[order[i].shop]>=5&&st[order[i].shop]==true)||(cnt[order[i].shop]>=3&&st[order[i].shop]==false)){
				res++;
			}
		}
	}
	
	cout<<res<<'\n';
	
	return 0;
}
