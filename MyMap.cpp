#include "stdafx.h"
#include "MyMap.h"

/*	
	//��ʼ����ͼ
	void initMap();
	//�滭��ͼ
	void drawMap();

*/
CMyMap::CMyMap()
{
}


CMyMap::~CMyMap()
{
}
//��ʼ����ͼ
void CMyMap::initMap()
{
	
	//����ͼ��ʼ��Ϊ0������յ�
	memset(m_map, 0, sizeof(char)*MAP_H*MAP_W);
	
	
	//��ͼ������ΧǽΧ����
	//��������
	for (char i = 0; i < MAP_W; i += MAP_W - 1)
	{
		for (char j = 0; j < MAP_H; j++)
		{
			//map [ j ] [ i ]������� j ���У����߸�ֵ��
			this->m_map[j][i] = m_wall;
		}
	}
	//�������߸�ֵ
	for (char i = 0; i < MAP_H; i += MAP_H - 1)
	{
		for (char j = 0; j < MAP_W; j++)
		{
			//map [ i ] [ j ]
			this->m_map[i][j] = m_wall;
		}
	}
}
//���Ƶ�ͼ
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
//���ø���ͼ��ֵ
void CMyMap::SetMapVal(const m_Point* point,int Val)
{
	for (short i = 0; i < BLOCK_NUM;++i)
		m_map[(point+i)->row] [(point+i)->clu] = Val;
}
//�ӿں������������ŵ�ͼ���׵�ַ
PARR CMyMap::getAddressMap()
{
	return m_map;
}
