#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define  group_max 10000
#define  n_group_elem_max 1000 
#define  n_elem_rect_max  10000
#define  n_elem_rect_item_max  10000

#define  Error_Large_Print(cmd_string)  do(printf("cmd_string\n"))while(0); 

typedef struct str_rect{
	int item_num
	int l;
	int w;
}*p_str_rect_type,str_rect_type;

int num_HowManyGroup;/*多少组测试数据*/
/*******************************************************************/
int input_HowManyGroup(void)
{
	int temp_input;
	  
	do
	{
		scanf("%d",&temp_input);
		if(temp_input>=group_max)) Error_Large_Print(group  too many);
		
	}while(temp_input>=group_max);
		
	return temp_input;
		
 } 
 
 int* InitMem_HowManyGroup(int NumOfGroup );
 {
	int size;
	int *p;
	
	size = sizeof(int)*(NumOfGroup); /*每一组的长方形个数不超过10 000*/
	p = malloc(size);
	memset(p,0,size);
	return p;
 } 
 
  int input_EachGroup_NumOfElem( int num_of_group,int* p_elem_num) 
{  
	int test_elem_num;
	
	 do
	 {
	 scanf("%d",&test_elem_num);
	 if(test_elem_num>n_group_elem_max) Error_Large_Print( group is too numerous);
	 
	 } while(test_elem_num>n_group_elem_max);
	 
	 p_elem_num[num_of_group] = test_elem_num;
	 			
	
	return 0;
 }
 
  p_str_rect_type p_Mem_P2GroupBlockAddr = InitMem_P2GroupBlockAddr(void)//初始化 指向block 
 {
 
 	int size;
	p_str_rect_type *p;
	
	size = sizeof(int*)*(num_HowManyGroup); 
	p = (p_str_rect_type)malloc(size);
	memset(p,0,size);
	return p;
		
 }
 
/**************************************************************************************************/
int main(void)
{
	
	int i;
	int* p_MemEachGroup_ElemNum;/*动态内存申请,是一个数组,每一组有多少个长方形*/
	p_str_rect_type  p_Mem_P2GroupBlockAddr;/*动态内存申请,是一个数组,存放每一个组块的开始地址*/
	p_str_rect_type  p_Mem_AllGroupElemBlock;/*动态内存申请*/
	
	/******ONE*********/
	num_HowManyGroup = 	input_HowManyGroup();	//检查输入，返回多少组测试数据	
	p_MemEachGroup_ElemNum = InitMem_HowManyGroup(num_HowManyGroup); //返回一个int数组 ,存放有每一组的长方形个数

	/******ONE*********/
	
	/**********input***********************/ 
	for(i=0;i<num_HowManyGroup;i++)//输入元素组数和每一组的元素 ，是循环 
	{
			
		input_ElemNumAndElem(i,p_MemEachGroup_ElemNum);
			
	}
	/******************************************************************/ 
	/**********print_all***********************/ 
	for(i=0;i<num_HowManyGroup;i++)//输出元每一组的元素 ，是循环 
	{
					
	}
	/**********print_all***************************************************/ 	
	
	
	
	
	
	
	
	
	
	
	
		
	input_EachGroup_NumOfElem(num_HowManyGroup,p_MemEachGroup_ElemNum);//Para:多少组测试数据 ；存放数据的指针(要访问故要取地址)
	/******ONE*********/ 
	 
	/******TWO*********/                 
	
	                               	 
	p_Mem_AllGroupElemBlock = InitMem_AllGroupElemBlock(num_HowManyGroup,p_MemEachGroup_ElemNum); 
	 							//Para1:多少组；Para2: 每一组的元素，是个数组
								                                              

}/*MAIN*/

void input_ElemNumAndElem(int num_of_group,int* p_elem_num)
{
	input_EachGroup_NumOfElem( num_of_group, p_elem_num) ;//每次，输入一个数 
	InitMem_P2GroupBlockAddr(num_of_group,p_elem_num );/*动态内存申请,是一个数组,将要存放每一个组块的开始地址*/
	
}
	



 

 
 /**************************************/

 
p_str_rect_type  InitMem_AllGroupElemBlock(int num_group,int* EachGroupNum_Arry); 
{
	int i,sum=0;
	int size;
	p_str_rect_type  p;
	
	for(i=0;i<num_group;i++)
	{
		sum=sum + EachGroupNum_Arry[i];		
	}

	size = sizeof(str_rect_type)*(sum); 
	p = (p_str_rect_type)malloc(size);
	memset(p,0,size);
	return p;

} 
 
  /*********up_ok********************/
  
  
  
  //(第几组;组的数组；元素block地址)
 input_OneOfElem_rectangle(p_str_rect_type  p_rect)//参数指向rect结构体的指针，以给它输入参数 
 {
 	int test_rectangle_val,test_rectangle_val1,test_rectangle_val2,test_rectangle_val_cp;
 	bool test_item_num_ok;
 	int item_num;
 	
 	do
	{
 		scanf("%d",&item_num);//输入长方形编号 
 		test_item_num_ok = ((0<item_num)&&(item_num<n_elem_rect_item_max));
 		if(false == test_item_num_ok) Error_Large_Print(item_num to lager);
	}while(  false == test_item_num_ok );
	
 	for(i=0;i<2;i++) /*一个长方形元素输入wide与high*/
	{
		do
		 {
		 	scanf("%d",&test_rectangle_val);
		 	if(test_rectangle_val>n_elem_rect_max)
			{
				Error_Large_Print(rectangle value L_or_W to longger);
			} 
		 } while(test_rectangle_val>n_elem_rect_max);
		 
		 if(0==i) test_rectangle_val1 = test_rectangle_val;
		 else test_rectangle_val2 = test_rectangle_val;
		
	}
	
	if(test_rectangle_val1<test_rectangle_val2) 
	{
		test_rectangle_val_cp = test_rectangle_val1;
		test_rectangle_val1 = test_rectangle_val2;
		test_rectangle_val2 = test_rectangle_val_cp;
	}
	p_rect->item_num = item_num;
	p_rect->l = test_rectangle_val1;
	p_rect->w = test_rectangle_val2;
 	
 	
 }//////
 
 seek_ElemAdrrOfBlock(whichgroup,base)

 input_OneOfGroupElem(int whichgroup,p_str_rect_type  p_rect)
 {
 	
 	
 }
 
 void input_AllOfGroupElem(int num_group,int* p_EachGroupNum,p_str_rect_type  p_AllElemBase)
  {
  		
  	
  }
 

