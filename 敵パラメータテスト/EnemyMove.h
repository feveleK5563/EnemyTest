#pragma once
#include "MyPG.h"

//動作の基底クラス
class EnemyMove
{
public:
	virtual void Move(ML::Vec2& moveVec) = 0;
};

//-----------------------------------------------
//何もしない
class EMove_NoMotion : public EnemyMove
{
public:
	void Move(ML::Vec2& moveVec);
};

//-----------------------------------------------
//右に移動する
class EMove_WalkRight : public EnemyMove
{
public:
	void Move(ML::Vec2& moveVec);
};

//-----------------------------------------------
//上に移動する
class EMove_Up : public EnemyMove
{
public:
	void Move(ML::Vec2& moveVec);
};

//-----------------------------------------------
//下に移動する
class EMove_Down : public EnemyMove
{
public:
	void Move(ML::Vec2& moveVec);
};