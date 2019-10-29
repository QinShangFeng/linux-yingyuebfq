
#include"common.h"//通用头文件

/************************触摸屏滑动******************************************/
int chumo()//触摸屏滑动
{
	//1.打开触摸屏
	int tp = open("/dev/input/event0", O_RDWR);
	// 2，读取坐标
	struct input_event buf;

	bool xdone = false;
	bool ydone = true;
	
    int x1,x2,x3,y1,y2,y3;
	while(1)
	{
		bzero(&buf, sizeof(buf));
		read(tp, &buf, sizeof(buf));

		if(buf.type == EV_ABS) // 获取到了一个绝对坐标的事件
		{
			if(buf.code == ABS_X && ydone) // 进一步确认: 是获取到了一个触摸屏的X轴坐标
			{
				x1=buf.value;//标记X轴坐标值
				xdone = true;
				ydone = false;
			}

			if(buf.code == ABS_Y && xdone) // 进一步确认: 是获取到了一个触摸屏的Y轴坐标
			{
				y1=buf.value;//标记X轴坐标值
				ydone = true;
				xdone = false;
			}
		}

		if(buf.type == EV_KEY) // 获取了一个按键类型的事件
		{
			if(buf.code == BTN_TOUCH) // 进一步确认: 是触摸屏的按压事件
			{
				// 进一步确认: 是按下了还是松开了

				if(buf.value > 0) 
				{
					x2=x1;
					y2=y1;
					//printf("\n手指按下了！\n");
				}
				if(buf.value == 0)
				{
				//	printf("手指松开了！\n");
					x3=x1;
					y3=y1;
					
					if((80<x2)&&(x2<350)&&(170<y2)&&
						(y2<400))
					{
						if((80<x3)&&(x3<350)&&(170<y3)&&
						(y3<400))
							{
								printf("播放》\n");
								return 1;
							}
					}
					if((440<x2)&&(x2<600)&&(170<y2)&&
						(y2<400))
					{
						if((440<x3)&&(x3<600)&&(170<y3)&&
						(y3<400))
							{
								printf("暂停||\n");
								return 2;
								
							}
					}
					if((690<x2)&&(x2<950)&&(170<y2)&&
						(y2<400))
					{
						if((690<x3)&&(x3<950)&&(170<y3)&&
						(y3<400))
							{
								printf("停止[]\n");
								return 3;
								
							}
					}
					if((90<x2)&&(x2<200)&&(500<y2)&&
						(y2<590))
					{
						if((90<x3)&&(x3<200)&&(500<y3)&&
						(y3<590))
							{
								printf("上一首<\n");
								return 4;
								
							}
					}
					if((290<x2)&&(x2<400)&&(500<y2)&&
						(y2<590))
					{
						if((290<x3)&&(x3<400)&&(500<y3)&&
						(y3<590))
							{
								printf("下一首>\n");
								return 5;
								
							}
					}
					if((690<x2)&&(x2<790)&&(450<y2)&&
						(y2<560))
					{
						if((690<x3)&&(x3<790)&&(450<y3)&&
						(y3<560))
							{
								printf("加音量+\n");
								return 6;
								
							}
					}
					if((890<x2)&&(x2<1000)&&(450<y2)&&
						(y2<560))
					{
						if((890<x3)&&(x3<1000)&&(450<y3)&&
						(y3<560))
							{
								printf("减音量-\n");
								return 7;
								
							}
					}
						
					
				}
			}
		}
	}
}	
/************************触摸屏滑动end******************************************/
	