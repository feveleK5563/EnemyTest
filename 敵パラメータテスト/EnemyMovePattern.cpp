#include "EnemyMovePattern.h"


//�R���X�g���N�^
EnemyMovePattern::EnemyMovePattern() :
	nowMoveOrder(0)
{
	em = new EMove_NoMotion();
}

//�f�X�g���N�^
EnemyMovePattern::~EnemyMovePattern()
{ 
	for (auto it : mt)
		delete it;

	delete em;
}

//-----------------------------------------------------------------------------
//����p�^�[����ݒ肷��(����͖ʓ|�Ȃ̂�3��ނ܂œK���ɐݒ�ł����I)
void EnemyMovePattern::SetMovePattern(int moveA, int moveB, int moveC,	//����ԍ�
									  int timeA, int timeB, int timeC)	//����̌p������
{
	mt.emplace_back(new MoveType(moveA, timeA));

	mt.emplace_back(new MoveType(moveB, timeB));

	mt.emplace_back(new MoveType(moveC, timeC));

	MoveChange(mt[0]->moveTypeNum);
}

//-----------------------------------------------------------------------------
//������s��
void EnemyMovePattern::Move(int& timeCnt, ML::Vec2& pos)
{
	em->Move(pos);

	++timeCnt;
	//timeCnt��moveTimeMax�𒴂�����A���̓���Ɉڍs����
	if (timeCnt >= mt[nowMoveOrder]->moveTimeMax)
	{
		timeCnt = 0;
		delete em;

		++nowMoveOrder;
		if (nowMoveOrder >= (int)mt.size())
			nowMoveOrder = 0;

		MoveChange(mt[nowMoveOrder]->moveTypeNum);
	}
}

//-----------------------------------------------------------------------------
//���쏇�����Z�b�g����
void EnemyMovePattern::MoveReset()
{
	nowMoveOrder = 0;
	MoveChange(mt[nowMoveOrder]->moveTypeNum);
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