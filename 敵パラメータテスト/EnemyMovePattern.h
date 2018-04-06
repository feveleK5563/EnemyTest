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

	//����p�^�[����ݒ肷��(����͖ʓ|�Ȃ̂�3��ނ܂œK���ɐݒ�ł����I)
	void SetMovePattern(int moveA, int moveB, int moveC,	//����ԍ�
						int timeA, int timeB, int timeC);	//����̌p������

	//������s��
	void Move(int& timeCnt, ML::Vec2& pos);

	//���쏇�����Z�b�g����
	void MoveReset();

	//���̓���Ɉڍs������
	void MoveChange(int mTypeNum);
};