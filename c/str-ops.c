#include<stdio.h>

void main()
{
    int op,i,j,n,m,flag;
    char arr[50],arr2[50],c;
    do
    {
        system("cls");
        printf("Enter string\n");
        fflush(stdin);
        gets(arr);
        printf("Select an option\n");
        printf("1. Length of string\n");
        printf("2. Copy a string to another\n");
        printf("3. Concatenate two strings\n");
        printf("4. Compare two strings\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
               for(i=0;arr[i]!='\0';i++);
               printf("The length of string is %d",i);
               break;
        case 2:
               for(i=0;arr[i]!='\0';i++)
                    arr2[i]=arr[i];
                    arr2[i]='\0';
               printf("The main string is\n");
               puts(arr);
               printf("The copy of string is\n");
               puts(arr2);
               break;
        case 3:
               printf("Enter new string\n");
               fflush(stdin);
               gets(arr2);
               for(i=0;arr[i]!='\0';i++);
               for(j=0;arr2[j]!='\0';j++);
               if(j>(49-i))
                    printf("New string is too large to concatenate\n");
               else
               {
                   n=i;
                   printf("The first string is\n");
                   puts(arr);
                   printf("The second string is\n");
                   puts(arr2);
                   for(j=n,i=0;arr2[i]!='\0';j++,i++)
                       arr[j]=arr2[i];
                   arr[j]='\0';
                   printf("The main string is\n");
                   puts(arr);
               }
            break;
        case 4:
               printf("Enter new string\n");
               fflush(stdin);
               gets(arr2);
               for(n=0;arr[n]!='\0';n++);
               for(j=0;arr2[j]!='\0';j++);
               flag=0;
               for(i=0;arr[i]!='\0';i++)
               {
                   if(arr[i]!=arr2[i]||n!=j)
                   {
                       flag=1;
                       printf("The two strings are not the same\n");
                       break;
                   }
               }
               if(flag==0)
                    printf("The two strings are the same\n");
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
