#include "../head/duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>


void menu(){
 	system("CLS");
 	printf("****************双向链表的演示**************\n");
    printf("*   1.初始化链表        4.向后插入数据     *\n");
    printf("    2.销毁链表          5.删除数据 	     	\n");
    printf("*   3.向前插入数据      6.遍历链表         *\n");
    printf("********************************************\n");
    printf("请选择您的操作："); 
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
		printf("对不起，链表不存在");
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
		printf("销毁成功！"); 
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
		printf("\n请输入你要插入的值：");
		//again:;
		while(1)
		{
			if(0 == scanf("%d",&(q->data)))
			{
				fflush(stdin);
				printf("输入无效,请再次输入: ");
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
		printf("\n请输入你要插入的值：");
		//again:;
		while(1)
		{
			if(0 == scanf("%d",&(q->data)))
			{
				fflush(stdin);
				printf("输入无效,请再次输入: ");
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
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {//向后遍历 
	if(!L)
	{
		printf("抱歉，该链表不存在!");
		return;	
	}	
	else
	{
		printf("\n各结点的值为:\n"); 
		DuLNode *p = L->next;
		while(p)
		{
			visit(p->data);
			p = p->next;
		}
	}	
	
}
