#include "stdafx.h"
#include "MyBlock.h"
/*//��ʼ�����飬����涨���ˣ�������ʲô������״��
	virtual void initBlock();
	//��ת����
	virtual void changeBlock();
	//�����ƶ�
	virtual void L_R_Move();
	//�����ƶ�
	virtual void DownMove();*/

CMyBlock::CMyBlock()
{
	

}


CMyBlock::~CMyBlock()
{

}
//�����ƶ�
void CMyBlock::DownMove()
{
	for (char i = 0; i < 4; ++i)
	{
		this->BlockPoint[i].row++;
	}
}
//�����ƶ�
void CMyBlock::L_R_Move(bool left)
{
	if (left)//����
	{
		for (char i = 0; i < BLOCK_NUM; ++i)
		{
			this->BlockPoint[i].clu--;
		}
	}
	else//����
	{
		for (char i = 0; i < BLOCK_NUM; ++i)
		{
			this->BlockPoint[i].clu++;
		}
	}
}
//��ȡ������������
m_Point* CMyBlock::getPoint()
{
	return this->BlockPoint;
}

/***********************************��һ������***************************************/
//��ʼ������
void _1::initBlock()
{
	//0����ˮƽ��1������ֱ��Ĭ��Ϊˮƽ��Ȼ���ڹ����Ź涨��ʲô���͵�
	this->BlockTapy = rand() % 2;
	//�涨
	switch (this->BlockTapy)
	{	//�ĸ�������ŵ�
	case 0:
		//  1  2  3  4
		this->BlockPoint[0].row = 2;
		this->BlockPoint[0].clu = 3;
		this->BlockPoint[1].row = 2;
		this->BlockPoint[1].clu = 4;
		this->BlockPoint[2].row = 2;
		this->BlockPoint[2].clu = 5;
		this->BlockPoint[3].row = 2;
		this->BlockPoint[3].clu = 6;
		break;
	case 1:
		//�ĸ��������ŵ�
		//	1
		//	2
		//	3
		//	4
		this->BlockPoint[0].row = 1;
		this->BlockPoint[0].clu = 4;
		this->BlockPoint[1].row = 2;
		this->BlockPoint[1].clu = 4;
		this->BlockPoint[2].row = 3;
		this->BlockPoint[2].clu = 4;
		this->BlockPoint[3].row = 4;
		this->BlockPoint[3].clu = 4;
		break;
	}
}

//��ת����
void _1::changeBlock()
{
	
	switch (this->BlockTapy)
	{
	case 1://������ת��ˮƽ
		this->BlockPoint[ 0 ].row = this->BlockPoint[1].row;
		this->BlockPoint[0].clu = this->BlockPoint[1].clu - 1;
		this->BlockPoint[2].row = this->BlockPoint[1].row;
		this->BlockPoint[2].clu = this->BlockPoint[1].clu+1;
		this->BlockPoint[3].row = this->BlockPoint[1].row;
		this->BlockPoint[3].clu = this->BlockPoint[1].clu + 2;

		//��ת֮��״̬�͸ı���
		this->BlockTapy = 0;
		break;
	case 0://��ˮƽת����ֱ
		this->BlockPoint[0].row = this->BlockPoint[1].row - 1;
		this->BlockPoint[0].clu = this->BlockPoint[1].clu;
		this->BlockPoint[2].row = this->BlockPoint[1].row + 1;
		this->BlockPoint[2].clu = this->BlockPoint[1].clu;
		this->BlockPoint[3].row = this->BlockPoint[1].row + 2;
		this->BlockPoint[3].clu = this->BlockPoint[1].clu; 
		//��ת֮��״̬�͸ı���
		this->BlockTapy = 1;
		break;
	}





}
bool _1::isChange(PARR map)
{
//����״̬�������ж��Ƿ������ת�����Ǹ������ͽ�����ת
	switch (this->BlockTapy)
	{
	case 1://������ת��ˮƽ
		if (map[this->BlockPoint[1].row][this->BlockPoint[1].clu-1] != m_null
			|| map[this->BlockPoint[1].row][this->BlockPoint[1].clu + 1] != m_null
			|| map[this->BlockPoint[1].row][this->BlockPoint[1].clu + 2] != m_null
			|| map[this->BlockPoint[1].row - 1][this->BlockPoint[1].clu - 1] != m_null
			|| map[this->BlockPoint[2].row][this->BlockPoint[1].clu + 1] != m_null
			|| map[this->BlockPoint[2].row][this->BlockPoint[1].clu + 2] != m_null
			|| map[this->BlockPoint[3].row][this->BlockPoint[3].clu + 1] != m_null
			|| map[this->BlockPoint[3].row][this->BlockPoint[3].clu + 2] != m_null)
			return false;
		break;
	case 0://��ˮƽת����ֱ
		if (   map[this->BlockPoint[ 1 ].row - 1][this->BlockPoint[ 1 ].clu] != m_null
			||map[this->BlockPoint[ 1 ].row + 1][this->BlockPoint[ 1 ].clu] != m_null
			||map[this->BlockPoint[ 1 ].row + 2][this->BlockPoint[ 1 ].clu] != m_null
			||map[this->BlockPoint[ 0 ].row - 1][this->BlockPoint[ 0 ].clu] != m_null
			||map[this->BlockPoint[ 2 ].row - 1][this->BlockPoint[ 2 ].clu] != m_null
			||map[this->BlockPoint[ 2 ].row - 2][this->BlockPoint[ 2 ].clu] != m_null
			|| map[this->BlockPoint[ 3 ].row - 1][this->BlockPoint[ 3 ].clu] != m_null
			|| map[this->BlockPoint[ 3 ].row - 2][this->BlockPoint[ 3 ].clu] != m_null
			)
		return false;
		break;
	}
	return true;
}

