# include <iostream>
# include <cstring>
using namespace std;

const int N=101;
char target[N],init[N];

void turn(int u){//���Ʒ�ת 
	if(init[u]=='*'){
		init[u]='o';
	}
	else init[u]='*';
	
}

int main(){
	
	cin>>init;//�����ʼ״̬ 
	cin>>target;//����Ŀ��״̬ 
	
	int step=0;
	for(int i=0;i<strlen(target);i++){//������ʼ�����Ŀ������ 
		if(init[i]!=target[i]){//״̬��һ�� 
			step++;//Ҫ���в�����������һ 
			turn(i),turn(i+1);//���з�ת���� 
		}
	}
	
	cout<<step;
	
	return 0;
}
