# include <iostream>
# include <algorithm>
using namespace std;

const int N=1e5+10;
int a[N],b[N],c[N];
int n;

// ������ arr �в��ҵ�һ�����ڻ���� target ���±�
int find_l(int arr[],int n,int target) {
    int l=0,r=n;
    while(l<r) {
        int mid=l+r>>1;
        if (arr[mid]>=target) {
            r=mid;
        } else {
            l=mid+1;
        }
    }
    return l;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    cin>>n;
    
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) cin>>b[i];
    for (int i=0;i<n;i++) cin>>c[i];
	
	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	
	long long res=0;


    for (int j=0;j<n;j++) {
        int cnt1=find_l(a,n,b[j]);//��a�����ҵ�һ��<b[j]��Ԫ�ص�λ�� 
        int cnt2=n-find_l(c,n,b[j]+1);//��a�����ҵ�һ��>b[j],Ҳ���ǵ�һ��>=b[j]+1��Ԫ�ص�λ�� 
		res+=(long long)cnt1*cnt2;
		}
        
    cout<<res<<'\n';
    return 0;
}
