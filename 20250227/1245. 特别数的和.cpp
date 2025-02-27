# include <iostream>
using namespace std;

const int N=1e4;
int n;
long long res=0;

int main(){
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		int x=i;
		while(x){
			int t=x%10;
			if(t==1||t==2||t==0||t==9){
				res+=i;
				//printf("%d\n",i);
				break;
			}
			x/=10;
		}		
	}

	
	printf("%lld",res);
	
	return 0;
} 
