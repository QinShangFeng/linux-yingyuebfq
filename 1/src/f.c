#include"common.h"//通用头文件
#include"chumo.h"
#include"linklist.h"
/****************************播放音乐线程响应函数************************************/


void *f(void *arg)
{
	//tmp初始
	
	linklist tmp;
	linklist head =(linklist)arg;
	tmp=head->next;
	int vv=-40;//初始音量
	int nxn=0;//标志，重新播放；nxn=0 不需要重新播放
	int nxn1=0;//标志，播放状态；nxn=0 歌曲未播放
	
	while(1)
	{
		//对system(buf1)里buf1，字符串整合实现切换歌曲，音量控制
		//如buf1="madplay 切换歌曲 -a 音量控制"
		char buf1[128]="madplay ";
		char buf2[64];
		bzero(buf2,sizeof(buf2));
		sprintf(buf2,"%s",tmp->data);
		char buf3[]=" -a ";
		char buf4[64];
		bzero(buf4,sizeof(buf4));
		sprintf(buf4,"%d",vv);
		char buf5[]=" &";
		strcat(buf1,buf2);
		strcat(buf1,buf3);
		strcat(buf1,buf4);
		strcat(buf1,buf5);
		
		printf("buf1:%s\n",buf1);//显示选中歌曲	
		if(nxn==1||(nxn==2&&nxn1==1))//nxn=1 切换歌曲；重新播放。
		{							//nxn=2 音量调整；nxn1=1,歌曲在播放；重新播放。
			system("killall -9 madplay");
			system(buf1);
			nxn1=1;//nxn1=1,歌曲在播放；
			nxn=0;//已重新播放，初始化标志
		}
		int c=chumo();//触摸
		switch(c)
		 {
			 
			 case 1://播放
				
				system("killall -CONT madplay &");	
				system(buf1);	
				nxn1=1;				
				 
			 break;
			 
			 case 2: //暂停
				system("killall -STOP madplay &");
				nxn1=0;
			 break;
			 
			 
			 case 3: //停止
				system("killall -9 madplay");
				nxn1=0;
			 break;
			 
			 
			 case 4: //上一首
				tmp=tmp->next; 
				if(tmp==head)
				tmp=tmp->next;
				
				nxn=1; 
			 break; 
			 
			 
			 case 5: //下一首	 
				tmp=tmp->prev;
				if(tmp==head)
				tmp=tmp->prev;
			
				nxn=1;
			 break;
			 
			 
			  
			 case 6: //音量+		 
				vv=vv+1;
				if(vv>10)
				{
					vv=10;
				}
				nxn=2;
			 break;
			 
			  case 7: //音量-	 
				vv=vv-1;
				if(vv<(-45))
				{
					vv=-45;
				}
				nxn=2;
			 break;
			 
			 
		 }
	}



}
/**********************************播放音乐线程响应函数END************************************/