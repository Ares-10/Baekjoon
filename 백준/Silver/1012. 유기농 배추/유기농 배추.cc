#include <iostream>
using namespace std;
int a[51][51]={0};
void fill(int x,int y)
{
	if(a[y][x]==0) return;
	a[y][x]=0;
	if((x>0)&&(a[y][x-1]!=0)) fill(x-1,y);
	if((y>0)&&(a[y-1][x]!=0)) fill(x,y-1);
	if(a[y][x+1])fill(x+1,y);
	if(a[y+1][x])fill(x,y+1);
}
int main(void)
{
	int n;
	cin>>n;
	int x,y,m, count;
	for(int k=0;k<n;k++){
		count=0;
		cin>>x>>y>>m;
		for (int i = 0,x,y; i < m; i++)
		{
			cin>>x>>y;
			a[y][x]=1;
		}
		for(int j=0;j<y;j++){
			for(int i=0;i<x;i++){
				if(a[j][i]==1){
					fill(i,j);
					count++;
				}
			}
		}
		cout<<count<<"\n";
	}
}