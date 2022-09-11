#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    int i, max, index=0;
    int num[26]={0};
    char a;
    char alp[1000000];
    
    scanf("%s", alp);
    
    //소문자를 대문자로 변환
    for(i=0; alp[i]!='\0'; i++)
    {
        alp[i] = (char)toupper(alp[i]);
        num[alp[i]-'A']++;
    }

    max = num[0];
    a='X';
    //가장 많이 사용된 알파벳 탐색
    for(i=1; i<26; i++)
    {
        if(max<=num[i])
        {
            if(max==num[i])
                a='O';
            else
            {
                a='X';
                index=i;
                max=num[i];
            }
        }
    }

    if (a=='O')
        printf("?\n");
    else
        printf("%c\n", index+65);
    return 0;
}