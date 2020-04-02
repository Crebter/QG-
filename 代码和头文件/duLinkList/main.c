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
   	DuLNode *L = NULL;	 //���������� 
    ElemType e;
    DuLinkedList r = (DuLinkedList)malloc(sizeof(DuLNode));
	while(scanf("%d",&choice) != EOF) //�ں���ת��char����������Ҳ���� 
	{
		fflush(stdin);
		DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
		choice = (char)(choice + 96);   //ǿ��ת��char 
		switch(choice)
		{
			case 'a':	
				judge = InitList_DuL(&L);
				if(judge == ERROR)
				{
					printf("\n��ʼ��ʧ�ܣ�\n");
				}else if(judge == SUCCESS) 
				{
					printf("\n��ʼ���ɹ���\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'b':	
				DestroyList_DuL(&L);
				Sleep(2000);
				menu();
				break;
			case 'c':
				judge = InsertBeforeList_DuL(L, q);
				if(judge == SUCCESS)
				{
					printf("\n����ɹ���\n");
				}else
				{
					printf("\n����ʧ�ܣ�\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'd':
				judge = InsertAfterList_DuL(L, q);
				if(judge == SUCCESS)
				{
					printf("\n����ɹ���\n");
				}else
				{
					printf("\n����ʧ�ܣ�\n");
				}
				Sleep(2000);
				menu();
				break;					
			case 'e':
				judge = DeleteList_DuL(L, &e);
				if(judge == SUCCESS)
				{
					printf("\nɾ���ɹ����ý���ֵΪ%d\n",e);
				}else
				{
					printf("\nɾ��ʧ�ܣ�\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'f':
				TraverseList_DuL(L, print);
				Sleep(2000);
				menu();
				break;
			case '_':
				exit(0);
				break;	
			default :
				printf("����������������������!");
				Sleep(1000);
				menu();
				fflush(stdin);
				goto restart;	
		}
	}
	return 0;
}
