#include<stdio.h>
int main(){
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    a==b && a==c && printf("zuv gurvaljin"); 
    a==b && a!=c && a+b>c && a+c>b && b+c>a && printf("adil hajuut");  
    a==c && a!=b && a+b>c && a+c>b && b+c>a && printf("adil hajuut");  
    b==c && b!=a && a+b>c && a+c>b && b+c>a && printf("adil hajuut");  
    a!=b && a!=c && b!= c && a+b>c && a+c>b && b+c>a && printf("eldev talt");  
    (a+b<=c || a+b<=c || b+c<=a) && printf("gurvaljin bish baina ");  
    return 0;
}