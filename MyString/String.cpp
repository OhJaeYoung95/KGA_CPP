#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>
#include <cstring>

using namespace my;

String::String() : str(nullptr), length(0)
{
}

String::String(const char* _str)
{
	length = strlen(_str) + 1;
	str = new char[length];
	strcpy(str, _str);
}

String::~String()
{
	delete[] str;
}

String::String(const String& ref) : length(ref.length)
{
	str = new char[length];
	strcpy(str, ref.str);
}

String& String::operator=(const String& ref)
{
	if (this == &ref)
		return *this;

	delete[] str;
	length = ref.length;
	str = new char[length];
	strcpy(str, ref.str);
	return *this;
}

String String::operator+(const String& ref)
{
	int newLength = length + ref.length - 1;
	char* newStr = new char[newLength];
	strcpy(newStr, str);
	strcat(newStr, ref.str);
	String result(newStr);
	delete[] newStr;
	return result;
}

String& String::operator+=(const String& ref)
{
	int newLength = length + ref.length - 1;
	char* newStr = new char[newLength];
	strcpy(newStr, str);
	strcat(newStr, ref.str);
	delete[] str;
	str = newStr;
	length = newLength;
	return *this;
}

bool String::operator==(const String& ref)
{
	return strcmp(str, ref.str) == 0;
}

ostream& my::operator<<(ostream& os, const String& str)
{
	os << str.str;
	return os;
}

istream& my::operator>>(istream& is, String& _str)
{
	char buffer[256];
	is.getline(buffer, 256);	// 띄어쓰기 가능
	//is >> buffer;
	delete[] _str.str;
	_str.length = strlen(buffer) + 1;
	_str.str = new char[_str.length];
	strcpy(_str.str, buffer);


	return is;
}
