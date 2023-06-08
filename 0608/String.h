#pragma once
#include <iostream>

using namespace std;

namespace my
{
	class String
	{
	private:
		char* str;
		int length;

	public:
		String(const String& ref);
		String& operator=(const String& ref);
		String();
		String(const char* _str);
		~String();

		String operator+(const String& ref);
		String operator+=(const String& ref);
		bool operator==(const String& ref);

		friend ostream& operator <<(ostream& os, String str);
		friend istream& operator >>(istream& is, String _str);
	};

	ostream& operator<< (ostream& os, String str);
	istream& operator>> (istream& is, String _str);
}