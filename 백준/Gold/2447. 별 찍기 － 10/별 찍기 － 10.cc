#include<stdio.h>
void hole(int, int, int);
void divide(int, int, int);
int n;
char a[3*3*3*3*3*3*3][3*3*3*3*3*3*3];
int main(void)
{
	scanf("%d", &n);
	
	for (int y=0;y<n;y++){
		for (int x=0;x<n;x++){
			a[y][x]='*';
		}
	}
	
	divide(n, 0, 0);
	for (int y=0;y<n;y++){
		for (int x=0;x<n;x++){
			printf("%c", a[y][x]);
		}
		printf("\n");
	}
	return 0;
}

void hole(int n, int X, int Y)
{
	for (int y=n/3;y<n/3*2;y++){
		for (int x=n/3;x<n/3*2;x++){
			a[Y+y][X+x]=' ';
		}
	}
}

void divide(int n, int x, int y)
{
	if (n==1) return;
	else {
		hole(n,x,y);
		for(int i=0;i<9;i+=3){
			for(int j=0;j<9;j+=3){
				divide(n/3, n/9*i+x, n/9*j+y);
				
			}
		}
	}
}