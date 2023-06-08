#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>

using namespace my;

my::String::String() : str(nullptr), length(0)
{
}

my::String::String(const char* _str)
{
	length = strlen(_str) + 1;
	if (str != nullptr)
		delete[] str;
	str = new char[length];
	strcpy(str, _str);
}

my::String::String(const String& ref) : length(ref.length)
{
	if (str != nullptr)
		delete[] str;
	if (ref.str != nullptr)
	{
		str = new char[ref.length];
		strcpy(str, ref.str);
	}
	else
	{
		str = nullptr;
	}
}

my::String::~String()
{
	if (str != nullptr)
		delete[] str;
}

String& my::String::operator=(const String& ref)
{
	if (this == &ref)
		return *this;

	if (str != nullptr)
		delete[] str;
	if (ref.str != nullptr)
	{
		str = new char[ref.length];
		strcpy(str, ref.str);
	}
	else
	{
		str = nullptr;
	}
	return *this;
}

String my::String::operator+(const String& ref)
{
	String strCat(*this);
	if (ref.str != nullptr)
		strcat(strCat.str, ref.str);
	return strCat;
}
String my::String::operator+=(const String& ref)
{
	
	String strCat(*this);
	strCat.length += ref.length - 1;
	if (ref.str != nullptr)
		strcat(strCat.str, ref.str);
	return strCat;
}

bool my::String::operator==(const String& ref)
{
	int same = strcmp(this->str, ref.str);
	if (same != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//ostream& my::operator<<(ostream& os, String str)
//{
//	// TODO: 여기에 return 문을 삽입합니다.
//}

ostream& my::operator<<(ostream& os, String str)
{
	os << str.str;
	return os;
}

istream& my::operator>>(istream& is, String _str)
{
	String buffer(_str);
	is >> buffer.str;
	strcpy(_str.str, buffer.str);
	//char buffer[100];
	//is >> buffer;
	//delete[] _str.str;
	//_str.length = strlen(buffer) + 1;
	//_str.str = new char[_str.length];
	//strcpy(_str.str, buffer);
	return is;
}
