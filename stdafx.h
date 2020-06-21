// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once
#include "targetver.h"
#include <iostream>
#include <tchar.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<easyx.h>
#pragma comment (lib,"winmm.lib")
using namespace std;
struct m_Point						//方块坐标	
{
	short row;
	short clu;
};								
#define BLOCK_NUM 4					//方块数
#define MAP_W 12					//地图的宽
#define MAP_H 24					//地图的高
#define HIGHT 720					//绘图窗口的高
#define WIGHT 700					//绘图窗口的宽
#define BOUNDARY 500				//输出信息栏的坐标分界线
#define INTERVAL 50					//信息栏和顶部的间隔
#define BORDER_W 150				//边框的宽度
#define BORDER_H 150				//边框的高度
#define SPACE 50					//左右间隔
#define SIZE 30						//每一个小方块的大小
#define BLOCK_KIND 3				//方块的种类数
typedef char(*PARR)[MAP_W];			//二维数组指针类型


							//正在下落的方块  已经下落的方块			
enum  {m_null,m_wall,m_block,m_block_dead};//枚举类型，用来给地图赋值

#define DEL(p){if(p!=NULL)delete p;p=NULL;}
#include"MyBlock.h"
#include"MyMap.h"
#include"Administrator.h"
// TODO:  在此处引用程序需要的其他头文件
