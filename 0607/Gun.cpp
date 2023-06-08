#include "Gun.h"

Gun::Gun() : bullet(10)
{

}

Gun::Gun(int bnum) : bullet(bnum)
{
}

void Gun::Shot()
{
	cout << "BBANG!" << endl;
	bullet--;
}

int Gun::GetBullet()
{
	return bullet;
}
