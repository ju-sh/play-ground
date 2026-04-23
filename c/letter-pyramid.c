#include<stdio.h>
int main()
{
	char seed='T';
	scanf(" %c", &seed);
	int i, j, m;
	for(i=0; i<'Z'-seed+2; ++i)
	{
		printf("\n%*s", 'Z'-seed-i+1, "");
		for(m=1, j=seed ; m==1?j<seed+i:j>=seed; j+=m)
		{
			putchar(j);
			if(j+1==seed+i)
			{
				m=-1;
			}
		}

		/*
		for(j=seed; j<seed+i; ++j)
		{
			putchar(j);	
		}
		for(; j>=seed; --j)
		{
			putchar(j);
		}
		*/
	}
	return 0;
}


/*
8

                                   
                                  8
                                 898
                                89:98
                               89:;:98
                              89:;<;:98
                             89:;<=<;:98
                            89:;<=>=<;:98
                           89:;<=>?>=<;:98
                          89:;<=>?@?>=<;:98
                         89:;<=>?@A@?>=<;:98
                        89:;<=>?@ABA@?>=<;:98
                       89:;<=>?@ABCBA@?>=<;:98
                      89:;<=>?@ABCDCBA@?>=<;:98
                     89:;<=>?@ABCDEDCBA@?>=<;:98
                    89:;<=>?@ABCDEFEDCBA@?>=<;:98
                   89:;<=>?@ABCDEFGFEDCBA@?>=<;:98
                  89:;<=>?@ABCDEFGHGFEDCBA@?>=<;:98
                 89:;<=>?@ABCDEFGHIHGFEDCBA@?>=<;:98
                89:;<=>?@ABCDEFGHIJIHGFEDCBA@?>=<;:98
               89:;<=>?@ABCDEFGHIJKJIHGFEDCBA@?>=<;:98
              89:;<=>?@ABCDEFGHIJKLKJIHGFEDCBA@?>=<;:98
             89:;<=>?@ABCDEFGHIJKLMLKJIHGFEDCBA@?>=<;:98
            89:;<=>?@ABCDEFGHIJKLMNMLKJIHGFEDCBA@?>=<;:98
           89:;<=>?@ABCDEFGHIJKLMNONMLKJIHGFEDCBA@?>=<;:98
          89:;<=>?@ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA@?>=<;:98
         89:;<=>?@ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA@?>=<;:98
        89:;<=>?@ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA@?>=<;:98
       89:;<=>?@ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA@?>=<;:98
      89:;<=>?@ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA@?>=<;:98
     89:;<=>?@ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA@?>=<;:98
    89:;<=>?@ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA@?>=<;:98
   89:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA@?>=<;:98
  89:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:98
 89:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:98
89:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA@?>=<;:98
*/
