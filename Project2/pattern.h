#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;


enum Items
{
	TSHIRT = 1,
	PANTS,
	JACKET,
	PHONE,
	LAPTOP,
	TVSET
};

class Prototype
{
public:
	Prototype() {};
	virtual Prototype* clone() const { return 0; };
};


class Clothes
{
public:
	virtual void creating() const {};
	virtual ~Clothes() {};
};

class TShirt : public Clothes, public Prototype
{
public:
	void creating() const override
	{
		cout << "T-Shirt has been created." << endl;
	}
	Prototype* clone() const override
	{
		cout << "Cloned T-Shirt" << endl;
		return new TShirt();
	}
};

class Pants : public Clothes, public Prototype
{
public:
	void creating() const override
	{
		cout << "Pants has been created." << endl;
	}
	Prototype* clone() const override
	{
		cout << "Cloned Pants" << endl;
		return new Pants();
	}
};

class Jacket : public Clothes, public Prototype
{
public:
	void creating() const override
	{
		cout << "Jacket has been created." << endl;
	}
	Prototype* clone() const override
	{
		cout << "Cloned Jacket" << endl;
		return new Jacket();
	}
};


class Electronic
{
public:
	virtual void creating() const {};
	virtual ~Electronic() {};
};

class Phone : public Electronic, public Prototype
{
public:
	void creating() const override
	{
		cout << "Phone has been created." << endl;
	}
	Prototype* clone() const override
	{
		cout << "Cloned Phone" << endl;
		return new Phone();
	}
};

class Laptop : public Electronic, public Prototype
{
public:
	void creating() const override
	{
		cout << "Laptop has been created." << endl;
	}
	Prototype* clone() const override
	{
		cout << "Cloned Laptop" << endl;
		return new Laptop();
	}
};

class TV : public Electronic, public Prototype
{
public:
	void creating() const override
	{
		cout << "TV has been created." << endl;
	}
	Prototype* clone() const override
	{
		cout << "Cloned TV" << endl;
		return new TV();
	}
};

class FactoryOfGoods
{
public:
	virtual Clothes* createClothesItem() const { return 0; };
	virtual Electronic* createElectronicItem() const { return 0; };
};

class ClothesFactory : public FactoryOfGoods
{
public:

	Clothes* createClothesItem() const override
	{
		cout << "1 - T-Shirt | 2 - Pants | 3 - Jacket" << endl;
		int ch;
		cin >> ch;
		if (ch < 1 || ch > 3)
		{
			cout << "ERROR" << endl;
		}
		else
		{
			return createClothes(static_cast<Items>(ch));
		}
	}
private:
	Clothes* createClothes(Items item) const
	{
		switch (item)
		{
		case TSHIRT:
			return new TShirt();
			break;
		case PANTS:
			return new Pants();
			break;
		case JACKET:
			return new Jacket();
			break;
		default:
			break;
		}
	}
};

class ElectronicFactory : public FactoryOfGoods
{
public:
	Electronic* createElectronicItem() const override
	{
		cout << "4 - Phone | 5 - Laptop | 6 - TV" << endl;
		int ch;
		cin >> ch;
		if (ch <= 3 || ch > 6)
		{
			cout << "ERROR" << endl;
		}
		else
		{
			return createElectronic(static_cast<Items>(ch));
		}

	}
private:
	Electronic* createElectronic(Items item) const
	{
		switch (item)
		{
		case PHONE:
			return new Phone();
			break;
		case LAPTOP:
			return new Laptop();
			break;
		case TVSET:
			return new TV();
			break;
		default:
			break;
		}
	}
};

class PrototypeFactory
{
public:
	PrototypeFactory()
	{
		prototypes[Items::TSHIRT] = new TShirt();
		prototypes[Items::PANTS] = new Pants();
		prototypes[Items::JACKET] = new Jacket();
		prototypes[Items::PHONE] = new Phone();
		prototypes[Items::LAPTOP] = new Laptop();
		prototypes[Items::TVSET] = new TV();

	};
	static PrototypeFactory& getInstance()
	{
		static PrototypeFactory instance;
		return instance;
	}
	Prototype* createClone(Items items)
	{
		return prototypes[items]->clone();
	}
	~PrototypeFactory()
	{
		prototypes.clear();
	}
private:
	unordered_map<Items, Prototype*, hash<int>> prototypes;
};