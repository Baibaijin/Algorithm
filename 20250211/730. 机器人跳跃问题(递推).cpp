# include <iostream>
# include <cmath>
using namespace std;

const int N=1e5+10;
int n; 
int h[N];
double p[N];//���2��n�η�����double����治�������2^1024~2^1024-1 

//�����������ۣ����Եó� E(i+1)=2E(i)-H(i+1);

int main(){
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	
	p[0]=1;
	
	double res=0;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]*2;
		res+=(double)h[i]/p[i];
	}
	
	printf("%d",(int)ceil(res));
	
	return  0;
}
