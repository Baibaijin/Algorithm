# include <iostream>
# include <cstring>
using namespace std;

const int N=510,INF = 1e9; ;
int n;
char g[N][N],backup[N][N];
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
void turn(int x,int y){
	
	for(int i=0;i<5;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a<0||a>4||b<0||b>4) continue;
		g[a][b]^=1;
	}
	
}

int main(){
	
	cin>>n;
	while(n--){
		for(int i=0;i<5;i++){
				cin>>g[i];
		}
		int res=INF;
		for(int op=0;op<1<<5;op++){//遍历第一行的所有情况
			memcpy(backup,g,sizeof g);
			int step=0;
			for(int i=0;i<5;i++){ 
				if(op>>i&1){
					step++;
					turn(0,i);
				}
			}
			for(int i=0;i<4;i++){//遍历0-4行 
				for(int j=0;j<5;j++){
					if(g[i][j]=='0'){
						turn(i+1,j);
						step++;	
					}
				}
			}		
			bool dark=false;
			 
			for(int j=0;j<5;j++){//判断最后一行是否全亮 
				if(g[4][j]=='0'){
					dark=true;
					break;
				}
			}
			
			if(!dark){
				res=min(res,step);
			}				
			memcpy(g,backup,sizeof backup);
		}
		if(res>6) res=-1;
		cout<<res<<endl;
		
	}
	
	return 0;
} 
