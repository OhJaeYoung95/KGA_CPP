#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
		String();
		String(const char* _str);
		~String();

		String(const String& ref);
		String& operator=(const String& ref);

		String operator+(const String& ref);
		String& operator+=(const String& ref);
		bool operator==(const String& ref);

		friend ostream& operator <<(ostream& os, const String& str);
		friend istream& operator >>(istream& is, String& _str);
	};

	ostream& operator<< (ostream& os, const String& str);
	istream& operator>> (istream& is, String& _str);
}
