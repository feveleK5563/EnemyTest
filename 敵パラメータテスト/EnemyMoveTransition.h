#pragma once
#include "MyPG.h"

//����p�^�[���J�ڂ̊��N���X
class EnemyMoveTransition
{
public:
	int	timeCnt;	//���Ԍv��
	int	maxTime;	//���Ԑ���
	EnemyMoveTransition() : timeCnt(0), maxTime(0){}
	
	void SetTime(int mt);
	virtual bool Transition() = 0;
};

//-----------------------------------------------
//�J�ڂ��Ȃ�
class ETransition_Non : public EnemyMoveTransition
{
public:
	bool Transition();
};

//-----------------------------------------------
//���Ԍo��
class ETransition_Timer : public EnemyMoveTransition
{
public:
	bool Transition();
};