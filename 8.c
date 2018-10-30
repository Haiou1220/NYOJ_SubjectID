
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define  group_max 10000
#define  n_group_elem_max 1000 
#define  n_elem_rect_max  10000
#define  n_elem_rect_item_max  10000

#define  Error_Large_Print(cmd_string)  do{printf(#cmd_string"\n");} while(0); 

typedef struct str_rect{
	int item_num;
	int l;
	int w;
}**pp_str_rect_type,*p_str_rect_type,str_rect_type;

int num_HowManyGroup;/*多少组测试数据*/

/********函数***********************************************************/
int input_HowManyGroup(void)
{
	int temp_input;
	  
	do
	{
		printf("How Many Group To Input\n");
		scanf("%d",&temp_input);
		if(temp_input>=group_max) Error_Large_Print(group  too many);
		
	}while(temp_input>=group_max);
		
	return temp_input;
		
 } 
 
 int* InitMem_HowManyGroup(void )
 {
	int size;
	int *p;
	/*全局num_HowManyGroup*/
	size = sizeof(int)*(num_HowManyGroup); /*每一组的长方形个数不超过10 000*/
	p = malloc(size);
	memset(p,0,size);
	return p;
 } 
 
  int input_EachGroup_NumOfElem( int num_of_group,int* p_elem_num) 
{  
	int test_elem_num;
	
	 do
	 {
	 printf("%dth Group Num Of Elem\n",num_of_group+1);
	 scanf("%d",&test_elem_num);
	 if(test_elem_num>n_group_elem_max) Error_Large_Print( group is too numerous);
	 
	 } while(test_elem_num>n_group_elem_max);
	 
	 p_elem_num[num_of_group] = test_elem_num;
	 			
	
	return 0;
 }
 
 void  StoreMem_P2GroupBlockAddr(int i,int* p_elem_num, pp_str_rect_type Store_P2GroupBlockAddr)//初始化 指向block 
 {//_P2GroupBlockAddr
 	/*存放每一个组块的开始地址 p_Mem_P2GroupBlockAddr*/
 
 	int size;
	p_str_rect_type *p;
	
	size = sizeof(str_rect_type)*(p_elem_num[i]); //申请一个block
	p = (p_str_rect_type)malloc(size);
	memset(p,0,size);
	Store_P2GroupBlockAddr[i] = p;
		
 }
 
  pp_str_rect_type  InitMem_P2GroupBlockAddr(void )
 {
	int size;
	pp_str_rect_type p;
	/*全局num_HowManyGroup*/
	size = sizeof(int*)*(num_HowManyGroup); /*每一组的长方形个数不超过10 000*/
	p = (pp_str_rect_type)malloc(size);
	memset(p,0,size);
	return p;
 } 
 
 str_rect_type input_OneRectangle(void)
 {
 	
 	int i,test_rectangle_val,test_rectangle_val1,test_rectangle_val2,test_rectangle_val_cp;
 	bool test_fault;        /****val1为l,********* val2为w********/
 	int item_num;
 	str_rect_type rect;
 	
 	do
	{                  /* 编号 长 宽**/
 		scanf("%d %d %d",&item_num,&test_rectangle_val1,&test_rectangle_val2);//输入长方形编号 
 		
 		if( (test_rectangle_val1>n_elem_rect_max)||(test_rectangle_val2>n_elem_rect_max))
			{
				Error_Large_Print(rectangle value L_or_W to longger);
			} 
		if(item_num>n_elem_rect_item_max) Error_Large_Print(item_num to lager);	
			
 		test_fault = ((item_num>n_elem_rect_item_max)||(test_rectangle_val1>n_elem_rect_max)||(test_rectangle_val2>n_elem_rect_max));
 		
	}while(  test_fault );
	
	
	if(test_rectangle_val1<test_rectangle_val2) 
	{
		test_rectangle_val_cp = test_rectangle_val1;
		test_rectangle_val1 = test_rectangle_val2;
		test_rectangle_val2 = test_rectangle_val_cp;
	}
	
	rect.item_num = item_num;
	rect.l = test_rectangle_val1;
	rect.w = test_rectangle_val2;
 	
 	return rect;
 	
 }/*input_OneRectangle*/
 
 
void input_ElemNumAndElem(int i_num_of_group,int* p_elem_num,pp_str_rect_type Store_P2GroupBlockAddr)
{
	input_EachGroup_NumOfElem( i_num_of_group, p_elem_num) ;//每次，输入一个数 
	StoreMem_P2GroupBlockAddr(i_num_of_group,p_elem_num ,Store_P2GroupBlockAddr);/*要存放了每一个组块的开始地址*/
	input_OneOfGroupElem(i_num_of_group,p_elem_num,Store_P2GroupBlockAddr);
}
	
/************************************/
 input_OneOfGroupElem(int i_group,int* p_elem_num,  pp_str_rect_type  Store_P2GroupBlockAddr)
 {									/**i_num_of_group,p_elem_num,Store_P2GroupBlockAddr*/
 	
 	int i,OneOfBlockSize = p_elem_num[i_group];
 	
 	p_str_rect_type OneOfBlockLocation = Store_P2GroupBlockAddr[i_group];//取出一个组block
 	 
 	printf("Please Input %d Rectangle Object\n",OneOfBlockSize) ;
 	for(i=0;i<OneOfBlockSize;i++)//一组元素输入个数
 	{
 		OneOfBlockLocation[i] =input_OneRectangle();
 		
 	}
 	
 }

 
/**************************************************************************************************/
int main(void)
{
	
	int i;
	int* p_MemEachGroup_ElemNum;/*动态内存申请,是一个数组,每一组有多少个长方形*/
	pp_str_rect_type  pp_Mem_P2GroupBlockAddr;/*动态内存申请,是一个数组,存放(point)每一个组块的开始地址*/
	
	/******初始化动态内存，存放**********************************************/
	num_HowManyGroup = 	input_HowManyGroup();	//检查输入，返回多少组测试数据	
	p_MemEachGroup_ElemNum = InitMem_HowManyGroup(); //返回一个int数组 ,存放有每一组的长方形个数

  pp_Mem_P2GroupBlockAddr = InitMem_P2GroupBlockAddr();//返回数组 ,将存放指向block的指针
      
	/******初始化动态内存，存放每一组的elem数量，将存放block的地址*********/
	
	/**********input***********************/ 
	for(i=0;i<num_HowManyGroup;i++)//输入元素组数和每一组的元素 ，是循环 
	{
		input_ElemNumAndElem(i,p_MemEachGroup_ElemNum,pp_Mem_P2GroupBlockAddr);	
		/*(int i_num_of_group,int* p_elem_num,pp_str_rect_type Store_P2GroupBlockAddr)*/	
	}
	/**********input*****************************************************/ 
	/**********print_all***********************/ 
	for(i=0;i<num_HowManyGroup;i++)//输出元每一组的元素 ，是循环 
	{	
	}
	/**********print_all***************************************************/ 	
	
 

								                                              

}/*MAIN*/
