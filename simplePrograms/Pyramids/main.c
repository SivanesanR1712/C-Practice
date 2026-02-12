#include <stdio.h>
#include <stdlib.h>

void pyramid2(int n){
printf("\nYour entered no.of rows is : %d\nYour enterd pyramid is 'Inverted Half Pyramid' \n\n",n);
        for(int i=n;i>0;i--){
            for(int j=i;j>0;j--){
              printf("* ");
            }
        printf("\n");

        }
}

void pyramid1(int n){
printf("\nYour entered no.of rows is : %d\nYour enterd pyramid is 'Half Pyramid' \n\n",n);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
              printf("* ");
            }
        printf("\n");

        }
}


int main()
{
    int n,count=0,type=0;
    printf("Enter the number of rows for the pyramid: ");
    scanf("%d",&n);
    while(n<=0 && count<5){
        printf("Enter Valid number of rows for the pyramis (Not <= 0) : ");
        scanf("%d",&n);
        count++;
    }
    if(n>0){
        printf("Which type of pyramid you want :\n1. Half Pyramid\n2. Inverted Half Pyramid\n\nEnter 1 or 2\nEnter here: ");
        scanf("%d",&type);
        switch(type){
    case 1:
        pyramid1(n);
        break;

    case 2:
        pyramid2(n);
        break;

    default :
        printf("Enter valid numbers only 1 or 2");
        break;
    }

    }
    else printf("Limits Reached... try gaian later...\n");
        return 0;
}

