#pragma once
#include "EnemyMove.h"
#include "EnemyMoveTransition.h"

//�G����̃p�^�[�����쐬�����I
class EnemyMovePattern
{
public:

	struct MovePattern		//����̎�ށA���Ԃ��������
	{
		EnemyMove*	em;		//����������ōs��
		int skillId;		//���쒆�Ɏ擾�\�ȃX�L���ԍ�
		int moveTimeMax;	//����I���܂ł̎���
		//�U���p�R���W�����̃T�C�Y
		//�U�����̃_���[�W

		MovePattern(int sklid, int mtime) :
			em(nullptr),
			skillId(sklid),
			moveTimeMax(mtime){}
	};
	vector<MovePattern*> mp;
	EnemyMoveTransition* emt;
	//�p�^�[�����s���̃A�j���[�V����
	ML::Box2D	src;
	int			sheetNum;
	float		animSpd;
	bool		isRoop;

	//�R���X�g���N�^
	//���͉��̎p
	EnemyMovePattern(	int* moveNum,			//����ԍ�����ꂽ�z��̃A�h���X�l
						int* skillId,			//���쒆�Ɏ擾�\�ȃX�L���ԍ�
						int* durationTime,		//����̌p�����Ԃ���ꂽ�z��̃A�h���X�l
						int  totalMoveNum,		//����̑���
						int  transitionNum);	//����p�^�[���J�ڏ����̔ԍ�

	//�f�X�g���N�^
	~EnemyMovePattern();

	//������s��
	//���݂̓��쏇�A���Ԍv���A���W
	void Move(int& nowMoveOrder, int& timeCnt, ML::Vec2& moveVec);

	//���쏇�����Z�b�g����
	void MoveReset(int& nowMoveOrder);

	//�����ݒ肷��
	void SetMoveAndTime(int moveNum, int skillId, int durationTime);

	//����p�^�[���J�ڏ�����ݒ肷��
	void SetTransition(int transitionNum);
};