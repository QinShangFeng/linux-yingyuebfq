
#include"common.h"//通用头文件
#include"chumo.h"
#include"linklist.h"
#include"bmp.h"

/************************************按钮动画效果************************/
void bmpjpg(linklist head)
{
	//tmp初始
	linklist tmp=head->next;
	
		linklist tmp1=tmp;
		linklist tmp2=tmp1->next->next;
		linklist tmp3=tmp2->next;
		linklist tmp4=tmp3->next;
		linklist tmp5=tmp4->next;
		linklist tmp6=tmp5->next;
		linklist tmp7=tmp6->next;
		
	//将第一张图片放到屏幕
	tmp=tmp1->next;
	
		while(1)
		{
						// 2，使用相应的库接口来显示指定的图片
						display(tmp->data, 50, 20);
						
						//printf("显示的图片是:%s\n",tmp->data);
						
					
						int c=chumo();//触摸
						switch(c)
						 {
							 case 1:
							 tmp=tmp1; 
						     break;
							 
							 case 2: 
							 tmp=tmp2; 
							 break;
							 
							 case 3: 
							 tmp=tmp3;							
							 break;
							 
							 
							 case 4: 
							 tmp=tmp4;							
							 break;
							 
							 
							 case 5: 
							 tmp=tmp5;							
							 break;
							 
							  case 6: 
							 tmp=tmp6;							
							 break;
							 
							  case 7: 
							 tmp=tmp7;							
							 break;
						 }
						
						
	}

}
/************************************按钮动画效果END************************/
