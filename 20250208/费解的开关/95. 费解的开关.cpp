# include <iostream>
# include <cstring>
using namespace std;

const int N=6,INF=2e9;
int n;
char g[N][N],backup[N][N];//因为 ^=是基于字符的 ASCII 值进行计算,所以要用char来存储 
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};//用来存储自己和上下左右四个灯。 
void turn(int x,int y){//控制开关 
	
	for(int i=0;i<5;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a<0||a>4||b<0||b>4) continue;//判断边界情况 
		g[a][b]^=1;//^=1  就是让1变成0,让0变成1 
	}
	
}

int main(){
	
	cin>>n;
	while(n--){
		for(int i=0;i<5;i++){
			cin>>g[i];//读取数字 
		}
		int res=INF;//结果先取无限大，后面再比较 
		for(int op=0;op<1<<5;op++){//遍历第一行的所有情况
			memcpy(backup,g,sizeof g);//备份一下g数组，下一次循环还要重新使用 
			int step=0;//记录步数 
			for(int i=0;i<5;i++){ 
				if(op>>i&1){//第一行的五个开关也是可以按动的，不同的按动会有不同的结果共有2的5次方种结果
					step++;
					turn(0,4-i);
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
			memcpy(g,backup,sizeof backup);//恢复数组 
		}
		if(res>6) res=-1;
		cout<<res<<endl;
		
	}
	
	return 0;
} 
