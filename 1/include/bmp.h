#ifndef __BMP_H_
#define __BMP_H_

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <pthread.h>

#define LCD "/dev/fb0"

#define BACKGROUND "./res/bmp/background.bmp"
#define BAR        "./res/bmp/bar.bmp"
#define LOGO       "./res/bmp/logo.bmp"
#define KEYON      "./res/bmp/key_on.bmp"
#define KEYOFF     "./res/bmp/key_off.bmp"


struct bitmap_header
{
	int16_t type;
	int32_t size; // 整个文件大小
	int16_t reserved1;
	int16_t reserved2;
	int32_t offbits; // bmp图像数据偏移量
}__attribute__((packed));

struct bitmap_info
{
	int32_t size; // 本结构大小	
	int32_t width; // 单位：像素
	int32_t height;// 单位：像素
	int16_t planes; // 总为零

	int16_t bit_count; // 色深:24（1像素=24位=3字节）
	int32_t compression;
	int32_t size_img; // bmp数据大小，必须是4的整数倍
	int32_t X_pel;
	int32_t Y_pel;
	int32_t clrused;
	int32_t clrImportant;
}__attribute__((packed));

struct rgb_quad
{
	int8_t blue;
	int8_t green;
	int8_t red;
	int8_t reserved;
}__attribute__((packed));


struct image_info
{
	int width;
	int height;
	int pixel_size;
};

void display(char *bmpfile, int x, int y);
void freelcd(void);


#endif
