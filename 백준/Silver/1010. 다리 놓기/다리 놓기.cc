#include <iostream>
using std::cin;
using std::cout;
int main(void) {
    int n;
    cin>>n;
    int count[n];
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
		int T=1;
		for(int j=1;j<=a;j++){
			T=T*(b+1-j)/j;
		}
		count[i]=T;
    }
    for(int i=0;i<n;i++){
        cout<<count[i]<<"\n";
    }
}