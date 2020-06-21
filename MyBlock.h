#pragma once
class CMyBlock
{
protected:
	//方块坐标
	m_Point BlockPoint[BLOCK_NUM];
	//方块的状态，（水平或者竖直，最多就是4种状态）
	char BlockTapy;
public:
	//初始化方块，这个规定好了，方块是什么样的形状的
	virtual void initBlock() = 0;
	//旋转方块
	virtual void changeBlock() = 0;
	//判读是否可以旋转
	virtual bool isChange(PARR map) = 0;
public:
	//左右移动
	void L_R_Move(bool left=true) ;
	//向下移动
	void DownMove();
	//提供接口，返回方块坐标
   m_Point * getPoint();
public:
	CMyBlock();
	~CMyBlock();
};
//水平四个方块
class _1 :public CMyBlock
{
public:
	//初始化方块，这个规定好了，方块是什么样的形状的
	virtual void initBlock();
	//旋转方块
	virtual void changeBlock();
	//判读是否可以旋转
	virtual bool isChange(PARR map);

};
//正着的Z
class _2 :public CMyBlock
{
public:
	//初始化方块，这个规定好了，方块是什么样的形状的
	virtual void initBlock();
	//旋转方块
	virtual void changeBlock();
	//判读是否可以旋转
	virtual bool isChange(PARR map);

};
//正方形
class _3 :public CMyBlock
{
public:
	//初始化方块，这个规定好了，方块是什么样的形状的
	virtual void initBlock();
	//旋转方块
	virtual void changeBlock();
	//判读是否可以旋转
	virtual bool isChange(PARR map);

};