#include<stdio.h>
void main()
{
    int a[20][20],b[20][20],result[20][20],i,j,k,r1,r2,c1,c2,op;
    char c;
    do
    {
        system("cls");
        printf("Enter the number of rows of matrix 1\n");
        scanf("%d",&r1);
        printf("Enter the number of columns of matrix 1\n");
        scanf("%d",&c1);
        printf("Enter the elements of matrix 1\n");
        for(i=0;i<r1;i++)
            {
                for(j=0;j<c1;j++)
                    scanf("%d",&a[i][j]);
            }
        printf("Enter the number of rows of matrix 2\n");
        scanf("%d",&r2);
        printf("Enter the number of columns of matrix 2\n");
        scanf("%d",&c2);
        printf("Enter the elements of matrix 2\n");
        for(i=0;i<r2;i++)
            {
                for(j=0;j<c2;j++)
                    scanf("%d",&b[i][j]);
            }
        printf("Select option\n");
        printf("1. Sum of matrices\n");
        printf("2. Product of matrices\n");
        scanf("%d",&op);
        printf("Matrix 1\n");
        for(i=0;i<r1;i++)
            {
                for(j=0;j<c1;j++)
                    printf("%d\t",a[i][j]);
                    printf("\n");
            }
        printf("Matrix 2\n");
        for(i=0;i<r2;i++)
            {
                for(j=0;j<c2;j++)
                   printf("%d\t",b[i][j]);
                    printf("\n");
            }
        switch(op)
        {
        case 1:
            if(r1!=r2||c1!=c2)
                  printf("The matices are of different dimensions and cannot be added\n");

               else
               {
                   printf("\nthe sum matrix is \n");
                   for(i=0;i<r1;i++)
                    {
                        for(j=0;j<c1;j++)
                        {
                            result[i][j]=a[i][j]+b[i][j];
                            printf("%d\t",result[i][j]);
                        }
                        printf("\n");
                    }
               }
               break;
        case 2:
               if(c1!=r2)
                  printf("\nThe row of martix 1 and column of matrix 2 are different and hence cannot be multiplied\n");
               else
               {
                   printf("The product matrix is\n");
                   for(i=0;i<r1;i++)
                    {
                        for(j=0;j<c2;j++)
                        {
                            result[i][j]=0;
                            for(k=0;k<c1;k++)
                                result[i][j]=result[i][j]+(a[i][k]*b[k][j]);
                                printf("%d\t",result[i][j]);

                        }
                        printf("\n");
                    }
               }
               break;
        default:
               printf("Invalid option\n");
               break;
        }
        printf("\nDo you wish to enter again ? (Y/N)\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}

