#include"common.h"//通用头文件
#include"linklist.h"

/************************目录******************************************/
void directory(linklist head, linklist head2,char *dir_name)//打开目录
{
	
	printf("进入目录:%s\n",dir_name);
	DIR *dp = opendir(dir_name); //dir_name
	struct dirent *ep;// ep是一个指向目录项的指针
   
	char buf[128];
	
	while(1)
	{
		bzero(buf,sizeof(buf));
		// ep是一个指向目录项的指针
		ep = readdir(dp); 
		
		// 读完收工
		if(ep == NULL)
			break;
		
      
			   
		// 跳过所有隐藏文件
		if(ep->d_name[0] == '.')
			continue;
		
		
		if(strstr(ep->d_name,".bmp")==0&&    //只存取.mp3 .bmp扩展名的文件名 
		strstr(ep->d_name,".mp3")==0 )
		{
			
			continue;
		} 
	
		if(strcmp(dir_name +strlen(dir_name) -1, "/") == 0)
		{
			printf(buf, "%s%s",dir_name ,ep->d_name);
		}else
		{
			sprintf(buf, "%s/%s", dir_name,ep->d_name);
		}
		
        
		
		
		
		if(strstr(ep->d_name,".bmp")!=0)
		{
			printf("head:%s\n",buf);
			linklist new = new_node(buf);// 创建一个新结点
			list_add_tail(new, head);// 将节点new插入到以head为首的链表的末尾 
		}	
        if(strstr(ep->d_name,".mp3")!=0)
		{
			printf("head2:%s\n",buf);
			linklist new = new_node(buf);// 创建一个新结点
			list_add_tail(new, head2);// 将节点new插入到以head1为首的链表的末尾 
		}				
	}
	
	

	 
 closedir(dp);	 
}
/************************目录end******************************************/