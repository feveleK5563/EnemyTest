#pragma once
#include "MyPG.h"

//動作の基底クラス
class EnemyMove
{
public:
	virtual void Move() = 0;
};

//-----------------------------------------------
//何もしない
class EMove_NoMotion : public EnemyMove
{
public:
	void Move();
};

//-----------------------------------------------
//右に歩く
class EMove_WalkRight : public EnemyMove
{
public:
	void Move();
};

//-----------------------------------------------
//ジャンプ
class EMove_Jump : public EnemyMove
{
public:
	void Move();
};