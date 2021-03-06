#include "../head/linkedList.h"
#include<stdio.h>
#include<stdlib.h>

void menu(){
 	system("CLS");
 	printf("****************单链表的演示****************\n");
    printf("*   1.初始化链表         6.查询链表        *\n");
    printf("*   2.销毁链表           7.反转链表 	   *\n");
    printf("*   3.插入数据           8.判断是否有环    *\n");
    printf("*   4.删除数据           9.找到中间结点    *\n");
    printf("*   5.遍历链表           10.偶结点反转     *\n"); 
    printf("********************************************\n");
    printf("请选择您的操作："); 
 }
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	if(*L)
		return ERROR;
	else
	{
		*L = (LinkedList)malloc(sizeof(LNode));	
		(*L)->data = 0;
		(*L)->next = NULL;
	}	
	return SUCCESS;
}	

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	if(!(*L))
	{
		printf("请初始化链表！\n");
	}
	else
	{
		LinkedList p = NULL;
		while(*L)
		{
			p = (*L)->next;
			free(*L);
			*L = p;	
		}
		printf("销毁成功!\n");	
	}
	
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if(!p)
		return ERROR;
	else
	{
		printf("\n请输入你要插入的值：");
		while(1)
		{
			if(0 == scanf("%d",&(q->data)))
			{
				fflush(stdin);
				printf("输入无效,请再次输入: ");
			}
			else
			{
				LNode *L = p;	
				while(L->next != NULL)
				{
					L = L->next;
				}
				q->next = L->next;
				L->next = q;
				return SUCCESS;
			}
		}				
	}	
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if(!p || !p->next)
		return ERROR;
	else
	{
		LNode *q = NULL;
		q = p->next;
		*e = q->data;
		p->next = q->next;
		free(q);
		return SUCCESS;
	}	
}



/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
 
// void Traverse(LinkedList L)
// {	
// 	LNode *p = L->next;
// 	while(p!=NULL)
// 	{
// 		printf("%d ",p->data);
//		p = p->next; 	
//	}
// }
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	if(!L)
	{
		printf("请初始化链表！\n");
		return;	
	}
	else
	{
		printf("各结点的值为:\n");
		LNode *p;
		p = L->next;
		while(p)
		{
			visit(p->data);
			p = p->next;
		}
	}
		 

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	if(!L)
		return 3;
	else
	{	
		printf("\n请输入你想要查找的值:"); 
		scanf("%d",&e);
		LNode *p = NULL;
		p = L->next;
		while(p)
		{
			if(e == p->data)
				return  SUCCESS;
			else
				p = p->next;	
		}	
	}
	return ERROR;	
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if(!(*L) || !(*L)->next )
		return ERROR;
	else
	{
		LNode *pre,*cur,*next;  
		pre = (*L)->next;   	//指向原来的第一个结点 
		cur = (*L)->next->next;	//指向原来的第二个结点
		pre->next = NULL;
		while(cur)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;	
		}
		LNode *q = (LinkedList)malloc(sizeof(LNode));
		q->next = pre;
		*L = q;
		return SUCCESS;	
	}	
	
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	if(!L)
	{
		return 3; 
	}
		
	else
	{
		LNode *fast,*slow;//用快慢指针法 
		fast = slow = L;
		while(fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast)
				return SUCCESS;
		}
		return ERROR;	
	}	
	
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	if(!(*L))
	{
		printf("请初始化链表！\n"); 
		return;
	}	
	else if(!(*L)->next)
	{
		printf("请插入结点!");
		return; 
	}
	{
		LNode *pre, *cur;		//定义前中后指针，用途和反转相似
		pre = *L;
		cur= (*L)->next;
		while(cur && cur->next){
			pre->next = cur->next;
			cur->next = pre->next->next;
			pre->next->next = cur;
			pre = cur;
			cur = cur->next;
		}
		printf("\n成功,请遍历链表查看！\n");
		return (*L);
	}	
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	if(!(*L))
	{
		printf("\n请初始化链表！\n");
		return;
	}
	else if(!(*L)->next)
	{
		printf("\n请插入结点！\n"); 
		return;
	}
	else
	{
		LinkedList fast,slow;
		fast = slow = (*L)->next;
		while(fast->next && fast->next->next)
		{
				fast = fast->next->next;
				slow = slow->next;
		}
		printf("该链表中间的结点值是%d",slow->data);
		return slow;
	}
	
}

