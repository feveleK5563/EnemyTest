#pragma once
#include "MyPG.h"

//����̊��N���X
class EnemyMove
{
public:
	virtual void Move(ML::Vec2& pos) = 0;
};

//-----------------------------------------------
//�������Ȃ�
class EMove_NoMotion : public EnemyMove
{
public:
	void Move(ML::Vec2& pos);
};

//-----------------------------------------------
//�E�ɕ���
class EMove_WalkRight : public EnemyMove
{
public:
	void Move(ML::Vec2& pos);
};

//-----------------------------------------------
//�W�����v
class EMove_Jump : public EnemyMove
{
public:
	void Move(ML::Vec2& pos);
};