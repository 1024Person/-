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
	//�ͷŴ��ڴ������������ڴ�
	DEL(this->fmp_block);
	DEL(this->fmp_map);
	DEL(this->fmp_block2);
	closegraph();
}
/*
	//��ʼ����Ϸ��
	void initGame();
	//������Ϸ��ͼ��
	void drawGame();
	//������Ϸ����
	void updateGame();
*/
void CAdministrator::initGame()
{
	
	//��ʼ����ͼ
	this->fmp_map->initMap();
	//���ɽ�����Ҫ���ֵķ���
	this->SetShapeBlock();
	//��ʼ�� 2 ��������ͷ���״̬
	this->fmp_block2->initBlock();

	//��ȡ��ʼ�������ʱ��͵�ǰʱ��
	this->BeginTime = this->EndTime = timeGetTime()/1000.0f;
	//��ȡ��Ϸ��ʼʱ��
	this->StartTime = timeGetTime() / 1000.0f;

}
//��Ϸ��ʼ����
void CAdministrator::DrawStratGame()
{
	setbkcolor(GREEN);
	cleardevice();
	settextcolor(RED);
	settextstyle(15, 15, "����");
	outtextxy(WIGHT / 3, HIGHT / 3, "����˹����С��Ϸ");
	outtextxy(WIGHT / 3, HIGHT / 3 + SPACE * 2, "40��117��֮��");
	outtextxy(WIGHT / 3, HIGHT / 3 + SPACE * 4, "���������ʼ��Ϸ");
	getch();
	setbkcolor(BLACK);
}
void CAdministrator::drawGame()
{
	BeginBatchDraw();
	cleardevice();

	
	this->fmp_map->drawMap();
	//��ʾ��Ϣ���
	
	settextcolor(RED);
	settextstyle(20, 15,"����");
	outtextxy(BOUNDARY, INTERVAL/2, "��һ������");

	//������Ϣ����
	setlinecolor(GREEN);
	rectangle(BOUNDARY, INTERVAL, BOUNDARY + BORDER_W , INTERVAL + BORDER_H);
	setfillcolor(RED);

	//����һ��Ҫ���ֵķ���滭����
	for (char i = 0; i < BLOCK_NUM; ++i)
	{
		fillrectangle((this->fmp_block2->getPoint()[i].clu -2)* SIZE + BOUNDARY, this->fmp_block2->getPoint()[i].row*SIZE + INTERVAL, (this->fmp_block2->getPoint()[i].clu -1)*SIZE + BOUNDARY, (this->fmp_block2->getPoint()[i].row + 1)*SIZE + INTERVAL);
	}
	//�����Ϸ����
	outtextxy(BOUNDARY, INTERVAL + BORDER_H * 3 / 2, "��Ϸ����");
	outtextxy(BOUNDARY, INTERVAL + BORDER_H * 2 , "��A D��");
	outtextxy(BOUNDARY, (INTERVAL + BORDER_H) * 2, "   S ��");
	//outtextxy(BOUNDARY, (INTERVAL * 3 + BORDER_H * 2), "   ");
	outtextxy(BOUNDARY, (INTERVAL * 3 + BORDER_H * 2) , "�ո� = ��ת");

	outtextxy(BOUNDARY , (INTERVAL * 4 + BORDER_H * 2) , "Score:");
	char ScoreStr[4];
	itoa(this->Score, ScoreStr, 10);
	outtextxy(BOUNDARY + SPACE + SIZE * 2, (INTERVAL * 4 + BORDER_H * 2), ScoreStr);
	settextstyle(20, 15, "����");
	outtextxy(BOUNDARY-SIZE*2, (INTERVAL * 3 + BORDER_H * 3), "��Ϸ�Ѷ���������");
	if (this->GameOver)
	{
		setbkcolor(GREEN);
		settextstyle(50, 40, "����");
		outtextxy(0 , MAP_H / 2 * SIZE, "��Ϸ������");
	}
	EndBatchDraw();
	
}
//������Ϸ����
void CAdministrator::updateGame()
{
	
	//����һ�εķ����������
	this->fmp_map->SetMapVal(this->fmp_block->getPoint(),m_null);
	
	//���÷��������
	//��ȡ��ʱʱ��
	//�Ƿ�Ӵ��Ѷ�
	this->EndTime = timeGetTime()/1000.0f;
	if (this->Velity>=0.3&&this->EndTime - this->StartTime >= 30)
	{
		this->StartTime = this->EndTime;
		this->Velity -= 0.05;
	}


	//�Ƿ��½�
	if (this->EndTime - this->BeginTime >= this->Velity)
	{
		this->BeginTime = this->EndTime;
		this->fmp_block->DownMove();
	}
	//��ȡ���������з���������ƶ�
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
		//������ķ������
		this->dir = 0;
	}
	//�ж��Ƿ�Ӧ���ٴ�����һ��
	//�������ײ��Ļ�����������һ������
	if (this->isAgain())
	{
		this->DelMapBlock();
		this->AgainBornBlock();
		this->isGameOver();
	}
	//�����¹��ķ������꣬��ֵ����ͼ��
	this->fmp_map->SetMapVal(this->fmp_block->getPoint(), m_block);

}
//���÷���ķ���
void CAdministrator::SetDir()
{
	if (_kbhit())
		this->dir = _getch();
}
//�ж��Ƿ�Ҫ������һ������
bool CAdministrator::isAgain()
{

	//�жϷ��������ʱ���ǵײ�,��Ҫ�����ŵ�ͼ���س���
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
		//�ж���������ķ��������Ƿ��Ƿ���
		//�ж���������ķ����Ƿ����Ѿ����µķ���
		short x = this->fmp_map->getAddressMap()[(this->fmp_block->getPoint()+i)->row + 1][(this->fmp_block->getPoint()+i)->clu];
		if (x == m_block_dead)
		{
			this->fmp_map->SetMapVal(this->fmp_block->getPoint(), m_block_dead);
			return true;
		}
	}
	return false; 
}
//��������һ������
void CAdministrator::AgainBornBlock()
{
	if (this->fmp_block != NULL)
	{
		delete this->fmp_block;
		this->fmp_block = this->fmp_block2;
	}
	//������һ�� 2�� ����
	this->SetShapeBlock();
	//��ʼ�� 2�� ����
	this->fmp_block2->initBlock();
}
//������һ�����������
void CAdministrator::SetShapeBlock()
{
	//������һ��Ҫ����ķ���
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
//�ж������Ƿ���������ƶ�
bool CAdministrator::isL_R_Move(char Dir)
{
	//�Ƿ���������ƶ����������
	//�������������ǽ�Ļ����Ͳ��������ƶ�
	//2����������Ƿ���Ļ����Ͳ����ƶ�
	if (Dir == 'A' || Dir == 'a')
	{
		for (char i = 0; i < BLOCK_NUM; ++i)
		{
			//�������߽�Ļ���  ��������Ƿ���,����Ҫ����ƫ������ע��һ��ָ���ƫ�Ƶ�λ�Ͷ���ָ���ƫ�Ƶ�λ��һ��
			if ((this->fmp_block->getPoint()+i)->clu - 1 < 1||this->fmp_map->getAddressMap()[(this->fmp_block->getPoint()+i)->row][(this->fmp_block->getPoint()+i)->clu-1]==m_block_dead)
				return false;
		}
	}
	//������ұ߽�
	else if (Dir == 'D' || Dir == 'd')
	{
		for (char i = 0; i < BLOCK_NUM; ++i)
		{
			//������ұ߽�Ļ���  ��������Ƿ���,����Ҫ����ƫ������ע��һ��ָ���ƫ�Ƶ�λ�Ͷ���ָ���ƫ�Ƶ�λ��һ��
			if (this->fmp_block->getPoint()[i].clu + 1 > MAP_W -2|| this->fmp_map->getAddressMap()[(this->fmp_block->getPoint()+i)->row][(this->fmp_block->getPoint()+ i )->clu+1] == m_block_dead)
				return false;
		}
	}
	return true;
}

//����
void CAdministrator::DelMapBlock()
{
	PARR map = this->fmp_map->getAddressMap();

	for (char i = MAP_H - 2; i > 4; i--)
	{
		bool flag = true;//����һ����ǣ�����¼��һ���Ƿ�Ӧ�ñ�����
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
			i++;//���ж�һ�ε���ķ����Ƿ�Ӧ�ñ�����
		}
	}
}
//�ж���Ӯ
void CAdministrator::isGameOver()
{
	PARR map = this->fmp_map->getAddressMap();
	m_Point* Point = this->fmp_block->getPoint();
	for (char i = 0; i < BLOCK_NUM; i++)
	{
		//�²����ķ������ǰ���еķ������غ�
		if (map[Point[i].row][Point[i].clu] == m_block_dead)
		{
			this->GameOver = true;
		}
	}
}
//������Ӯ��¼
bool CAdministrator::getGameOver()
{
	return this->GameOver;
}
