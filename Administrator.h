#pragma once
class CAdministrator
{
	CMyBlock* fmp_block;
	CMyMap* fmp_map;
	CMyBlock* fmp_block2;
	int Score;//����
	float BeginTime;//��ȡ��һ����������ʱ��
	float EndTime;//��ȡ��ʱ��ʱ��
	float Velity;//���ü���ٶȣ����Ƿ���������ٶ�
	float StartTime;//��ȡ��Ϸ�Ѷ����ӿ�ʼʱ��
	char dir;
	bool GameOver;//��¼��Ϸ�Ƿ����

public:
	//��Ϸ��ʼ����
	void DrawStratGame();
	//��ʼ����Ϸ��
	void initGame();
	//������Ϸ��ͼ��
	void drawGame();
	//������Ϸ����
	void updateGame();
	//��Ϸ����
	bool getGameOver();
private:
	//��ȡ����
	void SetDir();
	//�жϷ����Ƿ��Ѿ�������
	bool isAgain();
	//�жϷ����Ƿ���������ƶ�
	bool isL_R_Move(char Dir);
	//��������һ������
	void AgainBornBlock();
	//�������ɵ���һ���������״
	void SetShapeBlock();
	//����
	void DelMapBlock();
	//�ж��Ƿ�����
	void isGameOver();//
public:
	CAdministrator();
	~CAdministrator();
};

