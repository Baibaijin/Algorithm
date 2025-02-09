# include <iostream>
# include <cstring>
# include <vector>
# define x first   //和typedef类似，用x代替first 
# define y second
using namespace std;

typedef pair<int,int> PII;

const int N=5;
char g[N][N],backup[N][N];

int get(int x,int y){//建立映射，二维变成一维 
	return x*4+y;	
}

void turn_one(int x,int y){//对于单个开关进行操作 
	if(g[x][y]=='+') g[x][y]='-';
	else g[x][y]='+';
}

void turn_all(int x,int y){//一个开关会牵扯到一行和一列 
	for(int i=0;i<4;i++){
		turn_one(x,i);
		turn_one(i,y);
	}
	turn_one(x,y);
}

int main(){
	
	//读取数据
	for(int i=0;i<4;i++){ 
		for(int j=0;j<4;j++){
			cin>>g[i][j];
		}
	}

	vector<PII> res;	
	
	for(int op=0;op<1<<16;op++){
		memcpy(backup,g,sizeof g);//备份g图,因为需要在一个图上多次尝试。 
		 
		vector<PII> temp;
		
		for(int i=0;i<4;i++){//全部遍历看是否需要操作 
			for(int j=0;j<4;j++){
				if(op>>get(i,j)&1){//如果是1，也就是需要操作 
					temp.push_back({i,j});
					turn_all(i,j);
				}
			}
		}
		
		bool has_closed=false;
		
		for(int i=0;i<4;i++){//判断这个方案是否可行 
			for(int j=0;j<4;j++){
				if(g[i][j]=='+'){
					has_closed=true;
					continue;
				}
			}
		}
		
		if(!has_closed){//如果方案可行 
			if(res.empty()||res.size()>temp.size()) res=temp;//判断是否为最小次数，如果是，存下来 
		}
		memcpy(g,backup,sizeof backup);//还原 
	}
	
	cout<<res.size()<<endl;
	for(auto op:res){//循环遍历res 
		cout<<op.x+1<<" "<<op.y+1<<endl;
	}
	
	return 0;
}
