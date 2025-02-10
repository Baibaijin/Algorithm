# include <iostream>
using namespace std;

int main(){
	
	double n;
	scanf("%lf",&n);
	
	double l=-1e4,r=1e4;
	while(r-l>=1e-7){
		double mid=(l+r)/2;
		if(mid*mid*mid>=n)r=mid;
		else l=mid; 
	}
	
	printf("%.6lf\n",l);
	
	return 0;
}
