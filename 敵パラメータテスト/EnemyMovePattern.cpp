#include "EnemyMovePattern.h"


//�R���X�g���N�^
EnemyMovePattern::EnemyMovePattern(
	int* moveNum,			//����ԍ�����ꂽ�z��̃A�h���X�l
	int* durationTime,		//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
	int  totalMoveNum) :	//����̑���
	nowMoveOrder(0)
{
	for (int i = 0; i < totalMoveNum; ++i)
	{
		mt.emplace_back(new MoveType(*(moveNum + i), *(durationTime + i)));
	}

	MoveChange(mt[0]->moveTypeNum);
}

//�f�X�g���N�^
EnemyMovePattern::~EnemyMovePattern()
{ 
	for (auto it : mt)
		delete it;

	delete em;
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