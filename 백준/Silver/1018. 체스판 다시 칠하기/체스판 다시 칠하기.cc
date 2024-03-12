#include <iostream>
#include <algorithm>
using namespace std;
int counting(int x, int y);
char a[50][50];
int main(void)
{
	int n, m,c=0;
	cin>>n>>m;
	char a[n][m];
	int count[2500]={0};
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int x=0;x<=m-8;x++){
		for(int y=0;y<=n-8;y++){
			

	for(int j=y;j<y+8;j++){
		for(int i=x;i<x+8;i++){
			if(j%2==0 and i%2==0){
				if (a[j][i]=='W') count[c]++;
			}
			else if(j%2==0 and i%2==1){
				if (a[j][i]=='B') count[c]++;
			}
			else if(j%2==1 and i%2==0){
				if (a[j][i]=='B') count[c]++;
			}
			else {
				if (a[j][i]=='W') count[c]++;
			}
		}
	}
	if (count[c]>32) count[c]=64-count[c];
	c++;
		}
	}
	sort(count, count+c);
	cout<<count[0];
}