# include <iostream>
using namespace std;

int pow10[8]={1,10,100,1000,10000,100000,1000000,10000000};
int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

//判断是否是回文日期 
bool iftrue(int x){
	bool flag=true;
	for(int i=1;i<=4;i++){
		if(x%pow10[i]/pow10[i-1]!=x/pow10[8-i]%10){
			flag=false;
			return flag;
		}
	}
	return flag;
}
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
	for(int i=n;i<=m;i++){
		if(check(i)){
			if(iftrue(i)){
				cnt++;	
			}
		}	
	}
	
	cout<<cnt;
	
	return 0;
}
