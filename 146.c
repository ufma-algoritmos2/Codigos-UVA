#include<stdio.h>
#include<string.h>

/* 146 - ID Codes ACC*/

int ordena(char str[], int pos, int len)
{
	int i, j, k;
	for (i=pos; i<len; i++)
		for(j=i; j<len; j++)
			if(str[i]>str[j]) k=str[i], str[i]=str[j], str[j]=k;
	return 0;
}


int main()
{
	int i, j, len, pos_x, pos_y;
	char str[100];
	
	while(1)
	{
		scanf("%s", &str); if(!strcmp(str, "#")) break;
		len=strlen(str);
		pos_x = -1;
		for(i=len-2; i>=0 && pos_x == -1; i--)
			if(str[i]<str[i+1]) pos_x = i;
		if(pos_x == -1) printf("No Successor\n");
		else
		{
			pos_y = pos_x + 1;
			for(i=pos_x+1; i<len && pos_x != -1; i++)
				if(str[i] > str[pos_x] && str[i]<str[pos_y]) pos_y = i;
			/* troca */
			j = str[pos_x], str[pos_x] = str[pos_y], str[pos_y] = j;
			/* ordena apos pos_x */
			ordena(str, pos_x + 1, len);
			printf("%s\n", str);
		}
	}
	return 0;
}
