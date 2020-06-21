#include "stdafx.h"
#include "Administrator.h"


CAdministrator::CAdministrator()
{
	initgraph(WIGHT, HIGHT);
	srand((unsigned)time(NULL));
	this->StartTime = 0.0f;
	this->fmp_map = new CMyMap;
	this->fmp_block = new _3;
	this->fmp_block->initBlock();
	this->fmp_block2 = NULL;
	this->BeginTime = 0.0f;
	this->BeginTime = 0.0f;
	this->Velity = 0.6f;
	this->dir = 0;
	this->GameOver = false;
	this->Score = 0;
}


CAdministrator::~CAdministrator()
{
	//释放从内存中申请来的内存
	DEL(this->fmp_block);
	DEL(this->fmp_map);
	DEL(this->fmp_block2);
	closegraph();
}
/*
	//初始化游戏，
	void initGame();
	//绘制游戏地图，
	void drawGame();
	//更新游戏数据
	void updateGame();
*/
void CAdministrator::initGame()
{
	
	//初始化地图
	this->fmp_map->initMap();
	//生成接下来要出现的方块
	this->SetShapeBlock();
	//初始化 2 方块坐标和方块状态
	this->fmp_block2->initBlock();

	//获取开始方块掉落时间和当前时间
	this->BeginTime = this->EndTime = timeGetTime()/1000.0f;
	//获取游戏开始时间
	this->StartTime = timeGetTime() / 1000.0f;

}
//游戏开始界面
void CAdministrator::DrawStratGame()
{
	setbkcolor(GREEN);
	cleardevice();
	settextcolor(RED);
	settextstyle(15, 15, "楷体");
	outtextxy(WIGHT / 3, HIGHT / 3, "俄罗斯方块小游戏");
	outtextxy(WIGHT / 3, HIGHT / 3 + SPACE * 2, "40期117号之杰");
	outtextxy(WIGHT / 3, HIGHT / 3 + SPACE * 4, "按任意键开始游戏");
	getch();
	setbkcolor(BLACK);
}
void CAdministrator::drawGame()
{
	BeginBatchDraw();
	cleardevice();

	
	this->fmp_map->drawMap();
	//提示信息输出
	
	settextcolor(RED);
	settextstyle(20, 15,"楷体");
	outtextxy(BOUNDARY, INTERVAL/2, "下一个方块");

	//画出信息窗口
	setlinecolor(GREEN);
	rectangle(BOUNDARY, INTERVAL, BOUNDARY + BORDER_W , INTERVAL + BORDER_H);
	setfillcolor(RED);

	//将下一次要出现的方块绘画出来
	for (char i = 0; i < BLOCK_NUM; ++i)
	{
		fillrectangle((this->fmp_block2->getPoint()[i].clu -2)* SIZE + BOUNDARY, this->fmp_block2->getPoint()[i].row*SIZE + INTERVAL, (this->fmp_block2->getPoint()[i].clu -1)*SIZE + BOUNDARY, (this->fmp_block2->getPoint()[i].row + 1)*SIZE + INTERVAL);
	}
	//输出游戏规则
	outtextxy(BOUNDARY, INTERVAL + BORDER_H * 3 / 2, "游戏帮助");
	outtextxy(BOUNDARY, INTERVAL + BORDER_H * 2 , "←A D→");
	outtextxy(BOUNDARY, (INTERVAL + BORDER_H) * 2, "   S ↓");
	//outtextxy(BOUNDARY, (INTERVAL * 3 + BORDER_H * 2), "   ");
	outtextxy(BOUNDARY, (INTERVAL * 3 + BORDER_H * 2) , "空格 = 旋转");

	outtextxy(BOUNDARY , (INTERVAL * 4 + BORDER_H * 2) , "Score:");
	char ScoreStr[4];
	itoa(this->Score, ScoreStr, 10);
	outtextxy(BOUNDARY + SPACE + SIZE * 2, (INTERVAL * 4 + BORDER_H * 2), ScoreStr);
	settextstyle(20, 15, "楷体");
	outtextxy(BOUNDARY-SIZE*2, (INTERVAL * 3 + BORDER_H * 3), "游戏难度正在增加");
	if (this->GameOver)
	{
		setbkcolor(GREEN);
		settextstyle(50, 40, "楷书");
		outtextxy(0 , MAP_H / 2 * SIZE, "游戏结束！");
	}
	EndBatchDraw();
	
}
//更新游戏数据
void CAdministrator::updateGame()
{
	
	//将上一次的方块给消除掉
	this->fmp_map->SetMapVal(this->fmp_block->getPoint(),m_null);
	
	//设置方块的下落
	//获取当时时间
	//是否加大难度
	this->EndTime = timeGetTime()/1000.0f;
	if (this->Velity>=0.3&&this->EndTime - this->StartTime >= 30)
	{
		this->StartTime = this->EndTime;
		this->Velity -= 0.05;
	}


	//是否下降
	if (this->EndTime - this->BeginTime >= this->Velity)
	{
		this->BeginTime = this->EndTime;
		this->fmp_block->DownMove();
	}
	//获取按键，进行方块的左右移动
	this->SetDir();
	if (this->isL_R_Move(this->dir))
	{
		switch (this->dir)
		{
		case 'a':
		case 'A':
			this->fmp_block->L_R_Move();
			break;
		case 'D':
		case 'd':
			this->fmp_block->L_R_Move(false);
			break;
		case ' ':
			if (this->fmp_block->isChange(this->fmp_map->getAddressMap()))
			{
				this->fmp_block->changeBlock();
			}
			break;
		case 'S':
		case 's':
			for (char i = 0; i < BLOCK_NUM; ++i)
			{
				if (!this->isAgain())
				this->fmp_block->DownMove();
			}
		}
		//将方块的方向归零
		this->dir = 0;
	}
	//判断是否应该再次生成一个
	//如果到达底部的话，就在生成一个方块
	if (this->isAgain())
	{
		this->DelMapBlock();
		this->AgainBornBlock();
		this->isGameOver();
	}
	//将更新过的方块坐标，赋值到地图中
	this->fmp_map->SetMapVal(this->fmp_block->getPoint(), m_block);

}
//设置方块的方向
void CAdministrator::SetDir()
{
	if (_kbhit())
		this->dir = _getch();
}
//判断是否要在生成一个方块
bool CAdministrator::isAgain()
{

	//判断方块的下面时候是底部,还要把整张地图返回出来
	for (char i = 0; i < BLOCK_NUM; ++i)
	{
		if ((this->fmp_block->getPoint() + i)->row == MAP_H - 2 )
		{
			this->fmp_map->SetMapVal(this->fmp_block->getPoint(), m_block_dead);
			return  true;
		}
	}
	for (char i = 0; i < BLOCK_NUM ; i++)
	{	
		//判断正在下落的方块下面是否是方块
		//判读正在下落的方块是否是已经落下的方块
		short x = this->fmp_map->getAddressMap()[(this->fmp_block->getPoint()+i)->row + 1][(this->fmp_block->getPoint()+i)->clu];
		if (x == m_block_dead)
		{
			this->fmp_map->SetMapVal(this->fmp_block->getPoint(), m_block_dead);
			return true;
		}
	}
	return false; 
}
//重新生成一个方块
void CAdministrator::AgainBornBlock()
{
	if (this->fmp_block != NULL)
	{
		delete this->fmp_block;
		this->fmp_block = this->fmp_block2;
	}
	//在生成一个 2号 方块
	this->SetShapeBlock();
	//初始化 2号 方块
	this->fmp_block2->initBlock();
}
//设置下一个方块的类型
void CAdministrator::SetShapeBlock()
{
	//设置下一个要下落的方块
	switch (rand() % BLOCK_KIND)
	{
	case 0:
		this->fmp_block2 = new _1;
		break;
	case 1:
		this->fmp_block2 = new _2;
		break;
	case 2:
		this->fmp_block2 = new _3;
		break;
	}
}
//判读方块是否可以左右移动
bool CAdministrator::isL_R_Move(char Dir)
{
	//是否可以左右移动有两种情况
	//１、如果两边是墙的话，就不能左右移动
	//2、如果两边是方块的话，就不能移动
	if (Dir == 'A' || Dir == 'a')
	{
		for (char i = 0; i < BLOCK_NUM; ++i)
		{
			//如果是左边界的话，  或者左边是方块,还是要计算偏移量，注意一级指针的偏移单位和二级指针的偏移单位不一样
			if ((this->fmp_block->getPoint()+i)->clu - 1 < 1||this->fmp_map->getAddressMap()[(this->fmp_block->getPoint()+i)->row][(this->fmp_block->getPoint()+i)->clu-1]==m_block_dead)
				return false;
		}
	}
	//如果是右边界
	else if (Dir == 'D' || Dir == 'd')
	{
		for (char i = 0; i < BLOCK_NUM; ++i)
		{
			//如果是右边界的话，  或者左边是方块,还是要计算偏移量，注意一级指针的偏移单位和二级指针的偏移单位不一样
			if (this->fmp_block->getPoint()[i].clu + 1 > MAP_W -2|| this->fmp_map->getAddressMap()[(this->fmp_block->getPoint()+i)->row][(this->fmp_block->getPoint()+ i )->clu+1] == m_block_dead)
				return false;
		}
	}
	return true;
}

//消行
void CAdministrator::DelMapBlock()
{
	PARR map = this->fmp_map->getAddressMap();

	for (char i = MAP_H - 2; i > 4; i--)
	{
		bool flag = true;//设置一个标记，来记录这一行是否应该被消除
		for (char j = 1; j < MAP_W - 1; j++)
		{
			if (map[i][j] == m_null)
				flag = false;
		}
		if (flag)
		{
			for (char n = i; n >4; n--)
			{
				for (char m = 1; m < MAP_W - 1; m++)
				{
					map[n][m] = map[n - 1][m];
				}
			}
			this->Score+=5;
			i++;//在判断一次掉落的方块是否应该被消除
		}
	}
}
//判读输赢
void CAdministrator::isGameOver()
{
	PARR map = this->fmp_map->getAddressMap();
	m_Point* Point = this->fmp_block->getPoint();
	for (char i = 0; i < BLOCK_NUM; i++)
	{
		//新产生的方块和以前就有的方块有重合
		if (map[Point[i].row][Point[i].clu] == m_block_dead)
		{
			this->GameOver = true;
		}
	}
}
//返回输赢记录
bool CAdministrator::getGameOver()
{
	return this->GameOver;
}
