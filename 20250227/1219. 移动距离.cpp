# include <iostream>
using namespace std;
int main(){
	
	int w,m,n;
	cin>>w>>m>>n;
	m--,n--;//ӳ��ɴ�0��ʼ����������кź��к�  ���� 
	int x1=m/w;
	int x2=n/w;
	int y1=m%w;
	int y2=n%w;
	
	//�����з�ת 
	if(x1&1) y1=w-1-y1;
	if(x2&1) y2=w-1-y2;
	
	cout<<abs(x1-x2)+abs(y1-y2);
	
	return 0;
}
