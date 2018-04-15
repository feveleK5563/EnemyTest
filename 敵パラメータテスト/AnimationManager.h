#pragma once
#include "CharaChip.h"

class AnimationManager
{
public:
	string				imageName;
	vector<CharaChip*>	charaChip;
	int					nowAnimNum;
	float				animCnt;

	//�R���X�g���N�^
	AnimationManager(string imgName);

	//�f�X�g���N�^
	~AnimationManager();

	//----------------------------------------------
	//�L�����`�b�v�̍쐬
	void CreateCharaChip(int startPosX, int startPosY, int chipWidth, int chipHeight, int sheet, float spd);

	//----------------------------------------------
	//�A�j���[�V�����p�^�[���̐ݒ�
	void SetAnimationPattern(int motionNum);

	//----------------------------------------------
	//�A�j���[�V����
	void Animation();

	//----------------------------------------------
	//�`��
	void ImageRender(ML::Vec2 pos);
};