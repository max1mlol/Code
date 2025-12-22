#include <stdio.h>
int main(){
    char sn[100], n[100], dob[100], age[100], col[100], ft[100], hob[100];
    scanf("%[^\n]", sn);
    scanf("%[^\n]", n);
    scanf("%[^\n]", dob);
    scanf("%[^\n]", age);
    scanf("%[^\n]", col);
    scanf("%[^\n]", ft);
    scanf("%[^\n]", hob);
    printf("%s ovogtoi %s ni %s udur tursun. Odoo %s nastai. Tuunii durtai ungu bol %s. Ter chuluut tsagaaraa %s hiideg. Tuunii hobby bol %s.", sn, n, dob, age, col, ft, hob);
    return 0;
}