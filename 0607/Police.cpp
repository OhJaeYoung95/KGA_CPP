#include "Police.h"

Police::Police(int bnum, int bcuff) : handcuffs(bcuff)
{
	if (bnum > 0)
		pistol = new Gun(bnum);
	else
		pistol = nullptr;
}

Police::Police(Police& ref) : handcuffs(ref.handcuffs)
{
	if(pistol != nullptr)
		delete pistol;
	pistol = new Gun(ref.pistol->GetBullet());

}

void Police::PutHandcuff()
{
	cout << "SNAP!" << endl;
	handcuffs--;
}

void Police::Shot()
{
	if (pistol == nullptr)
		cout << "Hut BBANG!" << endl;
	else
		pistol->Shot();
}

Police::~Police()
{
	if (pistol != nullptr)
		delete pistol;
}

Police& Police::operator=(const Police& ref)
{
	if (pistol != nullptr)
		delete pistol;

	pistol = new Gun(ref.pistol->GetBullet());
	handcuffs = ref.handcuffs;
	return *this;
}
