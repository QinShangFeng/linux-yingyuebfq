#ifndef __LINKLIST_H
#define __LINKLIST_H


/*************************双向循环链表********************************/
typedef struct node//定义节点类型
{
	char data[128];
	struct node *prev;
	struct node *next;

}listnode, *linklist;


// 创建一个带头结点的空链表
linklist init_list(void);


// 创建一个新结点
linklist new_node(char* data);



// 将节点new插入到以head为首的链表的末尾
void list_add_tail(linklist new, linklist head);

 
 
void show(linklist head);//遍历链表


/************************双向循环链表end************************************/	
#endif