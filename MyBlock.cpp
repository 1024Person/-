#include "stdafx.h"
#include "MyBlock.h"
/*//初始化方块，这个规定好了，方块是什么样的形状的
	virtual void initBlock();
	//旋转方块
	virtual void changeBlock();
	//左右移动
	virtual void L_R_Move();
	//向下移动
	virtual void DownMove();*/

CMyBlock::CMyBlock()
{
	

}


CMyBlock::~CMyBlock()
{

}
//向下移动
void CMyBlock::DownMove()
{
	for (char i = 0; i < 4; ++i)
	{
		this->BlockPoint[i].row++;
	}
}
//左右移动
void CMyBlock::L_R_Move(bool left)
{
	if (left)//左移
	{
		for (char i = 0; i < BLOCK_NUM; ++i)
		{
			this->BlockPoint[i].clu--;
		}
	}
	else//右移
	{
		for (char i = 0; i < BLOCK_NUM; ++i)
		{
			this->BlockPoint[i].clu++;
		}
	}
}
//获取方块数组坐标
m_Point* CMyBlock::getPoint()
{
	return this->BlockPoint;
}

/***********************************第一个方块***************************************/
//初始化方块
void _1::initBlock()
{
	//0代表水平，1代表竖直，默认为水平，然后在管理着规定是什么类型的
	this->BlockTapy = rand() % 2;
	//规定
	switch (this->BlockTapy)
	{	//四个方块横着的
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
		//四个方块竖着的
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

//旋转方块
void _1::changeBlock()
{
	
	switch (this->BlockTapy)
	{
	case 1://从竖着转到水平
		this->BlockPoint[ 0 ].row = this->BlockPoint[1].row;
		this->BlockPoint[0].clu = this->BlockPoint[1].clu - 1;
		this->BlockPoint[2].row = this->BlockPoint[1].row;
		this->BlockPoint[2].clu = this->BlockPoint[1].clu+1;
		this->BlockPoint[3].row = this->BlockPoint[1].row;
		this->BlockPoint[3].clu = this->BlockPoint[1].clu + 2;

		//旋转之后，状态就改变了
		this->BlockTapy = 0;
		break;
	case 0://从水平转到竖直
		this->BlockPoint[0].row = this->BlockPoint[1].row - 1;
		this->BlockPoint[0].clu = this->BlockPoint[1].clu;
		this->BlockPoint[2].row = this->BlockPoint[1].row + 1;
		this->BlockPoint[2].clu = this->BlockPoint[1].clu;
		this->BlockPoint[3].row = this->BlockPoint[1].row + 2;
		this->BlockPoint[3].clu = this->BlockPoint[1].clu; 
		//旋转之后，状态就改变了
		this->BlockTapy = 1;
		break;
	}





}
bool _1::isChange(PARR map)
{
//根据状态来进行判断是否可以旋转而不是根据类型进行旋转
	switch (this->BlockTapy)
	{
	case 1://从竖着转到水平
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
	case 0://从水平转到竖直
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

/********************************第二个方块************************************/
//初始化方块，这个规定好了，方块是什么样的形状的
void _2::initBlock()
{
	this->BlockTapy = rand() % 2;
	switch (this->BlockTapy)
	{
	case 0://横着的Z
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
	case 1:	//竖着的Z
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
//判读是否可以旋转
bool _2::isChange(PARR map)
{
	switch (this->BlockTapy)
	{
	case 0://横着的Z,从水平转到竖直
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
		//0代表的是横着的方块，要把横着的方块转成竖着的
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
	case 1://从竖直转到水平
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

/************************************第三个方块*****************************************/

//,正方形转不转都一样
bool _3::isChange(PARR map)
{
	return false;
}

void _3::changeBlock()
{

}

//初始化方块
void _3::initBlock()
{
	//横着下来的，坐标
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