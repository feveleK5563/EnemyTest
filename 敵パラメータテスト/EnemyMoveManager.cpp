#include "EnemyMoveManager.h"

//�R���X�g���N�^
EnemyMoveManager::EnemyMoveManager() :
	timeCnt(0),
	nowPatternOrder(0) {}

//�f�X�g���N�^
EnemyMoveManager::~EnemyMoveManager()
{
	for (auto it : empattern)
		delete it;

	for (auto it : emtransition)
		delete it;
}

//-----------------------------------------------------------------------------
//����p�^�[���W���̐���
void EnemyMoveManager::CreateMotionPattern(int* moveNum,		//����ԍ�����ꂽ�z��̃A�h���X�l
										   int* durationTime,	//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
										   int  totalMoveNum,	//����̑���
										   int	transitionNum,	//����p�^�[���̑J�ڕ��@�̔ԍ�
										   int	transMaxTime)	//���ԑJ�ڑI�����̑J�ڎ���
{
	empattern.emplace_back(new EnemyMovePattern(moveNum, durationTime, totalMoveNum));
	SetTransition(transitionNum, transMaxTime);
}

//-----------------------------------------------------------------------------
//���݂̓���p�^�[�������s����
void EnemyMoveManager::Move(ML::Vec2& pos)
{
	empattern[nowPatternOrder]->Move(timeCnt, pos);

	//�p�^�[���̑J�ڏ����𖞂������瑦�p�^�[���ύX
	for (int i = 0; i < (int)emtransition.size(); ++i)
	{
		if (nowPatternOrder != i && 
			emtransition[i]->Transition())
		{
			PatternTransition(i);
			return;
		}
	}
}

//-----------------------------------------------------------------------------
//����p�^�[�����w��ԍ��ɑJ�ڂ�����
void EnemyMoveManager::PatternTransition(int patternNum)
{
	if (patternNum >= (int)empattern.size())
		return;

	empattern[nowPatternOrder]->MoveReset();
	nowPatternOrder = patternNum;
	timeCnt = 0;
}

//-----------------------------------------------------------------------------
//����p�^�[���̑J�ڕ��@��ݒ肷��
void EnemyMoveManager::SetTransition(int transitionNum, int transMaxTime)
{
	switch (transitionNum)
	{
	case 0:	//�J�ڂȂ�
		emtransition.emplace_back();
		emtransition.back() = new ETransition_Default();
		break;
	}
}