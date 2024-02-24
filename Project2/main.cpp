#include "pattern.h"

int main()
{
	FactoryOfWeapon* sword = new FactoryOfSword();
	sword->createWeapon();
	cout << endl;

	cout << "CLONE" << endl;
	PrototypeFactory prototype;
	PrototypeFactory& factory = PrototypeFactory::getInstance();
	cout << typeid(factory).hash_code() << endl;
	Prototype* clone_sword = prototype.createClone(Weapon_for_clone::SWORD);
	Prototype* clone_bow = prototype.createClone(Weapon_for_clone::BOW);
	PrototypeFactory& fac = PrototypeFactory::getInstance();
	cout << typeid(fac).hash_code() << endl;
}