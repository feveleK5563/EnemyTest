#include "EnemyMovePattern.h"


//�R���X�g���N�^
EnemyMovePattern::EnemyMovePattern() :
	movePatternNum(0),
	nowMoveOrder(0)
{
	timeCnt = 0;
	em = new EMove_NoMotion();
}

//�f�X�g���N�^
EnemyMovePattern::~EnemyMovePattern() { delete em; }

//-----------------------------------------------------------------------------
//����p�^�[����ݒ肷��(����͖ʓ|�Ȃ̂�3��ނ܂œK���ɐݒ�ł����I)
void EnemyMovePattern::SetMovePattern(int moveA, int moveB, int moveC,	//����ԍ�
									  int timeA, int timeB, int timeC)	//����̌p������
{
	mt.emplace_back();
	mt.back() = { moveA, timeA };

	mt.emplace_back();
	mt.back() = { moveB, timeB };

	mt.emplace_back();
	mt.back() = { moveC, timeC };

	movePatternNum = (int)mt.size();

	MoveChange(mt[0].moveTypeNum);
}

//-----------------------------------------------------------------------------
//������s��
void EnemyMovePattern::Move(/*int& timeCnt, */ML::Vec2& pos)
{
	em->Move(pos);

	++timeCnt;
	//timeCnt��moveTimeMax�ȏ�ɂȂ�����A���̓���Ɉڍs����
	if (timeCnt >= mt[nowMoveOrder].moveTimeMax)
	{
		timeCnt = 0;
		delete em;

		++nowMoveOrder;
		if (nowMoveOrder >= movePatternNum)
			nowMoveOrder = 0;

		MoveChange(mt[nowMoveOrder].moveTypeNum);
	}
}

//-----------------------------------------------------------------------------
//���̓���Ɉڍs������
void EnemyMovePattern::MoveChange(int mTypeNum)
{
	switch (mTypeNum)
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