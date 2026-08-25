#include<stdio.h>
void main()
{
    int arr[20][20],i,j,r,c,rsum[20],csum[20];
    char ch;
    do
    {
        system("cls");
        printf("Enter the number of rows\n");
        scanf("%d",&r);
        printf("Enter the number of columns\n");
        scanf("%d",&c);
        printf("Enter the elements of matrix\n");
        for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                    scanf("%d",&arr[i][j]);
            }
        printf("The matrix is\n");
        for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                    printf("%d\t",arr[i][j]);
                printf("\n");
            }
        for(i=0;i<r;i++)
        {
            rsum[i]=0;
            for(j=0;j<c;j++)
                rsum[i]=rsum[i]+arr[i][j];
        }
        for(i=0;i<c;i++)
        {
            csum[i]=0;
            for(j=0;j<r;j++)
                csum[i]=csum[i]+arr[j][i];
        }
        printf("The row sum is \n");
        for(i=0;i<r;i++)
            printf("%d\t",rsum[i]);
        printf("\nThe column sum is \n");
        for(i=0;i<c;i++)
            printf("%d\t",csum[i]);
        printf("\nDo you wish to enter again ? (Y/N)\n");
        fflush(stdin);
        scanf("%c",&ch);
    }
    while(ch=='Y'||ch=='y');
}
