#include"common.h"//通用头文件
#include"linklist.h"
#include"directory.h"
#include"xianshi.h"
#include"f.h"
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf(":%s dir_name\n", argv[0]);
		return -1;
	}
	
	
	linklist head = init_list();// 创建一个带头结点的空链表
	linklist head2 = init_list();// 创建一个带头结点的空链表

		//初始准备，获取显示图标以及音乐
	directory(head, head2,argv[1]);//将目录下,.bmp放链表head,.MP3放链表head2.
	 
	
	 
	show(head);//链表内容.bmp
	show(head2);//链表内容.mp3
	 
	 //一条线程用来播放音乐
	pthread_t tid;
	pthread_create(&tid, // 成功创建线程之后，其ID号将会被存储在tid中
	NULL,// 指定线程的启动属性，NULL代表不设定任何特殊属性
	f,    // 指定线程的执行函数
	head2);
		 
	//界面效果	
	xianshi(head);
	
}























