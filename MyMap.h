#pragma once
class CMyMap
{
public:char m_map[MAP_H][MAP_W];
public:
	//��ʼ����ͼ
	void initMap();
	//�滭��ͼ
	void drawMap()const;
	//���ø���ͼ��ֵ
	void SetMapVal(const m_Point* point,int Val);

public:
	//�ṩ�ӿڣ��������ŵ�ͼ�ĵ�ַ
	PARR getAddressMap();

	CMyMap();
	~CMyMap();
};