/********************************�ڶ�������************************************/
//��ʼ�����飬����涨���ˣ�������ʲô������״��
void _2::initBlock()
{
	this->BlockTapy = rand() % 2;
	switch (this->BlockTapy)
	{
	case 0://���ŵ�Z
		//			1	2
		//				3	4
		this->BlockPoint[0].row = 1;
		this->BlockPoint[0].clu = 3;
		this->BlockPoint[1].row = 1;
		this->BlockPoint[1].clu = 4;
		this->BlockPoint[2].row = 2;
		this->BlockPoint[2].clu = 4;
		this->BlockPoint[3].row = 2;
		this->BlockPoint[3].clu = 5;
	
		break;
	case 1:	//���ŵ�Z
		//			1
		//		3	2
		//		4
		this->BlockPoint[0].row = 1;
		this->BlockPoint[0].clu = 4;
		this->BlockPoint[1].row = 2;
		this->BlockPoint[1].clu = 4;
		this->BlockPoint[2].row = 2;
		this->BlockPoint[2].clu = 3;
		this->BlockPoint[3].row = 3;
		this->BlockPoint[3].clu = 3;
		
		break;
	}
}
//�ж��Ƿ������ת
bool _2::isChange(PARR map)
{
	switch (this->BlockTapy)
	{
	case 0://���ŵ�Z,��ˮƽת����ֱ
		if (map[this->BlockPoint[2].row][this->BlockPoint[2].clu - 1] != m_null
			|| map[this->BlockPoint[2].row + 1][this->BlockPoint[2].clu - 1] != m_null
			|| map[this->BlockPoint[2].row + 1][this->BlockPoint[2].clu] != m_null
			|| map[this->BlockPoint[2].row + 1][this->BlockPoint[2].clu + 1] != m_null)
			return false;

		break;
	case 1:
		if (map[this->BlockPoint[3].row][this->BlockPoint[3].clu+1]!=m_null
			||map[this->BlockPoint[1].row][this->BlockPoint[1].clu +1 ]!=m_null
			||map[this->BlockPoint[1].row +1 ][this->BlockPoint[1].clu + 1]!=m_null
			||map[this->BlockPoint[0].row][this->BlockPoint[0].clu -1 ]!=m_null
			||map[this->BlockPoint[0].row-1][this->BlockPoint[0].clu]!=m_null
			||map[this->BlockPoint[0].row -1][this->BlockPoint[0].clu - 1]!=m_null)
			return false;
		break;
	}
	return true;
}
void _2::changeBlock()
{
	switch (this->BlockTapy)
	{
		//0������Ǻ��ŵķ��飬Ҫ�Ѻ��ŵķ���ת�����ŵ�
	case 0:
		this->BlockPoint[0].row = this->BlockPoint[2].row - 1;
		this->BlockPoint[0].clu = this->BlockPoint[2].clu;
		this->BlockPoint[1].row = this->BlockPoint[2].row ;
		this->BlockPoint[1].clu = this->BlockPoint[2].clu;
		this->BlockPoint[3].row = this->BlockPoint[2].row + 1;
		this->BlockPoint[3].clu = this->BlockPoint[2].clu - 1 ;
		this->BlockPoint[2].row = this->BlockPoint[2].row;
		this->BlockPoint[2].clu = this->BlockPoint[2].clu - 1;
		
		this->BlockTapy = 1;
		break;
	case 1://����ֱת��ˮƽ
		this->BlockPoint[0].row = this->BlockPoint[1].row - 1;
		this->BlockPoint[0].clu = this->BlockPoint[1].clu - 1;
		this->BlockPoint[2].row = this->BlockPoint[1].row;
		this->BlockPoint[2].clu = this->BlockPoint[1].clu;
		this->BlockPoint[3].row = this->BlockPoint[1].row;
		this->BlockPoint[3].clu = this->BlockPoint[1].clu + 1;
		this->BlockPoint[1].row = this->BlockPoint[1].row - 1;
		this->BlockPoint[1].clu = this->BlockPoint[1].clu;
		this->BlockTapy = 0;
		break;
	}
}

/************************************����������*****************************************/

//,������ת��ת��һ��
bool _3::isChange(PARR map)
{
	return false;
}

void _3::changeBlock()
{

}

//��ʼ������
void _3::initBlock()
{
	//���������ģ�����
	//		1 2
	//		4 3
	this->BlockPoint[0].row = 2;
	this->BlockPoint[0].clu = 4;
	this->BlockPoint[1].row = 2;
	this->BlockPoint[1].clu = 5;
	this->BlockPoint[2].row = 3;
	this->BlockPoint[2].clu = 5;
	this->BlockPoint[3].row = 3;
	this->BlockPoint[3].clu = 4;

}