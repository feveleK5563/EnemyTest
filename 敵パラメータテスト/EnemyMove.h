#pragma once
#include "MyPG.h"

//����̊��N���X
class EnemyMove
{
public:
	virtual void Move() = 0;
};

//-----------------------------------------------
//�������Ȃ�
class EMove_NoMotion : public EnemyMove
{
public:
	void Move();
};

//-----------------------------------------------
//�E�ɕ���
class EMove_WalkRight : public EnemyMove
{
public:
	void Move();
};

//-----------------------------------------------
//�W�����v
class EMove_Jump : public EnemyMove
{
public:
	void Move();
};