# include <iostream>
# include <cstring>
using namespace std;

const int N=6,INF=2e9;
int n;
char g[N][N],backup[N][N];//��Ϊ ^=�ǻ����ַ��� ASCII ֵ���м���,����Ҫ��char���洢 
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};//�����洢�Լ������������ĸ��ơ� 
void turn(int x,int y){//���ƿ��� 
	
	for(int i=0;i<5;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a<0||a>4||b<0||b>4) continue;//�жϱ߽���� 
		g[a][b]^=1;//^=1  ������1���0,��0���1 
	}
	
}

int main(){
	
	cin>>n;
	while(n--){
		for(int i=0;i<5;i++){
			cin>>g[i];//��ȡ���� 
		}
		int res=INF;//�����ȡ���޴󣬺����ٱȽ� 
		for(int op=0;op<1<<5;op++){//������һ�е��������
			memcpy(backup,g,sizeof g);//����һ��g���飬��һ��ѭ����Ҫ����ʹ�� 
			int step=0;//��¼���� 
			for(int i=0;i<5;i++){ 
				if(op>>i&1){//��һ�е��������Ҳ�ǿ��԰����ģ���ͬ�İ������в�ͬ�Ľ������2��5�η��ֽ��
					step++;
					turn(0,4-i);
				}
			}
			for(int i=0;i<4;i++){//����0-4�� 
				for(int j=0;j<5;j++){
					if(g[i][j]=='0'){
						turn(i+1,j);
						step++;	
					}
				}
			}		
			bool dark=false;
			 
			for(int j=0;j<5;j++){//�ж����һ���Ƿ�ȫ�� 
				if(g[4][j]=='0'){
					dark=true;
					break;
				}
			}
			
			if(!dark){
				res=min(res,step);
			}				
			memcpy(g,backup,sizeof backup);//�ָ����� 
		}
		if(res>6) res=-1;
		cout<<res<<endl;
		
	}
	
	return 0;
} 
