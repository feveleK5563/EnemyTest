#include "ImageManager.h"

//�R���X�g���N�^
ImageManager::ImageManager(string imgName) : 
	imageName(imgName),
	animCnt(0.f),
	nowAnimNum(0),
	isDelete(true)
{
	DG::Image_Create(imageName, "data/image/" + imageName + ".png");
}

ImageManager::ImageManager(string imgName, vector<AnimationCharaChip*> acc) :
	imageName(imgName),
	animCnt(0.f),
	nowAnimNum(0),
	charaChip(acc),
	isDelete(false) {}

//�f�X�g���N�^
ImageManager::~ImageManager()
{
	if (isDelete == false)
		return;

	for (auto it : charaChip)
		delete it;

	DG::Image_Erase(imageName);
}

//-----------------------------------------------------------------------------
//�L�����`�b�v���쐬
void ImageManager::CreateCharaChip(const ML::Box2D& src, int sheet, float spd, bool isroop)
{
	if (isDelete == false)
		return;

	charaChip.emplace_back(new AnimationCharaChip(src, sheet, spd, isroop));
}

//-----------------------------------------------------------------------------
//�A�j���[�V�����p�^�[���̕ύX
void ImageManager::ChangeAnimationPattern(int motionNum)
{
	animCnt = 0.f;
	nowAnimNum = motionNum;
}

//-----------------------------------------------------------------------------
//�A�j���[�V����
void ImageManager::Animation()
{
	animCnt += 1.f / charaChip[nowAnimNum]->animSpd;

	//���[�v���Ȃ��ꍇ�͍Ō�̓���Œ�~
	if (charaChip[nowAnimNum]->isAnimRoop == false &&
		(int)animCnt >= charaChip[nowAnimNum]->chipSheetNum)
	{
		animCnt = (float)charaChip[nowAnimNum]->chipSheetNum;
	}
}

//-----------------------------------------------------------------------------
//�`��
void ImageManager::ImageRender(const ML::Vec2& pos)
{
	ML::Box2D src = charaChip[nowAnimNum]->chip;
	src.x += src.w * (int(animCnt) % charaChip[nowAnimNum]->chipSheetNum);
	ML::Box2D draw = src;
	draw.x = 0;
	draw.y = 0;
	draw.Offset(pos);
	DG::Image_Draw(imageName, draw, src);
}