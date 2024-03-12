#include <iostream>
using namespace std;
int MAX=0, bord[504][504];;
void SwapMax(int t){
    if (t>MAX) MAX=t;
}
void Type_l(int i, int j){
    SwapMax(bord[i][j]+bord[i][j+1]+bord[i][j+2]+bord[i][j+3]);
    SwapMax(bord[i][j]+bord[i+1][j]+bord[i+2][j]+bord[i+3][j]);
}
void Type_L(int i, int j){
    SwapMax(bord[i][j]+bord[i+1][j]+bord[i+2][j]+bord[i+2][j+1]);
    SwapMax(bord[i][j+1]+bord[i+1][j+1]+bord[i+2][j+1]+bord[i+2][j]);

    SwapMax(bord[i][j]+bord[i][j+1]+bord[i][j+2]+bord[i+1][j+2]);
    SwapMax(bord[i+1][j]+bord[i+1][j+1]+bord[i+1][j+2]+bord[i][j+2]);

    SwapMax(bord[i][j]+bord[i][j+1]+bord[i+1][j+1]+bord[i+2][j+1]);
    SwapMax(bord[i][j]+bord[i+1][j]+bord[i+2][j]+bord[i][j+1]);

    SwapMax(bord[i][j]+bord[i][j+1]+bord[i][j+2]+bord[i+1][j]);
    SwapMax(bord[i][j]+bord[i+1][j]+bord[i+1][j+1]+bord[i+1][j+2]);
}
void Type_T(int i, int j){
    SwapMax(bord[i][j]+bord[i][j+1]+bord[i][j+2]+bord[i+1][j+1]);
    SwapMax(bord[i][j]+bord[i+1][j]+bord[i+2][j]+bord[i+1][j+1]);
    SwapMax(bord[i+1][j]+bord[i][j+1]+bord[i+2][j+1]+bord[i+1][j+1]);
    SwapMax(bord[i+1][j]+bord[i][j+1]+bord[i+1][j+2]+bord[i+1][j+1]);
}
void Type_O(int i, int j){
    SwapMax(bord[i][j]+bord[i][j+1]+bord[i+1][j]+bord[i+1][j+1]);
}
void Type_N(int i, int j){
    SwapMax(bord[i][j]+bord[i+1][j]+bord[i+1][j+1]+bord[i+2][j+1]);
    SwapMax(bord[i][j+1]+bord[i+1][j+1]+bord[i+1][j]+bord[i+2][j]);

    SwapMax(bord[i][j]+bord[i][j+1]+bord[i+1][j+1]+bord[i+1][j+2]);
    SwapMax(bord[i+1][j]+bord[i+1][j+1]+bord[i][j+1]+bord[i][j+2]);
}
int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>bord[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Type_l(i,j);
            Type_L(i,j);
            Type_T(i,j);
            Type_O(i,j);
            Type_N(i,j);
        }
    }
    cout<<MAX<<"\n";
}