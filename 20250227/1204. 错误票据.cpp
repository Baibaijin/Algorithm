# include <iostream>
# include <sstream>
# include <algorithm>
using namespace std;

const int N=1e5+10;
int cnt[N];
int maxn=0,minn=0x3f3f3f3f;
int n,num;
string line;
int main(){
	
	cin>>n;
	
	getline(cin,line);//忽略第一行的空格 
	while(n--){
		getline(cin,line);
		stringstream ssin(line);
		while(ssin>>num){
			maxn=max(maxn,num);
			minn=min(minn,num);
			cnt[num]++;//计数，当前num有几个	
		}
	}
	
	int res1=0,res2=0;
	for(int i=minn;i<=maxn;i++){
		if(cnt[i]==0) res1=i;
		if(cnt[i]==2) res2=i;//因为保证只有一个断号和重号 
	}
	
	cout<<res1<<" "<<res2;
	
		
	return 0;
}
