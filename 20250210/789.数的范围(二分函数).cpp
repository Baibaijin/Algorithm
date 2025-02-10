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
		//binary_search查找某个元素是否出现
		if(binary_search(a,a+n,k)){
			
			//lower_bound(),返回第一次出现k的位置
			//upper_bound(),返回第一次出现大于k的数字的位置
			//upper_bound和lower_bound都是返回指针，要减去数组的指针 
			cout<<lower_bound(a,a+n,k)-a<<" "<<upper_bound(a,a+n,k)-a-1<<endl;
		}
		else cout<<"-1 -1"<<endl;
		
	}
	

	return 0;
}
