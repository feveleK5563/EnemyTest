#pragma once
#include "EnemyMovePattern.h"
#include "EnemyMoveTransition.h"

class EnemyMoveManager
{
public:
	int timeCnt;				//���Ԍv��
	int nowPatternOrder;		//���݂̓���p�^�[���ԍ�
	
	vector<EnemyMovePattern*>		empattern;		//����p�^�[��
	vector<EnemyMoveTransition*>	emtransition;	//�p�^�[���J�ڕ��@

	EnemyMoveManager();
	~EnemyMoveManager();

	//����p�^�[���W���̐���
	void CreateMotionPattern(int* moveNum,				//����ԍ�����ꂽ�z��̃A�h���X�l
							 int* durationTime,			//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
							 int  totalMoveNum,			//����̑���
							 int  transitionNum,		//����p�^�[���̑J�ڕ��@�̔ԍ�
							 int  transMaxTime = 0);	//���ԑJ�ڑI�����̑J�ڎ���

	//���݂̓���p�^�[�������s����
	void Move(ML::Vec2& pos);

	//����p�^�[�����w��ԍ��ɑJ�ڂ�����
	void PatternTransition(int patternNum);

	//����p�^�[���̑J�ڕ��@��ݒ肷��
	void SetTransition(int transitionNum, int transMaxTime);
};