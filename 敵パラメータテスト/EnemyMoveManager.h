#pragma once
#include "EnemyMovePattern.h"

class EnemyMoveManager
{
public:
	int timeCnt;		//時間計測
	vector<EnemyMovePattern> empattern;	//動作パターン

	//動作パターン集合の生成
	void CreateMotionPattern(int moveA, int moveB, int moveC,
							 int timeA, int timeB, int timeC);
};