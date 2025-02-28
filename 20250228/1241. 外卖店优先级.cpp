# include <iostream>
# include <algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
PII order[N];
int score[N],last[N];
bool st[N];
int main(){
	int m,n,T;
	cin>>n>>m>>T;
	for(int i=0;i<m;i++) cin>>order[i].first>>order[i].second;
	
	sort(order, order+m);
	
	for(int i=0;i<m;){
		int j=i;
		while(j<m&&order[j]==order[i]) j++;
		int t=order[i].first,id=order[i].second,cnt=j-i;
		i=j;
		
		//����tʱ��֮ǰ����Ϣ
		score[id]-=t-last[id]-1;
		if(score[id]<0) score[id]=0;
		if(score[id]<=3) st[id]=false;
		
		//����tʱ�̵���Ϣ 
		score[id]+=cnt*2;
		if(score[id]>5) st[id]=true;
		
		last[id]=t;
	}
	
	//�жϵ����ʱ��û�ж�������� 
	for(int i=1;i<=n;i++){
		if(last[i]<T){
			score[i]-=T-last[i];
			if(score[i]<=3) st[i]=false;
		}
	}
	
	int res=0;
	for(int i=1;i<=n;i++) res+=st[i];
	 
	cout<<res;
	
	return 0;
}
