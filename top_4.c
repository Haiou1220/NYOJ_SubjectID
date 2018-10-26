#include<stdio.h>
#include<stdlib.h>
#define N_row_max 10 /*最多有N_max组测试数据*/
#define N_char 4 /*每一组有N_char=4 字符 */

void mem_arr_ending(char a[][4]);/*二维数组，里面元素的数组结尾赋值为0 */
int qsort_comp(const void *a,const void *b);

int main(void)
{
	/*printf("%d",sizeof(char));*/
	char a[N_row_max][N_char]={0};/*有N_max组，每一组只能存三个字符，最后一个'\0' */

	unsigned char i , N;
	scanf("%d ",&N);/*有N组测试数据*/
	

	for(i=0;i<N;i++)
	{ 
		scanf("%s",(&a[0])+i);
	}
	
	mem_arr_ending(a);
	
	for(i=0;i<N;i++)
	{	
		qsort(((&a[0])+i),N_char-1,sizeof(char) ,qsort_comp);
		printf("%0.1s %0.1s %0.1s\n",((char*)((&a[0])+i)+0),\
							((char*)((&a[0])+i)+1),\
							((char*)((&a[0])+i)+2)	);
	}

	return 0;
}

void mem_arr_ending(char a[][4])/*二维数组，里面元素的数组结尾赋值为0*/ 
{ 
	unsigned char i;
	for(i=0;i<N_row_max;i++)
	{
		a[i][3] = '\0';
	}

}

int qsort_comp(const void *a,const void *b)
{
	return (*(char*)a - *(char*)b);
}