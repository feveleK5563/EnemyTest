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
//�E�Ɉړ�����
class EMove_WalkRight : public EnemyMove
{
public:
	void Move(ML::Vec2& pos);
};

//-----------------------------------------------
//��Ɉړ�����
class EMove_Up : public EnemyMove
{
public:
	void Move(ML::Vec2& pos);
};

//-----------------------------------------------
//���Ɉړ�����
class EMove_Down : public EnemyMove
{
public:
	void Move(ML::Vec2& pos);
};