#include <stdio.h>
int main(void)
{
    int num, n, i, j;
    char word[20]={0};
    
	scanf("%d", &num);

	for(int k=0; k<num; k++){
	    scanf("%d %s", &n, word);
		getchar();
	
		i=0;
	    while(word[i]!='\0')
	    {
 	       j=0;
  	      while(j<n)
  	      {
 	           printf("%c", word[i]);
  	          j++;
	        }
			i++;
	   	 }
		printf("\n");
	}
    return 0;
}