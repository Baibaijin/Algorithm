# include <iostream>
using namespace std;
const int N=51,MOD=1000000007;
int value[N][N];//ÿ�������еı����ֵ 
int n,m,k;
			//��  ��   ��ǰ�������ֵ  �������� 
int action(int x,int y,int valueMax,int cnt){
	
	if(x>n||y>m||cnt>k) return 0;//�жϱ߽�
	
	
	if(x==n&&y==m){//�����յ�
		if(cnt==k||(value[n][m]>valueMax&&cnt+1==k)){//���㷽�� 
			return 1;//��1���ظ���һ��action�е�res�� 
		}
	}
	long long res=0;
	if(value[x][y]>valueMax){
		res+=action(x+1,y,value[x][y],cnt+1);//�ñ���������
		res+=action(x,y+1,value[x][y],cnt+1);//�ñ���������
		res+=action(x+1,y,valueMax,cnt);//���ñ��������� 
		res+=action(x,y+1,valueMax,cnt);//���ñ��������� 
	}
	else{
		res+=action(x+1,y,valueMax,cnt);//���ñ��������� 
		res+=action(x,y+1,valueMax,cnt);//���ñ��������� 		
	}
	return res;
}

int main(){
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>value[i][j];
		}
	}

	cout<<action(1,1,-1,0)%MOD;
	
	return 0;
}
