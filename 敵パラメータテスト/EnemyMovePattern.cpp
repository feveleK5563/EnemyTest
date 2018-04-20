#include "EnemyMovePattern.h"

//�R���X�g���N�^
EnemyMovePattern::EnemyMovePattern(
	int* moveNum,			//����ԍ�����ꂽ�z��̃A�h���X�l
	int* skillId,			//���쒆�Ɏ擾�\�ȃX�L���ԍ�
	int* durationTime,		//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
	int  totalMoveNum,		//����̑���
	int  transitionNum)		//����p�^�[���J�ڏ����̔ԍ�
{
	for (int i = 0; i < totalMoveNum; ++i)
	{
		SetMoveAndTime(*(moveNum + i), *(skillId + i), *(durationTime + i));
	}
	SetTransition(transitionNum);
}

//�f�X�g���N�^
EnemyMovePattern::~EnemyMovePattern()
{ 
	for (auto it : mp)
	{
		delete it->em;
		delete it;
	}

	delete emt;
}

//-----------------------------------------------------------------------------
//������s��
void EnemyMovePattern::Move(int& nowMoveOrder, int& timeCnt, ML::Vec2& moveVec)
{
	mp[nowMoveOrder]->em->Move(moveVec);

	++timeCnt;
	//timeCnt��moveTimeMax�𒴂�����A���̓���Ɉڍs����
	if (timeCnt >= mp[nowMoveOrder]->moveTimeMax)
	{
		timeCnt = 0;

		++nowMoveOrder;
		if (nowMoveOrder >= (int)mp.size())
			nowMoveOrder = 0;
	}
}

//-----------------------------------------------------------------------------
//���쏇�����Z�b�g����
void EnemyMovePattern::MoveReset(int& nowMoveOrder)
{
	nowMoveOrder = 0;
}

//-----------------------------------------------------------------------------
//�����ݒ肷��
void EnemyMovePattern::SetMoveAndTime(int moveNum, int skillId, int durationTime)
{
	mp.emplace_back(new MovePattern(skillId, durationTime));
	switch (moveNum)
	{
	case 0:		//�������Ȃ�
		mp.back()->em = new EMove_NoMotion();
		break;

	case 1:		//�E�����ɕ���
		mp.back()->em = new EMove_WalkRight();
		break;

	case 2:		//��Ɉړ�����
		mp.back()->em = new EMove_Up();
		break;

	case 3:		//���Ɉړ�����
		mp.back()->em = new EMove_Down();
		break;
	}
}

//-----------------------------------------------------------------------------
//����p�^�[���J�ڏ�����ݒ肷��
void EnemyMovePattern::SetTransition(int transitionNum)
{
	switch (transitionNum)
	{
	case 0:	//�J�ڂȂ�
		emt = new ETransition_Default();
		break;
	}
}