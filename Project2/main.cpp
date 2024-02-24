#include "pattern.h"

int main()
{
	ClothesFactory* cloth1 = new ClothesFactory();
	Clothes* product1 = cloth1->createClothesItem();
	product1->creating();
	cout << endl;

	ElectronicFactory* el1 = new ElectronicFactory();
	Electronic* product2 = el1->createElectronicItem();
	product2->creating();
	cout << endl;

	cout << "CLONE" << endl;
	PrototypeFactory prot_fact;
	Prototype* clone = prot_fact.createClone(Items::JACKET);
}