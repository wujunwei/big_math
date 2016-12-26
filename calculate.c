#include "calculate.h"
#define CHARZERO 48

#ifndef MAX(a, b)
#define MAX(a, b)  (((a)>(b))?(a):(b))
#endif // !MAX

void IntToString(char* intager, int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		intager[i] += CHARZERO;
	}
}

char* ReserveString(char *str, int len, int expen_len)
{

	char* temp = (char*)emalloc(sizeof(char) * (expen_len + 1));
	int i;
	for (i = 0; i < expen_len; i ++)
	{
		if(i < len)
		{

			temp[i] = str[len-i-1];
		}else
		{
			temp[i] = '0';
		}
	}
	temp[expen_len] = '\0';
	return temp;
}
char* Plus(char* a, int a_len, char* b, int b_len)
{
	
	int max_len = MAX(a_len, b_len), i;
	char *sum;
	a = ReserveString(a, a_len, max_len);
	b = ReserveString(b, b_len, max_len);
	sum = (char*)emalloc(sizeof(char)*(max_len + 2));
	memset(sum, 0, max_len + 2);
	for (i = 0; i < max_len;i++)
	{
		sum[i] += a[i] + b[i] - (CHARZERO << 1);
		if (sum[i] / 10 > 0)
		{
			sum[i+1] ++;
			sum[i] = sum[i]%10;
		}
		sum[i] += CHARZERO;
	}
	if(sum[max_len] != 0)
	{
		sum[max_len] += CHARZERO;
		max_len ++;
	}

	return ReserveString(sum, max_len, max_len);
}

char* Multiply(char* a, int a_len, char* b, int b_len)
{
	int i, j, sum_len = a_len + b_len;
	char* sum = (char*)emalloc(sizeof(char)*(a_len + b_len + 1));
	memset(sum, 0, a_len + b_len + 1);
	a = ReserveString(a, a_len, a_len);
	b = ReserveString(b, b_len, b_len);
	for (i = 0; i<a_len;i ++)
	{
		for (j = 0;j<b_len;j ++)
		{
			sum[j+i] += (a[i] - CHARZERO) * (b[j] - CHARZERO);
			if (sum[j+i] / 10 > 0)
			{
				sum[j+i+1] += sum[i+j]/10;
				sum[i+j] = sum[j+i] % 10;
			}
		}
	}
	while(sum[sum_len] == '\0')sum_len--;
	IntToString(sum, ++sum_len);
	if (strlen(sum) == 0)
	{
		sum = "0";
	}
	return ReserveString(sum, sum_len, sum_len);

}

char* Divide(char* a, int a_len, char* b, int b_len)
{


}

char* Minus(char* a, int a_len, char* b, int b_len)
{


}