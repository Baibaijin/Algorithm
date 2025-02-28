# include <iostream>
#include<cstdio>
using namespace std;

int a[500010],tmp[500010];
int n;
long long res;

void merge_sort(int l,int r){
	if(l>=r) return ;
	
	int mid=l+r>>1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	
	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]) tmp[k++]=a[i++];
		else tmp[k++]=a[j++],res+=mid-i+1;
	}
	while(i<=mid) tmp[k++]=a[i++];
	while(j<=r) tmp[k++]=a[j++];
	
	for(int i=l,j=0;i<=r;i++,j++) a[i]=tmp[j];
}

int main(){

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	merge_sort(0,n-1);
	cout<<res;
	/*for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}*/
	return 0;
}
