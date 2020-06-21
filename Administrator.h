#pragma once
class CAdministrator
{
	CMyBlock* fmp_block;
	CMyMap* fmp_map;
	CMyBlock* fmp_block2;
	int Score;//分数
	float BeginTime;//获取上一个方块掉落的时间
	float EndTime;//获取当时的时间
	float Velity;//设置间隔速度，就是方块下落的速度
	float StartTime;//获取游戏难度增加开始时间
	char dir;
	bool GameOver;//记录游戏是否结束

public:
	//游戏开始界面
	void DrawStratGame();
	//初始化游戏，
	void initGame();
	//绘制游戏地图，
	void drawGame();
	//更新游戏数据
	void updateGame();
	//游戏结束
	bool getGameOver();
private:
	//获取按键
	void SetDir();
	//判断方块是否已经到底了
	bool isAgain();
	//判断方块是否可以左右移动
	bool isL_R_Move(char Dir);
	//重新生成一个方块
	void AgainBornBlock();
	//设置生成的下一个方块的形状
	void SetShapeBlock();
	//消行
	void DelMapBlock();
	//判断是否输了
	void isGameOver();//
public:
	CAdministrator();
	~CAdministrator();
};

