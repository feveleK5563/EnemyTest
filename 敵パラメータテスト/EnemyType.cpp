#include "EnemyType.h"

EnemyType::EnemyType(string imgName, int ml, int hd) :
	imageName(imgName),
	maxLife(ml),
	hitDamage(hd),
	emSet(new EnemyMoveSet())
{
	DG::Image_Create(imageName, "data/image/" + imgName + ".png");
}

EnemyType::~EnemyType()
{
	DG::Image_Erase(imageName);
	delete emSet;
}
