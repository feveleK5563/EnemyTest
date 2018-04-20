#pragma once
#include "EnemyMovePattern.h"
#include "AnimationCharaChip.h"

//EnemyMovePattern���܂Ƃ߂����
class EnemyMoveSet
{
public:
	vector<EnemyMovePattern*>		empattern;		//����p�^�[��
	vector<AnimationCharaChip*>		animChip;		//�A�j���[�V�����p�^�[��

	EnemyMoveSet();
	~EnemyMoveSet();

	//����p�^�[���W���̐���
	void CreateMotionPattern(	int* moveNum,			//����ԍ�����ꂽ�z��̃A�h���X�l
								int* skillId,			//���쒆�Ɏ擾�\�ȃX�L���ԍ�
								int* durationTime,		//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
								int  totalMoveNum,		//����̑���
								int  transitionNum,		//����p�^�[���̑J�ڏ����̔ԍ�
								ML::Box2D&	src,		//�A�j���[�V�����摜�̍ŏ��̈ʒu
								int			sheet,		//�A�j���[�V��������
								float		spd,		//�A�j���[�V�������x
								bool		ir);		//���[�v���邩�ۂ�

	//���݂̓���p�^�[�������s����
	void Move(int& nowMoveOrder, int& nowPatternOrder, int& timeCnt, ML::Vec2& moveVec);

	//����p�^�[�����w��ԍ��ɑJ�ڂ�����
	void PatternTransition(int& nowMoveOrder, int& nowPatternOrder, int& timeCnt, int patternNum);
};