# include <iostream>
# include <algorithm>
using namespace std;

const int N=5e3+10;
int s[N][N]={0};
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0); 
	
	int n,r,max_length=0;
	cin>>n>>r;
	
	for(int i=0;i<n;i++){
		int x,y,w;
		cin>>x>>y>>w;
		s[x+1][y+1]+=w;
		max_length=max(max_length,max(x,y)+1);//因为不知道数组的具体大小，用一个变量来表示 
	}
	
	//大于5000直接累加就行 
	if(r>=max_length){
		int res=0;
		for(int i=1;i<=max_length;i++){
			for(int j=1;j<=max_length;j++){
				res+=s[i][j];
			}
		}
		cout<<res;
	}
	else{
		int res=0;
		//构造前缀和数组的另一种方法，只需要一个数组，可以避免MLE 
		for(int i=1;i<=max_length;i++){
			for(int j=1;j<=max_length;j++){
				s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
			}
		}
		
		for(int i=r;i<=max_length;i++){
			for(int j=r;j<=max_length;j++){
				int x1=i-r+1,y1=j-r+1;
				res=max(s[i][j]-s[i][y1-1]-s[x1-1][j]+s[x1-1][y1-1],res);
			}
		}
		cout<<res;	
	}

	
	return 0;
}
