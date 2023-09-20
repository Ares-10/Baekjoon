#include <iostream>
#include <cstring>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        int a=0,b=1,k;
        for (int i=0;i<m-1;i++)
        {
            k=b;
            b=b+a;
            a=k;
        }
        if (m==0) {a=1;b=0;}
        cout<<a<<" "<<b<<"\n";
    }
}