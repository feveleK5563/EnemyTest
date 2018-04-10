#pragma once
#include "MyPG.h"

//動作パターン遷移の基底クラス
class EnemyMoveTransition
{
public:
	int	timeCnt;	//時間計測
	int	maxTime;	//時間制限
	EnemyMoveTransition() : timeCnt(0), maxTime(0){}
	
	void SetTime(int mt);
	virtual bool Transition() = 0;
};

//-----------------------------------------------
//遷移しない
class ETransition_Non : public EnemyMoveTransition
{
public:
	bool Transition();
};

//-----------------------------------------------
//時間経過
class ETransition_Timer : public EnemyMoveTransition
{
public:
	bool Transition();
};