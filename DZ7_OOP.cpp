#include <iostream>
#include <windows.h>

using namespace std;

class Overcoat
{
private:
	char* name;
	char* color;
	char* size;
public:
	Overcoat(const char* name, const char* color, const char* size)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		
		this->color = new char[strlen(color) + 1];
		strcpy_s(this->color, strlen(color) + 1, color);
		
		this->size = new char[strlen(size) + 1];
		strcpy_s(this->size, strlen(size) + 1, size);
	}
	
	
	void show()
	{
		cout << "Name: " << name << std::endl;
		cout << "Color: " << color << std::endl;
		cout << "Size: " << size << std::endl;
	}
	
	~Overcoat()
	{
		delete[] name;
		delete[] color;
		delete[] size;
	}

};

int main()
{
	Overcoat a("Classic Coat", "Black", "L");
	Overcoat b("Winter Coat", "Brown", "XL");

	a.show();
	b.show();

}

