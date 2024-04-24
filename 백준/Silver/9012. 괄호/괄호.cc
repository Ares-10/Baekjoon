#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
	int n;
	cin>>n;
	char a[51];
	int count[n];
	for(int i=0;i<n;i++){
		count[i]=0;
		cin>>a;
		int N=strlen(a);
		for(int j=0;j<N;j++){
			if(a[j]=='(') count[i]++;
			else count[i]--;
			if(count[i]<0) break;
		}
	}
	for(int i=0;i<n;i++){
		if(count[i]) cout<<"NO\n";
		else cout<<"YES\n";
	}
}