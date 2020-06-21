#include "stdafx.h"
#include "MyMap.h"

/*	
	//初始化地图
	void initMap();
	//绘画地图
	void drawMap();

*/
CMyMap::CMyMap()
{
}


CMyMap::~CMyMap()
{
}
//初始化地图
void CMyMap::initMap()
{
	
	//将地图初始化为0，代表空地
	memset(m_map, 0, sizeof(char)*MAP_H*MAP_W);
	
	
	//地图两边用围墙围起来
	//左右两边
	for (char i = 0; i < MAP_W; i += MAP_W - 1)
	{
		for (char j = 0; j < MAP_H; j++)
		{
			//map [ j ] [ i ]这里就是 j 是行，两边赋值，
			this->m_map[j][i] = m_wall;
		}
	}
	//上下两边赋值
	for (char i = 0; i < MAP_H; i += MAP_H - 1)
	{
		for (char j = 0; j < MAP_W; j++)
		{
			//map [ i ] [ j ]
			this->m_map[i][j] = m_wall;
		}
	}
}
//绘制地图
void CMyMap::drawMap()const
{
	setlinecolor(RED);
	for (char i = 0; i < MAP_H ; i++)
	{
		for (char j = 0; j < MAP_W; j++)
		{
			switch (this->m_map[i][j])
			{
			case m_null:
				break;
			case m_wall:
				setfillcolor(YELLOW);
				fillrectangle(j * SIZE + SPACE, i*SIZE, (j + 1)*SIZE+SPACE, (i + 1)* SIZE);
				break;
			case m_block:
				setfillcolor(WHITE);
				fillrectangle(j*SIZE + SPACE, i*SIZE, (j + 1)*SIZE + SPACE, (i + 1)*SIZE);
				break;
			case m_block_dead:
				setfillcolor(BLUE);
				
				fillrectangle(j*SIZE + SPACE, i*SIZE, (j + 1)*SIZE + SPACE,(i+1)*SIZE);
				break;
			}
		}
	}
}
//设置给地图赋值
void CMyMap::SetMapVal(const m_Point* point,int Val)
{
	for (short i = 0; i < BLOCK_NUM;++i)
		m_map[(point+i)->row] [(point+i)->clu] = Val;
}
//接口函数，返回整张地图的首地址
PARR CMyMap::getAddressMap()
{
	return m_map;
}
