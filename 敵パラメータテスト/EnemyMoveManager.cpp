#include "EnemyMoveManager.h"

//�R���X�g���N�^
EnemyMoveManager::EnemyMoveManager(ML::Vec2* enemypos) :
	pos(enemypos),
	movePatternNum(0),
	nowMoveOrder(0),
	timeCnt(0)
{
	for (int i = 0; i < 3; ++i)
	{
		moveType[i] = 0;
		moveTimeMax[i] = 0;
	}
	em = new EMove_NoMotion();
}

//�f�X�g���N�^
EnemyMoveManager::~EnemyMoveManager() { delete em; }

//-----------------------------------------------------------------------------
//����p�^�[����ݒ肷��(����͖ʓ|�Ȃ̂�3��ނ܂œK���ɐݒ�ł����I)
void EnemyMoveManager::SetMovePattern(int moveA, int moveB, int moveC,	//����ԍ�
									  int timeA, int timeB, int timeC)	//����̌p������
{
	moveType[0] = moveA;
	moveType[1] = moveB;
	moveType[2] = moveC;

	moveTimeMax[0] = timeA;
	moveTimeMax[1] = timeB;
	moveTimeMax[2] = timeC;

	movePatternNum = 3;

	MoveChange(moveType[nowMoveOrder]);
}

//-----------------------------------------------------------------------------
//������s��
void EnemyMoveManager::Move()
{
	em->Move(*pos);

	++timeCnt;

	if (timeCnt >= moveTimeMax[nowMoveOrder])
	{
		timeCnt = 0;
		delete em;

		++nowMoveOrder;
		if (nowMoveOrder > movePatternNum)
		{
			nowMoveOrder = 0;
		}

		MoveChange(moveType[nowMoveOrder]);
	}
}

//-----------------------------------------------------------------------------
//�����̓���Ɉڍs������
//�����̓e�X�g�p�Ȃ̂�int�^
void EnemyMoveManager::MoveChange(int motionNum)
{
	switch (motionNum)
	{
	case 0:		//�������Ȃ�
		em = new EMove_NoMotion();
		break;

	case 1:		//�E�����ɕ���
		em = new EMove_WalkRight();
		break;

	case 2:		//��Ɉړ�����
		em = new EMove_Up();
		break;

	case 3:		//���Ɉړ�����
		em = new EMove_Down();
		break;
	}
}