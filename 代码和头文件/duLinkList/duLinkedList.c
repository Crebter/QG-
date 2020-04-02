#include "../head/duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>


void menu(){
 	system("CLS");
 	printf("****************˫���������ʾ**************\n");
    printf("*   1.��ʼ������        4.����������     *\n");
    printf("    2.��������          5.ɾ������ 	     	\n");
    printf("*   3.��ǰ��������      6.��������         *\n");
    printf("********************************************\n");
    printf("��ѡ�����Ĳ�����"); 
 }

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	if(*L)
		return ERROR;			
	else{
		*L = (DuLinkedList)malloc(sizeof(DuLNode));	
		(*L)->next = NULL;
		(*L)->prior = NULL;
	}
	return SUCCESS;	
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	if(!(*L))
	{
		printf("�Բ�����������");
		return;
	} 
	else
	{	
		DuLinkedList p = NULL;
		while(*L)
		{
			p = (*L)->next;
			free(*L);
			*L = p;
		}
		printf("���ٳɹ���"); 
	}	
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(!p)
		return ERROR;
	else
	{	
		printf("\n��������Ҫ�����ֵ��");
		//again:;
		while(1)
		{
			if(0 == scanf("%d",&(q->data)))
			{
				fflush(stdin);
				printf("������Ч,���ٴ�����: ");
				//goto again;
			}
			else
			{
				DuLNode *L = p;
				if(L->next)
				{
					L->next->prior = q;
				}
				q->prior = L;
				q->next = L->next;
				L->next = q;
				return SUCCESS;
			}
		}
	}		
	
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(!p)
		return ERROR;
	else
	{	
		printf("\n��������Ҫ�����ֵ��");
		//again:;
		while(1)
		{
			if(0 == scanf("%d",&(q->data)))
			{
				fflush(stdin);
				printf("������Ч,���ٴ�����: ");
				//goto again;
			}
			else
			{
				DuLNode *L = p;
				while(L->next)
				{
					L = L->next;
				}
				q->prior = L;
				q->next = L->next;
				L->next = q;
				return SUCCESS;
			}
		}
	}			
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if(!p || !p->next)
		return ERROR;
	else
	{
		DuLNode *q = NULL;
		q = p->next;
		if(q->next)
			q->next->prior = p;
		*e = q->data;
		p->next = q->next;
		free(q);
		return SUCCESS;	
	}	
	
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {//������ 
	if(!L)
	{
		printf("��Ǹ������������!");
		return;	
	}	
	else
	{
		printf("\n������ֵΪ:\n"); 
		DuLNode *p = L->next;
		while(p)
		{
			visit(p->data);
			p = p->next;
		}
	}	
	
}
