# include <iostream>
# include <algorithm>
using namespace std;

const int N=110;
int value[N][N];
int f[N][N];//表示从[1,1]到[i,j]的最大花生数 

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
		//f[i][j]的值只依赖于f[i-1][j]和 f[i][j-1]，所以只要初始化第一个点就可以了，不用整个数组初始化 
		f[1][1]=value[1][1];//初始化第一个点 
		
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
