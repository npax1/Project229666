#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


enum setState
{
	MINIMUM = 1,
	MEDIUM,
	FULL
};

class Prototype
{
public:
	Prototype() {};
	virtual Prototype* cloneItem() const { return nullptr; };

	static Prototype& getInstance()
	{
		static Prototype instance;
		return instance;
	}
};

class Product : public Prototype
{
public:
	vector <string> parts;
	void ListParts() const
	{
		cout << "Parts: ";
		for (size_t i = 0; i < parts.size(); i++)
		{
			if (parts[i] == parts.back())
			{
				cout << parts[i] + "." << endl;
			}
			else
			{
				cout << parts[i] + ",";
			}
		}
	}
	Prototype* cloneItem() const override
	{
		Product* cloned_product = new Product();
		cloned_product->parts = this->parts;
		cout << "CLONED" << endl;
		return cloned_product;
	}
};

class Builder
{
public:
	Builder()
	{
		this->reset();
	};

	Product* product;

	void produceComponent1() const
	{
		this->product->parts.push_back("Part 1");
	};
	void produceComponent2() const
	{
		this->product->parts.push_back("Part 2");
	};
	void produceComponent3() const
	{
		this->product->parts.push_back("Part 3");
	};
	void reset()
	{
		this->product = new Product();
	};

	~Builder()
	{
		delete product;
	}

	Product* getProduct()
	{
		Product* result = this->product;
		this->reset();
		return result;
	}
};


class Director : public Builder, public Prototype
{
private:
	Builder* builder;

public:
	Director(Builder* builder) : builder(builder) {};
	void setBuilder(Builder* builder)
	{
		this->builder = builder;
	}
	void buildMinimal()
	{
		this->builder->produceComponent1();
	}
	void buildMedium()
	{
		buildMinimal();
		this->builder->produceComponent2();
	}
	void buildFull()
	{
		buildMedium();
		this->builder->produceComponent3();
	}
	void showProduct() const
	{
		this->builder->product->ListParts();
	}
};