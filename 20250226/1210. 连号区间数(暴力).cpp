# include <iostream>
# include <algorithm>
# include <cstring>
using namespace std;

const int N=1e4+10;
int n;
int a[N],backup[N]; 
int cnt=0;
bool flag;

int main(){
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	memcpy(backup,a,sizeof a);//备份,防止排序完数组有变化 
	for(int i=0;i<n;i++){
		memcpy(a,backup,sizeof a);	
		for(int j=i;j<n;j++){
			sort(a+i,a+j+1);	
			flag=true;
			for(int k=i;k<j;k++){
				//cout<<a[k]<<" ";
				if(a[k]+1!=a[k+1]){//后一个数是否等于前一个数+1 
					flag=false;
					break;
				}
			}
			if(flag) cnt++;
		}		
	}
	
	cout<<cnt<<'\n';
	
	return 0;
}
