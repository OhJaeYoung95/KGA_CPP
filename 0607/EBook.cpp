#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

#include "EBook.h"
using namespace std;

EBook::EBook()
{
	//DRMKey = new char[strlen(DRMKey) + 1];
}

EBook::EBook(const char* _title, const char* _isbn, int _price, const char* _DRMKey) : Book(_title, _isbn, _price)
{
	DRMKey = new char[strlen(_DRMKey) + 1];
	strcpy(DRMKey, _DRMKey);

}
EBook::EBook(EBook& ref) : Book(ref.title, ref.isbn, ref.price)
{
	if (DRMKey != nullptr)
		delete[] DRMKey;
	DRMKey = new char[ref.GetDRMKeyLen()];
	strcpy(DRMKey, ref.DRMKey);


}
int EBook::GetDRMKeyLen()
{
	return strlen(DRMKey) +1;
}
void EBook::ShowBookInfo()
{
	Book::ShowBookInfo();
	cout << "ÀÎÁõÅ°: " << DRMKey << endl;

}
EBook::~EBook()
{
	if (DRMKey != nullptr)	
		delete[] DRMKey;
}

EBook& EBook::operator=(const EBook& ref)
{
	Book::operator=(ref);
	delete[] DRMKey;
	DRMKey = new char[strlen(ref.DRMKey) + 1];
	strcpy(DRMKey, ref.DRMKey);
	return *this;
}