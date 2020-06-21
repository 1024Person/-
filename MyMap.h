#pragma once
class CMyMap
{
public:char m_map[MAP_H][MAP_W];
public:
	//初始化地图
	void initMap();
	//绘画地图
	void drawMap()const;
	//设置给地图赋值
	void SetMapVal(const m_Point* point,int Val);

public:
	//提供接口，返回整张地图的地址
	PARR getAddressMap();

	CMyMap();
	~CMyMap();
};

