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
    LinkedList L;	 //���������� 
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
					printf("\n��ʼ���ɹ���\n");
				}else
				{
					printf("\n��ʼ��ʧ�ܣ�\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'b':	
				DestroyList(&L);
				printf("\n�����٣�\n");
				Sleep(2000);
				menu();
				break;
			case 'c':
				printf("\n��������Ҫ�����ֵ��");
				scanf("%d",&(q->data));
				fflush(stdin);
				judge = InsertList(L, q);
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
				judge = DeleteList(L, &e);
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
			case 'e':
				printf("\n������ֵΪ:\n"); 
				TraverseList(L, print);
				Sleep(3000);
				menu();
				break;
			case 'f':
				printf("\n����������Ҫ���ҵ�ֵ:"); 
				scanf("%d",&e);
				judge = SearchList(L,e);
				if(judge == SUCCESS)
				{
					printf("\n�ҵ��ˣ�\n");
				}else
				{
					printf("\n��Ǹ��û���ҵ���ֵ��\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'g':
				judge = ReverseList(&L);
				if(judge == SUCCESS)
				{
					printf("\n��ת�ɹ���\n");
				}else
				{
					printf("\n��תʧ�ܣ�\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'h':
				judge = IsLoopList(L);
				if(judge == SUCCESS)
				{
					printf("\n�ñ���ѭ������\n");
				}else
				{
					printf("\n�ñ���ѭ������\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'i':
				r = FindMidNode(&L);
				e = r->data;
				printf("�������м�Ľ��ֵ��%d",e);
				Sleep(3000);
				menu();
				break;
			case 'j':
				L = ReverseEvenList(&L);
				printf("\n�ɹ�,���������鿴��\n");
				Sleep(3000);
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
