#pragma once
class CMyBlock
{
protected:
	//��������
	m_Point BlockPoint[BLOCK_NUM];
	//�����״̬����ˮƽ������ֱ��������4��״̬��
	char BlockTapy;
public:
	//��ʼ�����飬����涨���ˣ�������ʲô������״��
	virtual void initBlock() = 0;
	//��ת����
	virtual void changeBlock() = 0;
	//�ж��Ƿ������ת
	virtual bool isChange(PARR map) = 0;
public:
	//�����ƶ�
	void L_R_Move(bool left=true) ;
	//�����ƶ�
	void DownMove();
	//�ṩ�ӿڣ����ط�������
   m_Point * getPoint();
public:
	CMyBlock();
	~CMyBlock();
};
//ˮƽ�ĸ�����
class _1 :public CMyBlock
{
public:
	//��ʼ�����飬����涨���ˣ�������ʲô������״��
	virtual void initBlock();
	//��ת����
	virtual void changeBlock();
	//�ж��Ƿ������ת
	virtual bool isChange(PARR map);

};
//���ŵ�Z
class _2 :public CMyBlock
{
public:
	//��ʼ�����飬����涨���ˣ�������ʲô������״��
	virtual void initBlock();
	//��ת����
	virtual void changeBlock();
	//�ж��Ƿ������ת
	virtual bool isChange(PARR map);

};
//������
class _3 :public CMyBlock
{
public:
	//��ʼ�����飬����涨���ˣ�������ʲô������״��
	virtual void initBlock();
	//��ת����
	virtual void changeBlock();
	//�ж��Ƿ������ת
	virtual bool isChange(PARR map);

};