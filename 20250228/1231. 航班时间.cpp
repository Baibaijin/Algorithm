# include <iostream>
using  namespace std;

int getTime(){
	int h1,h2,m1,m2,s1,s2,d=0;
	scanf("%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&d);
	
	//转换成秒去算差值 
	int second=(h2*60*60+m2*60+s2+d*24*60*60)-(h1*60*60+m1*60+s1);
	
	return 	second;
}

int main(){
	
	int n;
	scanf("%d",&n);
	while(n--){
		int time1=getTime();
		int time2=getTime();
		int res=(time1+time2)/2;
		printf("%02d:%02d:%02d\n",res/3600,res/60%60,res%60);
	}
	
	return 0;
}
