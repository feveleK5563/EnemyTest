#include "EnemyMoveTransition.h"

//-----------------------------------------------
//ŽžŠÔ§ŒÀ‚ÌÝ’è
void EnemyMoveTransition::SetTime(int mt)
{
	maxTime = mt;
}

//-----------------------------------------------
//‘JˆÚ‚È‚µ
bool ETransition_Non::Transition()
{
	return false;
}

//-----------------------------------------------
//ŽžŠÔŒo‰ß
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