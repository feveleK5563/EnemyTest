#pragma once
#include "EnemyMove.h"

//�G����̊Ǘ��������I�I
class EnemyMoveManager
{
public:
	ML::Vec2* pos;		//�G�̍��W�̃A�h���X�l���i�[

	int movePatternNum;		//�s������̐�
	int nowMoveOrder;		//���݂̓��쏇
	int moveType[3];		//����̎��(�ꉞ���ߑł���3��ނ܂�)
	int moveTimeMax[3];		//����I���܂ł̎���(��������ꉞ3��ނ܂�)
	int timeCnt;			//���Ԃ��v��

	EnemyMove* em;			//����������ōs��

	//�R���X�g���N�^
	EnemyMoveManager(ML::Vec2* enemypos);

	//�f�X�g���N�^
	virtual ~EnemyMoveManager();

	//����p�^�[����ݒ肷��(����͖ʓ|�Ȃ̂�3��ނ܂œK���ɐݒ�ł����I)
	void SetMovePattern(int moveA, int moveB, int moveC,	//����ԍ�
						int timeA, int timeB, int timeC);	//����̌p������

	//������s��
	void Move();

	//�����̓���Ɉڍs������
	//�����̓e�X�g�p�Ȃ̂�int�^
	void MoveChange(int motionNum);
};