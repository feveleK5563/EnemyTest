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
}

//-----------------------------------------------------------------------------
//����p�^�[���W���̐���
void EnemyMoveManager::CreateMotionPattern(int* moveNum,		//����ԍ�����ꂽ�z��̃A�h���X�l
										   int* durationTime,	//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
										   int  totalMoveNum)	//����̑���
{
	empattern.emplace_back(new EnemyMovePattern());
	empattern.back()->SetMovePattern(moveNum, durationTime, totalMoveNum);
}

//-----------------------------------------------------------------------------
//���݂̓���p�^�[�������s����
void EnemyMoveManager::Move(ML::Vec2& pos, const DI::VGamePad& gp)
{
	empattern[nowPatternOrder]->Move(timeCnt, pos);

	if (gp.B1.down)
	{
		PatternTransition(1);
	}
	else if (gp.B1.up)
	{
		PatternTransition(0);
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