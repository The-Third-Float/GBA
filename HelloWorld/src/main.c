/*************************************************************************
    > File Name: main.c
    > Title: 
    > Author: PeterShen
    > Mail: peter704678976@126.com 
    > Created Time: 2019年03月07日 星期四 22时55分17秒
 ************************************************************************/

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

#define REG_DISPCNT *(u16*)0x04000000  // 显示寄存器地址
#define VRAM 0x06000000  // 图像缓冲区地址
#define PALETTE 0x5000000  // 调色板地址
#define MODE_4 0x04  // mode4标志
#define BG2_ENABLE 0x0400  // BG_2标志
#define SetMode(Mode) REG_DISPCNT=(Mode) // 设置显示模式的宏定义

#include "helloworld.h"  // 包含图像调色板和数据的头文件

u16* palette_mem=(u16*)PALETTE; // 系统调色板

u16* video_buffer=(u16*)VRAM; // 图像缓冲区
void Draw(u16* src_palette,u16* src_data,u16* dst_palette,u16* dst_data);

int main()
{
    // 设置屏幕模式,这里使用MODE_4
    SetMode (MODE_4 | BG2_ENABLE); 

    // helloworld_pal和helloworld_gfx是在"helloworld.h"定义的调色板和图像数据数组名
    Draw((u16*)helloworld_pal,(u16*)helloworld_gfx,palette_mem,video_buffer);

    // 死循环
    while(1)
    { ;}
}

// MODE_4绘图函数
void Draw(u16* src_palette,u16* src_data,u16* dst_palette,u16* dst_data)
{
    int loop,x,y;

    // 写入目的调色板
    for(loop = 0; loop < 256; loop++)
        dst_palette[loop] = src_palette[loop];

    // 写入图像缓冲区
    for(x = 0; x < 120; x++)
        for(y = 0; y < 160; y++)
              dst_data[(y) *120 + (x)]=src_data[(y) *120 + (x)];
}

