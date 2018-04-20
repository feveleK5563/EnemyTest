#include "EnemyMoveSet.h"

//�R���X�g���N�^
EnemyMoveSet::EnemyMoveSet() {}

//�f�X�g���N�^
EnemyMoveSet::~EnemyMoveSet()
{
	for (auto it : empattern)
		delete it;
}

//-----------------------------------------------------------------------------
//����p�^�[���W���̐���
void EnemyMoveSet::CreateMotionPattern(	int* moveNum,			//����ԍ�����ꂽ�z��̃A�h���X�l
										int* skillId,			//���쒆�Ɏ擾�\�ȃX�L���ԍ�
										int* durationTime,		//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
										int  totalMoveNum,		//����̑���
										int  transitionNum,		//����p�^�[���̑J�ڏ����̔ԍ�
										ML::Box2D&	src,		//�A�j���[�V�����摜�̍ŏ��̈ʒu
										int			sheet,		//�A�j���[�V��������
										float		spd,		//�A�j���[�V�������x
										bool		ir)			//���[�v���邩�ۂ�
{
	empattern.emplace_back(new EnemyMovePattern(moveNum, skillId, durationTime, totalMoveNum, transitionNum));
	animChip.emplace_back(new AnimationCharaChip(src, sheet, spd, ir));
}

//-----------------------------------------------------------------------------
//���݂̓���p�^�[�������s����
void EnemyMoveSet::Move(int& nowMoveOrder, int& nowPatternOrder, int& timeCnt, ML::Vec2& moveVec)
{
	empattern[nowPatternOrder]->Move(nowMoveOrder, timeCnt, moveVec);

	//�p�^�[���̑J�ڏ����𖞂������瑦�p�^�[���ύX
	for (int i = 0; i < (int)empattern.size(); ++i)
	{
		if (nowPatternOrder != i && 
			empattern[i]->emt->Transition())
		{
			PatternTransition(nowMoveOrder, nowPatternOrder, timeCnt, i);
			return;
		}
	}
}

//-----------------------------------------------------------------------------
//����p�^�[�����w��ԍ��ɑJ�ڂ�����
void EnemyMoveSet::PatternTransition(int& nowMoveOrder, int& nowPatternOrder, int& timeCnt, int patternNum)
{
	if (patternNum >= (int)empattern.size())
		return;

	empattern[nowPatternOrder]->MoveReset(nowMoveOrder);
	nowPatternOrder = patternNum;
	timeCnt = 0;
}