#pragma once
#include "EnemyMove.h"

//�G����̃p�^�[�����쐬�����I
class EnemyMovePattern
{
public:
	int nowMoveOrder;		//���݂̓��쏇

	struct MoveType		//����̎�ށA���Ԃ��������
	{
		int moveTypeNum;	//����̎��(�ԍ�)
		int moveTimeMax;	//����I���܂ł̎���

		MoveType(int mtype, int mtime) :
			moveTypeNum(mtype),
			moveTimeMax(mtime){}
	};
	vector<MoveType*> mt;

	EnemyMove* em;			//����������ōs��


	//�R���X�g���N�^
	EnemyMovePattern();

	//�f�X�g���N�^
	~EnemyMovePattern();

	//����p�^�[����ݒ肷��
	void SetMovePattern(int* moveNum,		//����ԍ�����ꂽ�z��̃A�h���X�l
						int* durationTime,	//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
						int  totalMoveNum);	//����̑���

	//������s��
	void Move(int& timeCnt, ML::Vec2& pos);

	//���쏇�����Z�b�g����
	void MoveReset();

	//���̓���Ɉڍs������
	void MoveChange(int mTypeNum);
};