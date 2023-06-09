#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <iostream>
#include <cstring>

using namespace my;

my::String::String() : str(nullptr), length(0)
{
}

my::String::String(const char* _str)
{
	//length = strlen(_str) + 1;
	//if (str != nullptr)
	//	delete[] str;
	//str = new char[length];
	//strcpy(str, _str);

	length = strlen(_str) + 1;
	str = new char[length];
	strcpy(str, _str);

}

my::String::~String()
{
	//if (str != nullptr)
		delete[] str;
}

my::String::String(const String& ref) : length(ref.length)
{
	//if (str != nullptr)
	//	delete[] str;
	//if (ref.str != nullptr)
	//{
	//	str = new char[ref.length];
	//	strcpy(str, ref.str);
	//}
	//else
	//{
	//	str = nullptr;
	//}

	str = new char[length];
	strcpy(str, ref.str);
}

String& my::String::operator=(const String& ref)
{
	//if (this == &ref)
	//	return *this;

	//if (str != nullptr)
	//	delete[] str;
	//if (ref.str != nullptr)
	//{
	//	length = ref.length;
	//	str = new char[length];
	//	strcpy(str, ref.str);
	//}
	//else
	//{
	//	str = nullptr;
	//}
	//return *this;

	if (this == &ref)
		return *this;

	delete[] str;
	length = ref.length;
	str = new char[length];
	strcpy(str, ref.str);
	return *this;

}

String my::String::operator+(const String& ref)
{
	//String strCat(*this);
	//if (ref.str != nullptr)
	//	strcat(strCat.str, ref.str);
	//return strCat;

	int newLength = length + ref.length - 1;
	char* newStr = new char[newLength];
	strcpy(newStr, str);
	strcat(newStr, ref.str);
	String result(newStr);
	delete[] newStr;
	return result;

}
String& my::String::operator+=(const String& ref)
{
	
	String strCat(*this);
	strCat.length += ref.length - 1;
	if (ref.str != nullptr)
		strcat(strCat.str, ref.str);
	return strCat;

	//int newLength = length + ref.length - 1;
	//char* newStr = new char[newLength];
	//strcpy(newStr, str);
	//strcat(newStr, ref.str);
	//delete[] str;
	//str = newStr;
	//length = newLength;
	//return *this;
}

bool my::String::operator==(const String& ref)
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
	//String buffer(_str);
	//is.getline(buffer.str, 256);	// 띄어쓰기 가능
	//delete[] _str.str;
	//_str.length = buffer.length + 1;
	//_str.str = new char[_str.length]; 
	//strcpy(_str.str, buffer.str);

	//char buffer[100];
	//is.getline(buffer, 100);
	//delete[] _str.str;
	//_str.length = strlen(buffer) + 1;
	//_str.str = new char[_str.length];
	//strcpy(_str.str, buffer);
	return is;
}
