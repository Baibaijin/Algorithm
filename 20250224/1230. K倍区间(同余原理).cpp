# include <iostream>
using namespace std;

const int N=1e5+10;
long long s[N]={0},cnt[N]={0};

int main(){
	
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
		s[i]+=s[i-1];//ǰ׺�ʹ��� 
	}
	
	long long res=0;
	cnt[0]=1;//��Ϊ����Ϊ���ʾ�������һ��k�����䣬Ҫ���⴦��һ�� 
	//ͬ��ԭ�� 
	for(int i=1;i<=n;i++){
		res+=cnt[s[i]%k];//��s[r]��������ͬ����ΪҪ������������һ�����䣬����cnt++���ں���ִ�� 
		cnt[s[i]%k]++;
	}
	printf("%lld",res);
	
	return 0;
}
