#include "EnemyMoveManager.h"


//�R���X�g���N�^
EnemyMoveManager::EnemyMoveManager() :
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

	MoveChange();
}

//-----------------------------------------------------------------------------
//������s��
void EnemyMoveManager::Move()
{
	em->Move();

	//timeCnt��moveTimeMax�ȏ�ɂȂ�����A���̓���Ɉڍs����
	if (++timeCnt >= moveTimeMax[nowMoveOrder])
	{
		timeCnt = 0;
		delete em;
		nowMoveOrder = ++nowMoveOrder % movePatternNum;

		MoveChange();
	}
}

//-----------------------------------------------------------------------------
//���̓���Ɉڍs������
void EnemyMoveManager::MoveChange()
{
	switch (moveType[nowMoveOrder])
	{
	case 0:		//�������Ȃ�
		em = new EMove_NoMotion();
		break;

	case 1:		//�E�����ɕ���
		em = new EMove_WalkRight();
		break;

	case 2:		//�W�����v����
		em = new EMove_Jump();
		break;
	}
}