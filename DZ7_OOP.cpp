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

	bool operator==(const Overcoat& other)
	{
		
		if (type == nullptr || other.type == nullptr)
			return type == other.type;

		return strcmp(this->type, other.type) == 0;
	}
	
	void show()
	{
		if (type == nullptr || color == nullptr || size == nullptr)
		{
			cout << "Error: Some data is missing!" << endl;
			return;
		}

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
	Overcoat a("Classic Coat", "Black", "L",12);
	Overcoat b("Winter Coat", "Brown", "XL",12);
	
	



}

