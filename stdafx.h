// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once
#include "targetver.h"
#include <iostream>
#include <tchar.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<easyx.h>
#pragma comment (lib,"winmm.lib")
using namespace std;
struct m_Point						//��������	
{
	short row;
	short clu;
};								
#define BLOCK_NUM 4					//������
#define MAP_W 12					//��ͼ�Ŀ�
#define MAP_H 24					//��ͼ�ĸ�
#define HIGHT 720					//��ͼ���ڵĸ�
#define WIGHT 700					//��ͼ���ڵĿ�
#define BOUNDARY 500				//�����Ϣ��������ֽ���
#define INTERVAL 50					//��Ϣ���Ͷ����ļ��
#define BORDER_W 150				//�߿�Ŀ��
#define BORDER_H 150				//�߿�ĸ߶�
#define SPACE 50					//���Ҽ��
#define SIZE 30						//ÿһ��С����Ĵ�С
#define BLOCK_KIND 3				//�����������
typedef char(*PARR)[MAP_W];			//��ά����ָ������


							//��������ķ���  �Ѿ�����ķ���			
enum  {m_null,m_wall,m_block,m_block_dead};//ö�����ͣ���������ͼ��ֵ

#define DEL(p){if(p!=NULL)delete p;p=NULL;}
#include"MyBlock.h"
#include"MyMap.h"
#include"Administrator.h"
// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
