#pragma once
#include "EnemyMoveSet.h"

//�G�̎�ޕʂɐݒ肳�ꂽ����A�h���X�����L���A
//���쏈�����Ăяo���N���X
class EnemyController
{
public:
	EnemyMoveSet* ems;		//����(delete�֎~)

	int skillId;			//���݂̓G����ǂݎ���X�L���ԍ�
	int nowMoveOrder;		//���݂̓��쏇��
	int nowPatternOrder;	//���݂̓���p�^�[������
	int timeCnt;			//���Ԍv��

	//�R���X�g���N�^
	EnemyController(EnemyMoveSet* cpyems);
	//�f�X�g���N�^
	~EnemyController();

	//����̎��s
	void Move(ML::Vec2& moveVec);
};