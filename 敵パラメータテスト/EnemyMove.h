#pragma once
#include "MyPG.h"

//動作の基底クラス
class EnemyMove
{
public:
	virtual void Move(ML::Vec2& pos) = 0;
};

//-----------------------------------------------
//何もしない
class EMove_NoMotion : public EnemyMove
{
public:
	void Move(ML::Vec2& pos);
};

//-----------------------------------------------
//右に歩く
class EMove_WalkRight : public EnemyMove
{
public:
	void Move(ML::Vec2& pos);
};

//-----------------------------------------------
//ジャンプ
class EMove_Jump : public EnemyMove
{
public:
	void Move(ML::Vec2& pos);
};