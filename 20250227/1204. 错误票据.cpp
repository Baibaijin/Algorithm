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
	
	getline(cin,line);//���Ե�һ�еĿո� 
	while(n--){
		getline(cin,line);
		stringstream ssin(line);
		while(ssin>>num){
			maxn=max(maxn,num);
			minn=min(minn,num);
			cnt[num]++;//��������ǰnum�м���	
		}
	}
	
	int res1=0,res2=0;
	for(int i=minn;i<=maxn;i++){
		if(cnt[i]==0) res1=i;
		if(cnt[i]==2) res2=i;//��Ϊ��ֻ֤��һ���Ϻź��غ� 
	}
	
	cout<<res1<<" "<<res2;
	
		
	return 0;
}
