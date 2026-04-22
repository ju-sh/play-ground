#include<stdio.h>
#include<string.h>
void main()
{
    int i,j,len,flag;
    char arr[50],c,temp;
    do
    {
        flag=0;
        system("cls");
        printf("Enter string\n");
        fflush(stdin);
        gets(arr);
        len=strlen(arr);
        for(i=0;arr[i]!='\0';i++)
        {
            if(ispunct(arr[i])!=0||isalnum(arr[i])==0)
            {
                for(j=i;j<len;j++)
                    arr[j]=arr[j+1];
                len--;
                i--;
            }
        }
        for(i=0,j=len-1;i<len/2;i++,j--)
        {
            if(arr[i]!=arr[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("The string is a palindrome\n");
        else
            printf("The string is not a palindrome\n");
        printf("\nDo you wish to enter again ? (Y/N)\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='Y'||c=='y');
}


