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

	void show() const
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

class Flat
{
private:
	int floor;
	int aptNumber;
	int rooms;
	double area;
	double price;
	char* address;
public:
	Flat(): Flat(0,0,0,0,0,"Unknown") {}

	Flat(int floor, int aptNumber, int rooms, double area, double price, const char* address)
		:floor(floor),aptNumber(aptNumber),rooms(rooms),area(area),price(price),address(nullptr)
	{
		if (address != nullptr)
		{
			this->address = new char[strlen(address) + 1];
			strcpy_s(this->address, strlen(address) + 1, address);
		}

	}

	Flat(const Flat& other)
		:floor(other.floor), aptNumber(other.aptNumber), rooms(other.rooms), area(other.area), price(other.price), address(nullptr)
	{

		if (other.address != nullptr)
		{
			this->address = new char[strlen(other.address) + 1];
			strcpy_s(this->address, strlen(other.address) + 1, other.address);

		}

	}

	Flat& operator=(const Flat& other)
	{
		if (this == &other)
		{
			return *this;
		}

			delete[] address;
			address = nullptr;
	
		floor = other.floor;
		aptNumber = other.aptNumber;
		rooms = other.rooms;
		area = other.area;
		price = other.price;

		if (other.address != nullptr)
		{
			address = new char[strlen(other.address) + 1];
			strcpy_s(address, strlen(other.address) + 1, other.address);

		}
		return *this;
	}

	bool operator==(const Flat& other) const
	{
		return area == other.area;
	}

	bool operator>(const Flat& other) const
	{
		return price > other.price;
	}
	

	void show() const
	{
		cout << "Floor: " << floor << endl;
		cout << "AptNumber: " << aptNumber << endl;
		cout << "Rooms: " << rooms << endl;
		cout << "Area: " << area << endl;
		cout << "Price: " << price << endl;
		cout << "Address: " << address << endl;
	}

	~Flat()
	{
		delete[] address;
	}

};


int main()
{
	// TASK 1
	cout << "\nTASK 1" << endl;
	
	Overcoat o1("Jacket", "Black", "L", 2500);
	Overcoat o2("Jacket", "Black", "XL", 3200);
	Overcoat o3("Coat", "Grey", "M", 4000);

	cout << "=== Original objects ===" << endl;
	o1.show();
	cout << endl;
	o2.show();
	cout << endl;
	o3.show();

	cout << "\n=== Copy constructor ===" << endl;
	Overcoat o4(o1);
	o4.show();

	cout << "\n=== Assignment operator ===" << endl;
	Overcoat o5;
	o5 = o2;
	o5.show();

	cout << "\n=== Operator == ===" << endl;

	if (o1 == o2)
		cout << "o1 and o2 have the same type" << endl;
	else
		cout << "o1 and o2 have different types" << endl;

	if (o1 == o3)
		cout << "o1 and o3 have the same type" << endl;
	else
		cout << "o1 and o3 have different types" << endl;

	cout << "\n=== Operator > ===" << endl;

	if (o2 > o1)
		cout << "o2 is more expensive than o1" << endl;
	else
		cout << "o2 is not more expensive than o1 of the same type" << endl;

	if (o3 > o1)
		cout << "o3 is more expensive than o1" << endl;
	else
		cout << "o3 is not more expensive than o1 of the same type" << endl;

	cout << "\n=== Self-assignment ===" << endl;
	o1 = o1;
	o1.show();

	cout << "\n=== Default constructor ===" << endl;
	Overcoat o6;
	o6.show();
	
	// TASK 2
	cout << "\nTASK 2" << endl;

	Flat f1(2, 15, 2, 65.5, 75000, "Kyiv, Khreshchatyk 10");
	Flat f2(5, 28, 3, 85.0, 120000, "Lviv, Svobody Avenue 5");

	cout << "=== Original objects ===" << endl;
	f1.show();
	cout << endl;
	f2.show();

	cout << "\n=== Copy constructor ===" << endl;
	Flat f3(f1);
	f3.show();

	cout << "\n=== Assignment operator ===" << endl;
	Flat f4;
	f4 = f2;
	f4.show();

	cout << "\n=== Operator == ===" << endl;
	if (f1 == f2)
		cout << "Areas are equal" << endl;
	else
		cout << "Areas are different" << endl;

	cout << "\n=== Operator > ===" << endl;
	if (f2 > f1)
		cout << "f2 is more expensive than f1" << endl;
	else
		cout << "f2 is not more expensive than f1" << endl;

	cout << "\n=== Self-assignment ===" << endl;
	f1 = f1;
	f1.show();

	cout << "\n=== Default constructor ===" << endl;
	Flat f5;
	f5.show();

	return 0;
}

