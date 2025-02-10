# include <iostream>
# include <algorithm>
using namespace std;

const int N=1e5+10;
int n,q,k;
int a[N];

int  main(){

	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	while(q--){
		cin>>k;
		//binary_search����ĳ��Ԫ���Ƿ����
		if(binary_search(a,a+n,k)){
			
			//lower_bound(),���ص�һ�γ���k��λ��
			//upper_bound(),���ص�һ�γ��ִ���k�����ֵ�λ��
			//upper_bound��lower_bound���Ƿ���ָ�룬Ҫ��ȥ�����ָ�� 
			cout<<lower_bound(a,a+n,k)-a<<" "<<upper_bound(a,a+n,k)-a-1<<endl;
		}
		else cout<<"-1 -1"<<endl;
		
	}
	

	return 0;
}
