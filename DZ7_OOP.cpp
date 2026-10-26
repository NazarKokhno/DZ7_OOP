#include <iostream>
#include <windows.h>
#include <cstring>

using namespace std;

class Overcoat
{
private:
	char* type;
	char* color;
	char* size;
	double price;
public:
	Overcoat() :type(nullptr), color(nullptr), size(nullptr),price(0) {}
	
	Overcoat(const char* type, const char* color, const char* size,double price)
		:type(nullptr), color(nullptr), size(nullptr)
	{
		this->price = price;
		
		if (type != nullptr)
		
		{
			this->type = new char[strlen(type) + 1];
			strcpy_s(this->type, strlen(type) + 1, type);
		}
		
		if (color != nullptr)
		{
			this->color = new char[strlen(color) + 1];
			strcpy_s(this->color, strlen(color) + 1, color);
		}
		
		if (size != nullptr)
		{
			this->size = new char[strlen(size) + 1];
			strcpy_s(this->size, strlen(size) + 1, size);
		}
	}
	
	Overcoat(const Overcoat& other)
		:type(nullptr), color(nullptr), size(nullptr)
	{
		this->price = other.price;

		if (other.type != nullptr)
		{
			this->type = new char[strlen(other.type) + 1];
			strcpy_s(this->type, strlen(other.type) + 1, other.type);

		}

		if (other.color != nullptr)
		{
			this->color = new char[strlen(other.color) + 1];
			strcpy_s(this->color, strlen(other.color) + 1, other.color);

		}

		if (other.size != nullptr)
		{
			this->size = new char[strlen(other.size) + 1];
			strcpy_s(this->size, strlen(other.size) + 1, other.size);

		}

	
	}

	Overcoat& operator=(const Overcoat& other)
	{
		if (this == &other)
			return *this;

		delete[] type;
		delete[] color;
		delete[] size;

		type = nullptr;
		color = nullptr;
		size = nullptr;

		if (other.type != nullptr)
		{
			type = new char[strlen(other.type) + 1];
			strcpy_s(type, strlen(other.type) + 1, other.type);
		}

		if (other.color != nullptr)
		{
			color = new char[strlen(other.color) + 1];
			strcpy_s(color, strlen(other.color) + 1, other.color);
		}

		if (other.size != nullptr)
		{
			size = new char[strlen(other.size) + 1];
			strcpy_s(size, strlen(other.size) + 1, other.size);
		}

		price = other.price;

		return *this;
	}

	bool operator==(const Overcoat& other) const
	{
		if (type == nullptr || other.type == nullptr)
			return type == other.type;

		return strcmp(this->type, other.type) == 0;
	}
	
	bool operator>(const Overcoat& other) const
	{
		if (!(*this == other))
			return false;

		return this->price > other.price;
	}

	void show()
	{
		cout << "show()";
		
		if (type == nullptr || color == nullptr || size == nullptr)
		{
			cout << "Error: Some data is missing!" << endl;
			return;
		}
		cout << endl;
		cout << "Name: " << type << endl;
		cout << "Color: " << color << endl;
		cout << "Size: " << size << endl;
		cout << "Price: " << price << endl;
	}
	
	~Overcoat()
	{
		delete[] type;
		delete[] color;
		delete[] size;
	}

};

int main()
{
	Overcoat a("Classic Coat", "Black", "L",115);
	Overcoat b("Winter Coat", "Brown", "XL",200);
	cout << "a: ";
	a.show();
	
	cout << "\nb: ";
	b.show();

	bool result1 = a == b;
	bool result2 = a > b;
	
	cout << "\na.type == b.type? " << (result1 ? "true" : "false"); // false
	cout << "\na.price > b.price? " << (result2 ? "true" : "false") << endl; // true
	cout << "\na: ";
	
	a.show();
	
	cout << "\na = b" << endl;
	a = b;
	cout << "\na: ";
	
	a.show();
	
	result1 = a == b;
	result2 = a > b;
	
	cout << "\na.type == b.type? " << (result1 ? "true" : "false") << endl; // true
	cout << "a.price > b.price? " << (result2 ? "true" : "false") << endl; // false
}

