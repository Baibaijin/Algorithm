# include <iostream>
# include <algorithm>
using namespace std;

const int N=1e4+10;
int a[N][N];
int w,m,n;
int x1,x2,y1,y2;
int main(){

	cin>>w>>m>>n;
	
	int cnt=1;
	int maxn=max(m,n);
	for(int i=0;;i++){
		if(!(i&1)){//Å¼ÊıĞĞ´Ó×óÍùÓÒ 
			for(int j=0;j<w;j++){
				a[i][j]=cnt++;
				if(cnt==m+1){
					x1=i;
					y1=j;
				}
				else if(cnt==n+1){
					x2=i;
					y2=j;
				}
				if(cnt>maxn) break;
			}
		}
		else{
			for(int j=w-1;j>=0;j--){
				a[i][j]=cnt++;
				if(cnt==m+1){
					x1=i;
					y1=j;
				}
				else if(cnt==n+1){
					x2=i;
					y2=j;
				}
				if(cnt>maxn) break;
			}
		}
		if(cnt>maxn) break;
	}	
	cout<<abs(x1-x2)+abs(y1-y2);
	return 0;
}
