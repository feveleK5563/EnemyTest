#pragma once
#include "AnimationCharaChip.h"

class ImageManager
{
private:
	bool	isDelete;

public:
	string						imageName;
	vector<AnimationCharaChip*>	charaChip;
	int							nowAnimNum;
	float						animCnt;

	//�R���X�g���N�^
	ImageManager(string imgName);
	ImageManager(string imgName, vector<AnimationCharaChip*> acc);

	//�f�X�g���N�^
	~ImageManager();

	//----------------------------------------------
	//�L�����`�b�v�̍쐬
	void CreateCharaChip(const ML::Box2D& src, int sheet, float spd, bool isroop);

	//----------------------------------------------
	//�A�j���[�V�����p�^�[���̕ύX
	void ChangeAnimationPattern(int motionNum);

	//----------------------------------------------
	//�A�j���[�V����
	void Animation();

	//----------------------------------------------
	//�`��
	void ImageRender(const ML::Vec2& pos);
};