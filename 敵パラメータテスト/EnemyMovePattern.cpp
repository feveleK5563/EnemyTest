#include "EnemyMovePattern.h"


//�R���X�g���N�^
EnemyMovePattern::EnemyMovePattern() :
	movePatternNum(0),
	nowMoveOrder(0)
{
	em = new EMove_NoMotion();
}

//�f�X�g���N�^
EnemyMovePattern::~EnemyMovePattern() { delete em; }

//-----------------------------------------------------------------------------
//����p�^�[����ݒ肷��(����͖ʓ|�Ȃ̂�3��ނ܂œK���ɐݒ�ł����I)
void EnemyMovePattern::SetMovePattern(int moveA, int moveB, int moveC,	//����ԍ�
									  int timeA, int timeB, int timeC)	//����̌p������
{
	for (int i = 0; i < 3; ++i)
	{
		mt.emplace_back();
		mt.back() = { moveA, timeA };
	}
	moveType[0] = moveA;
	moveType[1] = moveB;
	moveType[2] = moveC;

	moveTimeMax[0] = timeA;
	moveTimeMax[1] = timeB;
	moveTimeMax[2] = timeC;

	movePatternNum = (int)mt.size();

	MoveChange();
}

//-----------------------------------------------------------------------------
//������s��
void EnemyMovePattern::Move(int& timeCnt, ML::Vec2& pos)
{
	em->Move(pos);

	++timeCnt;
	//timeCnt��moveTimeMax�ȏ�ɂȂ�����A���̓���Ɉڍs����
	if (timeCnt >= moveTimeMax[nowMoveOrder])
	{
		timeCnt = 0;
		delete em;

		++nowMoveOrder;
		if (nowMoveOrder > movePatternNum)
			nowMoveOrder = 0;

		MoveChange();
	}
}

//-----------------------------------------------------------------------------
//���̓���Ɉڍs������
void EnemyMovePattern::MoveChange()
{
	switch (moveType[nowMoveOrder])
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