#include<stdio.h>
int main(){
    int num;
    char ch;
    float fnum;
    double dnum;
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("Enter a character: ");
    scanf(" %c", &ch);
    printf("Enter a float: ");
    scanf("%f", &fnum);
    printf("Enter a double: ");
    scanf("%lf", &dnum);
    printf("Integer: %d\n", num);
    printf("Character: %c\n", ch);
    printf("Float: %.2f\n", fnum);
    printf("Double: %.2lf\n", dnum);
    return 0;
}