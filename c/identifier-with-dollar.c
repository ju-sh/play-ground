#include<stdio.h>
void fn$a$()
{
	printf("\nExecuted!");
}
int main()
{
	int $id=3;
	printf("\n%d", $id);	
	fn$a$();
	return 0;
}

/*
3
Executed!
*/
