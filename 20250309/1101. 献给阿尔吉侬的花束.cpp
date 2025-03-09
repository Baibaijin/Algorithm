# include <iostream>
# include <queue>
# include <cstring> 
using namespace std;
# define x first
# define y second
typedef pair<int,int> PII;
const int N=210;
char g[N][N];
int dist[N][N];
int n,m;

int bfs(PII start,PII end){
	
	queue<PII> q;
	memset(dist,-1,sizeof dist);
	
	dist[start.x][start.y]=0;
	q.push(start);
	
	int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
	
	while(q.size()){
		
		PII t=q.front();
		q.pop();
		
		for(int i=0;i<4;i++){
			int x=t.x+dx[i],y=t.y+dy[i];
			if(x<0||x>=n||y<0||y>=m) continue;//����
			if(g[x][y]=='#') continue; //�ϰ���
			if(dist[x][y]!=-1) continue;//�Ѿ��߹� 
			
			dist[x][y]=dist[t.x][t.y]+1;
			
			if(end==make_pair(x,y)) return dist[x][y];
			
			q.push({x,y});
		}
	}
	
	return -1;
	
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++) cin>>g[i];
		
		PII start,end;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(g[i][j]=='S') start={i,j};
				else if(g[i][j]=='E')end={i,j};
			}
		}
		
		int distance=bfs(start,end);
		if(distance==-1) cout<<"oop!"<<'\n';
		else cout<<distance<<'\n';
		
	}
	
	
	return 0;
}
