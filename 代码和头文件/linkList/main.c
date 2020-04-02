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
    LNode *L = NULL;	 //���������� 
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
				}
				else if(judge == ERROR)
				{
					printf("\n��ʼ��ʧ�ܣ�\n");
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
					printf("\n����ɹ���\n");
				}
				else if(judge == ERROR) 
				{
					printf("\n����ʧ�ܣ�\n");
				}
				else if(judge == 3)
				{
					printf("���ʼ������\n");
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
					printf("\nɾ��ʧ�ܣ�\nԭ��:����δ��ʼ������ͷ����û�н��\n");
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
					printf("\n�ҵ��ˣ�\n");
				}
				else if(judge == ERROR) 
				{
					printf("\n��Ǹ��û���ҵ���ֵ��\n");
				}
				else if(judge == 3)
				{
					printf("���ʼ������!"); 
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
					printf("���ʼ������\n");
				}
				Sleep(2000);
				menu();
				break;
			case 'h':
				judge = IsLoopList(L);
				if(judge == SUCCESS)
				{
					printf("\n�ñ���ѭ������\n");
				}else if(judge == ERROR)
				{
					printf("\n�ñ���ѭ������\n");
				}else if(judge == 3){
					printf("���ʼ������");
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
				printf("����������������������!");
				Sleep(1000); 
				menu();
				fflush(stdin);
				goto restart;	
		}		
	}
	
		
	return 0;
}
