#include "EnemyMoveTransition.h"

//-----------------------------------------------
//時間制限の設定
void EnemyMoveTransition::SetTime(int mt)
{
	maxTime = mt;
}

//-----------------------------------------------
//遷移なし
bool ETransition_Non::Transition()
{
	return false;
}

//-----------------------------------------------
//時間経過
bool ETransition_Timer::Transition()
{
	++timeCnt;
	if (timeCnt >= maxTime)
	{
		timeCnt = 0;
		return true;
	}

	return false;
}