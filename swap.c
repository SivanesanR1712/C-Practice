#include<stdio.h>
int main(){
    int num1, num2;
    printf("Enter the number: \n");
    scanf("%d%d",&num1,&num2);
    printf("The numbers before swapping are: %d %d\n",num1, num2);
    int temp=0;
    temp=num1;
    num1=num2;
    num2=temp;
    printf("The numbers after swapping are: %d %d\n", num1,num2);
    return 0;
    }