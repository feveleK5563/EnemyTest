#pragma once
#include "MyPG.h"

//����̊��N���X
class EnemyMove
{
public:
	virtual void Move(ML::Vec2& moveVec) = 0;
};

//-----------------------------------------------
//�������Ȃ�
class EMove_NoMotion : public EnemyMove
{
public:
	void Move(ML::Vec2& moveVec);
};

//-----------------------------------------------
//�E�Ɉړ�����
class EMove_WalkRight : public EnemyMove
{
public:
	void Move(ML::Vec2& moveVec);
};

//-----------------------------------------------
//��Ɉړ�����
class EMove_Up : public EnemyMove
{
public:
	void Move(ML::Vec2& moveVec);
};

//-----------------------------------------------
//���Ɉړ�����
class EMove_Down : public EnemyMove
{
public:
	void Move(ML::Vec2& moveVec);
};