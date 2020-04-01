#include <stdio.h> 
#include <stdlib.h>
#include "../head/duLinkedList.h"

void print(ElemType e)
{	
	printf("%d  ",e); 
}
int main(int argc, char *argv[]) {
	restart:;
	
	menu();
    int choice,judge;
    DuLinkedList L;	 //创建的链表 
    ElemType e;
    DuLinkedList r = (DuLinkedList)malloc(sizeof(DuLNode));
	while(scanf("%d",&choice) != EOF) //在后面转成char，脸滚键盘也不怕 
	{
		fflush(stdin);
		DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
		choice = (char)(choice + 96);   //强制转成char 
		switch(choice)
		{
			case 'a':	
				judge = InitList_DuL(&L);
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
				DestroyList_DuL(&L);
				printf("\n已销毁！\n");
				Sleep(2000);
				menu();
				break;
			case 'c':
				printf("\n请输入你要插入的值：");
				scanf("%d",&(q->data));
				fflush(stdin);
				judge = InsertBeforeList_DuL(L, q);
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
				printf("\n请输入你要插入的值：");
				scanf("%d",&(q->data));
				fflush(stdin);
				judge = InsertAfterList_DuL(L, q);
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
			case 'e':
				judge = DeleteList_DuL(L, &e);
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
			case 'f':
				printf("\n各结点的值为:\n"); 
				TraverseList_DuL(L, print);
				Sleep(2000);
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
