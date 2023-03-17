#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
	int u,v;
	int w;
};
vector<edge> canh;
const int maxn=1001;
int parent[maxn],sz[maxn];
void make_set() {
	for(int i=1;i<=n;i++) {
		parent[i]=i;
		sz[i]=i;
	}
}
int find(int v) {
	if(v==parent[v]) return v;
	return parent[v]=find(parent[v]);
}
bool Union(int a,int b) {
	a=find(a);
	b=find(b);
	if(a==b) return false; // khong the gop a,b vao voi nhau
	if(sz[a]<=sz[b]) swap(a,b);
	parent[b]=a;
	sz[a]+sz[b];
	return true;
}
void inp() {
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int x,y,w;
		cin >> x>> y >> w;
		edge e;
		e.u=x;
		e.v=y;
		e.w=w;
		canh.push_back(e);
	}
}
bool cmp(edge a,edge b) {
	return a.w<b.w;
}
void Kruskal() { // Tao cay khung cuc tieu rong 
	vector<edge> mst;
	int d=0;
	// sort danh sach canh theo chieu dai 
	sort(canh.begin(),canh.end(),cmp);
	for(int i=0;i<m;i++) {
		if(mst.size()==n-1) break;
			edge e= canh[i]; // chon canh e la nho nhat
		if(Union(e.u,e.v)) {
			mst.push_back(e);
			d+=e.w;
		}
	}
	if(mst.size()!=n-1) cout<<"Do thi khong lien thong!\n";
	else {
		cout<<"MST:"<<d<<endl;
		for(auto it:mst) {
			cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
		}
 	}
}
int main() {
	inp();
	make_set();
	Kruskal();
}
//6 9
//1 2 12
//1 3 4
//2 3 1
//2 4 5
//2 5 3
//3 5 2
//4 5 3
//4 6 10
//5 6 8