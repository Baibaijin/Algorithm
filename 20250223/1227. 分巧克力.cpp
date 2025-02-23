# include <iostream>
using namespace std;

const int N=1e5+10;
int n,k;

//�ýṹ��洢ÿһ���ɿ��� 
struct Chocolate{
	int l,h;
}chocolate[N];

bool check(int mid){
	
	int num=0;
	for(int i=0;i<n;i++){
		num+=(chocolate[i].l/mid)*(chocolate[i].h/mid);
	}
	//midԽ��,numԽС�� 
	//��� check(mid) ���� true��˵����ǰ mid ��һ�����еĽ⣬�����ܴ��ڸ���Ľ⣬�����Ҫ��������
	//��� check(mid) ���� false��˵����ǰ mid �����У���Ҫ����������
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
