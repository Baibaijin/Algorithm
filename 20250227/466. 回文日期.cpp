# include <iostream>
using namespace std;

int pow10[8]={1,10,100,1000,10000,100000,1000000,10000000};
int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

//检查日期是否合法 
bool check(int n){
	int year=n/pow10[4],month=n%pow10[4]/pow10[2],day=n%pow10[2];
	if(month>=13) return false;
	if(month!=2&&day>months[month])	return false;
	if(month==2){
		bool leap=((year%4==0&&year%100!=0)||year%400==0);
		if(day>28+leap) return false;
	}
	return true;
}

int main(){
	
	int n,m;
	cin>>n>>m;
	
	int cnt=0;
	for(int i=1000;i<10000;i++){
		int res=i,x=i;//x是要拼接的,res是被拼接的 
		for(int j=1;j<=4;j++){
			res=res*10+x%10;
			x/=10;
		}
		if(res<=m&&res>=n&&check(res)){
			cnt++;
		}
	}
	
	cout<<cnt;
	
	return 0;
}
