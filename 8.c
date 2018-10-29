#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define  n_group_max 10000
#define  n_group_elem_max 1000 
#define  n_elem_rect_max  10000

#define  Error_Large_Print(cmd_string)  do(printf("cmd_string\n"))while(0); 

typedef struct str_rect{
	int l;
	int w;
}*p_str_rect_type,str_rect_type;

int input_n_group(unsigned int *p_n_group);
int input_n_group_elem_num( int n_group_site, int *p_elem_num);

 input_elem_rectangle(p_str_rect_type  rect);

int main(void)
{
	unsigned int n_group;/*多少组测试数据*/
	int* p_elem_num;/*每一组有多少个长方形*/
	
    p_elem_num =  input_n_group(&n_group);
    input_n_group_elem_num( n_group , &p_elem_num);
     input_elem_rectangle(p_str_rect_type  rect);
    
	//scanf("%d",n_group_elem);
//	scanf("%d",elem_rect);
 //	printf("ok");
	return 0;
}

int* input_n_group(unsigned int *p_n_group)
{
	int n_size;
	int *p;
	  
	do
	{
		scanf("%d",p_n_group);
		if(*p_n_group>=n_group_max)) Error_Large_Print(group  too many);
	}
	while(*p_n_group>=n_group_max);
		
		n_size = sizeof(int)*(*p_n_group); /*每一组的长方形个数不超过10 000*/
		p = malloc( n_size);
		memset(p,0,n_size);
		return p;
		
	
 } 
 
 int input_n_group_elem_num( int n_group_site, int *p_elem_num)
{
	int test_elem_num;
	for(i=0;i<n_group_site;i++) 
	{	
	 do
	 {
	 scanf("%d",&test_elem_num);
	 if(test_elem_num>n_group_elem_max) Error_Large_Print(Each group is too numerous);
	 } while(test_elem_num>n_group_elem_max);
	 
	 p_elem_num[i] = test_elem_num;
		
	}
	return 0;
 }
 
 input_elem_rectangle(p_str_rect_type  rect)//now now
 {
 	int test_rectangle_val;
 	
 	
 	for(i=0;i<2;i++) /*一个长方形元素输入wide与high*/
	{
		do
		 {
		 	scanf("%d",&test_rectangle_val);
		 	if(test_rectangle_val>n_elem_rect_max)  Error_Print(rectangle value to longger);
		 } while(test_rectangle_val>n_elem_rect_max);
		 
		 if(0==i) rect->l = test_rectangle_val;
		 else rect->w = test_rectangle_val;
		
	}
 	
 	
 }//////
