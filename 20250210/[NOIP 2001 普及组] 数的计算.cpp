# include <iostream>
# include <cstring>
using namespace std;

const int N=1e3+10;
int f[N];
int n;

int main(){
	
	cin>>n;
	
	for(int i=1;i<=n;i++){//����ѭ��1~n 
		for(int j=1;j<=i/2;j++){//����ѭ��1~n/2��ÿһλ 
			f[i]+=f[j];
		}
		f[i]++;
	}
	
	cout<<f[n]<<endl;
	
	return 0;
}
