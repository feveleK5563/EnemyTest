#include "conio.h"
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
void EnemyMoveManager::CreateMotionPattern(int moveA, int moveB, int moveC,	//����ԍ�
										   int timeA, int timeB, int timeC) //����̌p������
{
	empattern.emplace_back(new EnemyMovePattern());
	empattern.back()->SetMovePattern(moveA, moveB, moveC, timeA, timeB, timeC);
}

//-----------------------------------------------------------------------------
//���݂̓���p�^�[�����s��
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