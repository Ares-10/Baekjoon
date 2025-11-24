#include <stdio.h>
int main(void)
{
    char a[10001];
    scanf("%s", a);
    int n;
    scanf("%d", &n);
    printf("%c", a[n-1]);
}