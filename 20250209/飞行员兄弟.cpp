# include <iostream>
# include <cstring>
# include <vector>
# define x first   //��typedef���ƣ���x����first 
# define y second
using namespace std;

typedef pair<int,int> PII;

const int N=5;
char g[N][N],backup[N][N];

int get(int x,int y){//����ӳ�䣬��ά���һά 
	return x*4+y;	
}

void turn_one(int x,int y){//���ڵ������ؽ��в��� 
	if(g[x][y]=='+') g[x][y]='-';
	else g[x][y]='+';
}

void turn_all(int x,int y){//һ�����ػ�ǣ����һ�к�һ�� 
	for(int i=0;i<4;i++){
		turn_one(x,i);
		turn_one(i,y);
	}
	turn_one(x,y);
}

int main(){
	
	//��ȡ����
	for(int i=0;i<4;i++){ 
		for(int j=0;j<4;j++){
			cin>>g[i][j];
		}
	}

	vector<PII> res;	
	
	for(int op=0;op<1<<16;op++){
		memcpy(backup,g,sizeof g);//����gͼ,��Ϊ��Ҫ��һ��ͼ�϶�γ��ԡ� 
		 
		vector<PII> temp;
		
		for(int i=0;i<4;i++){//ȫ���������Ƿ���Ҫ���� 
			for(int j=0;j<4;j++){
				if(op>>get(i,j)&1){//�����1��Ҳ������Ҫ���� 
					temp.push_back({i,j});
					turn_all(i,j);
				}
			}
		}
		
		bool has_closed=false;
		
		for(int i=0;i<4;i++){//�ж���������Ƿ���� 
			for(int j=0;j<4;j++){
				if(g[i][j]=='+'){
					has_closed=true;
					continue;
				}
			}
		}
		
		if(!has_closed){//����������� 
			if(res.empty()||res.size()>temp.size()) res=temp;//�ж��Ƿ�Ϊ��С����������ǣ������� 
		}
		memcpy(g,backup,sizeof backup);//��ԭ 
	}
	
	cout<<res.size()<<endl;
	for(auto op:res){//ѭ������res 
		cout<<op.x+1<<" "<<op.y+1<<endl;
	}
	
	return 0;
}
