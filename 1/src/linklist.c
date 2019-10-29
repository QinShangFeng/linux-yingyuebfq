#include"common.h"//通用头文件
#include"linklist.h"

/*************************双向循环链表********************************/


// 创建一个带头结点的空链表
linklist init_list(void)
{
	linklist head = calloc(1, sizeof(listnode));//头节点
	if(head != NULL)
	{
		head->prev = head;
		head->next = head;
	}

	return head;
}

// 创建一个新结点
linklist new_node(char* data)
{
	linklist new = calloc(1, sizeof(listnode));
	if(new != NULL)
	{
		//new->data = data;
		strcpy(new->data , data);
		new->prev = new;
		new->next = new;
	}

	return new;
}


// 将节点new插入到以head为首的链表的末尾
void list_add_tail(linklist new, linklist head)
{
	new->prev = head->prev;
	new->next = head;

	head->prev->next = new;
	head->prev = new;
}
 
 
void show(linklist head)//遍历链表
{
	printf("\n");

	for(linklist tmp = head->next; tmp!=head; tmp=tmp->next)
	{
		printf("%s\t", tmp->data);
	}
	printf("\n");
}

/************************双向循环链表end************************************/	