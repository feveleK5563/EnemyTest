#include "AnimationManager.h"

//コンストラクタ
AnimationManager::AnimationManager(string imgName) : 
	imageName(imgName),
	animCnt(0.f),
	nowAnimNum(0)
{
	//DG::Image_Create(imageName, "./data/image/Slime.png");
}

//デストラクタ
AnimationManager::~AnimationManager()
{
	for (auto it : charaChip)
		delete it;

	//DG::Image_Erase(imageName);
}

//-----------------------------------------------------------------------------
//キャラチップを作成
void AnimationManager::CreateCharaChip(
	int startPosX, int startPosY, int chipWidth, int chipHeight, int sheet, float spd)
{
	charaChip.emplace_back(new CharaChip());
	charaChip.back()->CreateChip(startPosX, startPosY, chipWidth, chipHeight, sheet, spd);
}

//-----------------------------------------------------------------------------
//アニメーションパターンの設定
void AnimationManager::SetAnimationPattern(int motionNum)
{
	animCnt = 0.f;
	nowAnimNum = motionNum;
}

//-----------------------------------------------------------------------------
//アニメーション
void AnimationManager::Animation()
{
	animCnt += charaChip[nowAnimNum]->animSpd;
}

//-----------------------------------------------------------------------------
//描画
void AnimationManager::ImageRender(ML::Vec2 pos)
{
	ML::Box2D src = *charaChip[nowAnimNum]->chip[int(animCnt) % charaChip[nowAnimNum]->chipSheetNum];
	ML::Box2D draw = src;
	draw.x = 0;
	draw.y = 0;
	draw.Offset(pos);
	DG::Image_Draw(imageName, draw, src);
}