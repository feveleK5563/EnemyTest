#pragma once
#include "EnemyMovePattern.h"

class EnemyMoveManager
{
public:
	int timeCnt;		//���Ԍv��
	vector<EnemyMovePattern> empattern;	//����p�^�[��

	//����p�^�[���W���̐���
	void CreateMotionPattern(int moveA, int moveB, int moveC,
							 int timeA, int timeB, int timeC);
};