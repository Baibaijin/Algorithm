# include <iostream>
# include <algorithm>
using namespace std;

const int N=110;
int value[N][N];
int f[N][N];//��ʾ��[1,1]��[i,j]��������� 

int main(){
	
	int R,C,T;
	cin>>T;
	while(T--){
		cin>>R>>C;
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++){
				cin>>value[i][j];
				//f[i][j]=0; 
			}
		}
		//f[i][j]��ֵֻ������f[i-1][j]�� f[i][j-1]������ֻҪ��ʼ����һ����Ϳ����ˣ��������������ʼ�� 
		f[1][1]=value[1][1];//��ʼ����һ���� 
		
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++){
				if(i==1&&j==1) continue;
				f[i][j]=max(f[i-1][j]+value[i][j],f[i][j-1]+value[i][j]);
			}
		}
		cout<<f[R][C]<<endl;
	}
	
	return 0;
}
