#pragma once
#include "EnemyMovePattern.h"

class EnemyMoveManager
{
public:
	int timeCnt;			//���Ԍv��
	int nowPatternOrder;		//���݂̓���p�^�[���ԍ�
	
	vector<EnemyMovePattern*> empattern;	//����p�^�[��

	EnemyMoveManager();
	~EnemyMoveManager();

	//����p�^�[���W���̐���
	void CreateMotionPattern(int* moveNum,			//����ԍ�����ꂽ�z��̃A�h���X�l
							 int* durationTime,		//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
							 int  totalMoveNum);	//����̑���

	//���݂̓���p�^�[�������s����
	void Move(ML::Vec2& pos, const DI::VGamePad& gp);

	//����p�^�[�����w��ԍ��ɑJ�ڂ�����
	void PatternTransition(int patternNum);
};