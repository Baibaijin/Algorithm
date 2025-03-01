# include <iostream>
using namespace std;

const int N=1010,MOD=1e8+7;
int f[N][N];

int getmod(int a,int b){
	return (a%b+b)%b;//保证取完模的数一定是正数 
}

int main(){
	
	int n,s,a,b;
	cin>>n>>s>>a>>b;
	
	f[0][0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			//模运算的加减法是封闭的。所以(C+i*a)%n=j和C=(j-i-a)%n相同
			//对n取模是因为同余原理,(C+i*a)%n==s%n，再由(C+i*a)%n经过转换得到 
			f[i][j]=(f[i-1][getmod(j-a*(n-i),n)]+f[i-1][getmod(j+b*(n-i),n)])%MOD;
		}
	}
	
	cout<<f[n-1][getmod(s,n)];//一共有n项，第一项是未知的，所以我们需要进行+a或者-b的操作只有后面的n-1项
	
	return 0;
}
