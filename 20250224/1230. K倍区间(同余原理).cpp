# include <iostream>
using namespace std;

const int N=1e5+10;
long long s[N]={0},cnt[N]={0};

int main(){
	
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
		s[i]+=s[i-1];//前缀和处理 
	}
	
	long long res=0;
	cnt[0]=1;//因为余数为零表示自身就是一个k倍区间，要特殊处理一下 
	//同余原理 
	for(int i=1;i<=n;i++){
		res+=cnt[s[i]%k];//和s[r]的余数相同，因为要两个才能算是一个区间，所以cnt++放在后面执行 
		cnt[s[i]%k]++;
	}
	printf("%lld",res);
	
	return 0;
}
