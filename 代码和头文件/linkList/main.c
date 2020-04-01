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
    LinkedList L;	 //创建的链表 
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
				}else
				{
					printf("\n初始化失败！\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'b':	
				DestroyList(&L);
				printf("\n已销毁！\n");
				Sleep(2000);
				menu();
				break;
			case 'c':
				printf("\n请输入你要插入的值：");
				scanf("%d",&(q->data));
				fflush(stdin);
				judge = InsertList(L, q);
				if(judge == SUCCESS)
				{
					printf("\n插入成功！\n");
				}else
				{
					printf("\n插入失败！\n");
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
					printf("\n删除失败！\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'e':
				printf("\n各结点的值为:\n"); 
				TraverseList(L, print);
				Sleep(3000);
				menu();
				break;
			case 'f':
				printf("\n请输入你想要查找的值:"); 
				scanf("%d",&e);
				judge = SearchList(L,e);
				if(judge == SUCCESS)
				{
					printf("\n找到了！\n");
				}else
				{
					printf("\n抱歉，没有找到该值！\n");
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
					printf("\n反转失败！\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'h':
				judge = IsLoopList(L);
				if(judge == SUCCESS)
				{
					printf("\n该表是循环链表\n");
				}else
				{
					printf("\n该表不是循环链表\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'i':
				r = FindMidNode(&L);
				e = r->data;
				printf("该链表中间的结点值是%d",e);
				Sleep(3000);
				menu();
				break;
			case 'j':
				L = ReverseEvenList(&L);
				printf("\n成功,请遍历链表查看！\n");
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
