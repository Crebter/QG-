#include <stdio.h>
#include <stdlib.h>
#include "../head/linkedList.h" 
void print(ElemType e)
{
	printf("%d  ",e);
}

int main(int argc, char *argv[]) {
	restart:;
	
	menu();
   	int choice;
	int judge;
    LNode *L = NULL;	 //创建的链表 
    ElemType e;
    LinkedList r = (LinkedList)malloc(sizeof(LNode));
	while(scanf("%d",&choice) != EOF )
	{
		fflush(stdin);
		LinkedList q = (LinkedList)malloc(sizeof(LNode));
		choice = (char)(choice + 96) ;
		switch(choice)
		{
			case 'a':	
				judge = InitList(&L);
				if(judge == SUCCESS)
				{
					printf("\n初始化成功！\n");
				}
				else if(judge == ERROR)
				{
					printf("\n初始化失败！\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'b':	
				DestroyList(&L);
				Sleep(2000);
				menu();
				break;
			case 'c':
				judge = InsertList(L, q);
				if(judge == SUCCESS)
				{
					printf("\n插入成功！\n");
				}
				else if(judge == ERROR) 
				{
					printf("\n插入失败！\n");
				}
				else if(judge == 3)
				{
					printf("请初始化链表！\n");
				}
				Sleep(2000);
				menu();
				break;		
			case 'd':
				judge = DeleteList(L, &e);
				if(judge == SUCCESS)
				{
					printf("\n删除成功，该结点的值为%d\n",e);
				}else
				{
					printf("\n删除失败！\n原因:链表未初始化或者头结点后没有结点\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'e':
				TraverseList(L, print);
				Sleep(3000);
				menu();
				break;
			case 'f':
				judge = SearchList(L,e);
				if(judge == SUCCESS)
				{
					printf("\n找到了！\n");
				}
				else if(judge == ERROR) 
				{
					printf("\n抱歉，没有找到该值！\n");
				}
				else if(judge == 3)
				{
					printf("请初始化链表!"); 
				}
				Sleep(2000);
				menu();
				break;
			case 'g':
				judge = ReverseList(&L);
				if(judge == SUCCESS)
				{
					printf("\n反转成功！\n");
				}else
				{
					printf("请初始化链表！\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'h':
				judge = IsLoopList(L);
				if(judge == SUCCESS)
				{
					printf("\n该表是循环链表\n");
				}else if(judge == ERROR)
				{
					printf("\n该表不是循环链表\n");
				}else if(judge == 3){
					printf("请初始化链表！");
				}
				Sleep(2000);
				menu();
				break;
			case 'i':
				r = FindMidNode(&L);
				Sleep(3000);
				menu();
				break;
			case 'j':
				L = ReverseEvenList(&L);
				Sleep(3000);
				menu();
				break;	
			case '_':
				exit(0);
				break;					
			default :
				printf("您的输入有误，请重新输入!");
				Sleep(1000); 
				menu();
				fflush(stdin);
				goto restart;	
		}		
	}
	
		
	return 0;
}
