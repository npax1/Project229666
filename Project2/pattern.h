#include <iostream>
#include <unordered_map>

using namespace std;


enum Weapon_for_clone
{
	SWORD = 0,
	BOW,
	DAGGER
};

class Prototype
{
public:
	Prototype() {};
	virtual Prototype* clone() const { return 0; };
};

class Weapon
{
public:
	virtual int fireRange() const = 0;
	virtual string damageType() const = 0;
	virtual int criticalDamageBonus() const = 0;
	virtual ~Weapon() {};


};

class Sword : public Weapon, public Prototype
{
public:
	Sword(int fire_range = 1, string damage_type = "Multi", int critical_damage_bonus = 5) : fire_range(fire_range), damage_type(damage_type), critical_damage_bonus(critical_damage_bonus) {};

	int fireRange() const override
	{
		return this->fire_range;
	}
	string damageType() const override
	{
		return this->damage_type;
	}
	int criticalDamageBonus() const override
	{
		return this->critical_damage_bonus;
	}
	Prototype* clone() const override
	{
		cout << "NEW SWORD" << endl;
		return new Sword(this->fire_range, this->damage_type, this->critical_damage_bonus);
	}

private:
	int fire_range;
	string damage_type;
	int critical_damage_bonus;
};

class Bow : public Weapon, public Prototype
{
public:
	Bow(int fire_range = 10, string damage_type = "Single", int critical_damage_bonus = 3) : fire_range(fire_range), damage_type(damage_type), critical_damage_bonus(critical_damage_bonus) {};

	int fireRange() const override
	{
		return this->fire_range;
	}
	string damageType() const override
	{
		return this->damage_type;
	}
	int criticalDamageBonus() const override
	{
		return this->critical_damage_bonus;
	}
	Prototype* clone() const override
	{
		cout << "NEW BOW" << endl;
		return new Bow(this->fire_range, this->damage_type, this->critical_damage_bonus);
	}

private:
	int fire_range;
	string damage_type;
	int critical_damage_bonus;
};

class Dagger : public Weapon, public Prototype
{
public:
	Dagger(int fire_range = 1, string damage_type = "Single", int critical_damage_bonus = 5) : fire_range(fire_range), damage_type(damage_type), critical_damage_bonus(critical_damage_bonus) {};

	int fireRange() const override
	{
		return this->fire_range;
	}
	string damageType() const override
	{
		return this->damage_type;
	}
	int criticalDamageBonus() const override
	{
		return this->critical_damage_bonus;
	}
	Prototype* clone() const override
	{
		cout << "NEW DAGGER" << endl;
		return new Dagger(this->fire_range, this->damage_type, this->critical_damage_bonus);
	}

private:
	int fire_range;
	string damage_type;
	int critical_damage_bonus;
};

class FactoryOfWeapon : public Prototype
{
public:
	virtual Weapon* factoryMethod() const = 0;
	virtual void createWeapon() const = 0;
	virtual ~FactoryOfWeapon() {};

	/*void CreateWeapon() const
	{
		Weapon* weapon = this->factoryMethod();
		cout << "Created weapon with characteristics: \nFire range | Damage type | Bonus\n" << "    " << weapon->fireRange() << "\t\t" << weapon->damageType() << "\t     " << weapon->criticalDamageBonus() << "\t" << endl;
	}*/
private:
};

class FactoryOfSword : public FactoryOfWeapon
{
public:
	Weapon* factoryMethod() const override
	{
		return new Sword();
	}
	void createWeapon() const override
	{
		Sword sword;
		cout << "Created sword with characteristics: \nFire range | Damage type | Bonus\n" << "    " << sword.fireRange() << "\t\t" << sword.damageType() << "\t     " << sword.criticalDamageBonus() << "\t" << endl;
	}
};

class FactoryOfBow : public FactoryOfWeapon
{
public:
	Weapon* factoryMethod() const override
	{
		return new Bow();
	}
	void createWeapon() const override
	{
		Bow bow;
		cout << "Created bow with characteristics: \nFire range | Damage type | Bonus\n" << "    " << bow.fireRange() << "\t\t" << bow.damageType() << "\t     " << bow.criticalDamageBonus() << "\t" << endl;
	}
};

class FactoryOfDagger : public FactoryOfWeapon
{
public:
	Weapon* factoryMethod() const override
	{
		return new Dagger();
	}
	void createWeapon() const override
	{
		Dagger dagger;
		cout << "Created dagger with characteristics: \nFire range | Damage type | Bonus\n" << "    " << dagger.fireRange() << "\t\t" << dagger.damageType() << "\t     " << dagger.criticalDamageBonus() << "\t" << endl;
	}
};


class PrototypeFactory
{
public:
	PrototypeFactory()
	{
		prototypes[Weapon_for_clone::SWORD] = new Sword();
		prototypes[Weapon_for_clone::BOW] = new Bow();
		prototypes[Weapon_for_clone::DAGGER] = new Dagger();
	}

	static PrototypeFactory& getInstance()
	{
		static PrototypeFactory instance;
		return instance;
	}

	Prototype* createClone(Weapon_for_clone weapon_for_clone)
	{
		return prototypes[weapon_for_clone]->clone();
	}

	~PrototypeFactory()
	{
		prototypes.clear();
	}


private:
	unordered_map<Weapon_for_clone, Prototype*, hash<int>> prototypes;
};