# include <iostream>
using namespace std;
int main(){
	
	int w,m,n;
	cin>>w>>m>>n;
	m--,n--;//映射成从0开始，方便计算行号和列号  精髓 
	int x1=m/w;
	int x2=n/w;
	int y1=m%w;
	int y2=n%w;
	
	//奇数行翻转 
	if(x1&1) y1=w-1-y1;
	if(x2&1) y2=w-1-y2;
	
	cout<<abs(x1-x2)+abs(y1-y2);
	
	return 0;
}
