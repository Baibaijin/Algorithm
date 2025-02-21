# include <iostream>
# include <algorithm>
# include <cmath>
using namespace std;
int main(){
	
	int n;
	cin>>n;
	
	for(int i=0;i*i<=n;i++){
		for(int j=i;j*j+i*i<=n;j++){
			for(int k=j;k*k+j*j+i*i<=n;k++){
				int t=n-i*i-j*j-k*k;
				int m=sqrt(t);
				if(m*m==t){
					cout<<i<<" "<<j<<" "<<k<<" "<<m<<endl;
					return 0;						
				}
			}					
		}
	}
	
	return 0;
}
