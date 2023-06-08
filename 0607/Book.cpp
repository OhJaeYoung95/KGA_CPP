#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#include "Book.h"

using namespace std;



Book::Book()
{

}

Book::Book(const char* _title, const char* _isbn, int _price) : price(_price)
{
	title = new char[strlen(_title) + 1];
	isbn = new char[strlen(_isbn) + 1];

	strcpy(title, _title);
	strcpy(isbn, _isbn);
}

Book::Book(Book& ref)
{
	if (title != nullptr)
		delete[] title;
	if (isbn != nullptr)
		delete[] isbn;
	title = new char[ref.GetTitleLen()];
	isbn = new char[ref.GetIsbnLen()];
	strcpy(title, ref.title);
	strcpy(isbn, ref.isbn);
	price = ref.price;
}

int Book::GetTitleLen()
{
	return strlen(title) +1;
}

int Book::GetIsbnLen()
{
	return strlen(isbn) +1;
}


void Book::ShowBookInfo()
{
	cout << "제목: " << title << endl;
	cout << "ISBN: " << isbn << endl;
	cout << "가격: " << price << endl;
}


Book::~Book()
{
	if (title != nullptr)
		delete[] title;
	if (isbn != nullptr)
		delete[] isbn;
}

Book& Book::operator=(const Book& ref)
{
	if (title != nullptr)
		delete[] title;
	if (isbn != nullptr)
		delete[] isbn;
	title = new char[strlen(ref.title) +1];
	isbn = new char[strlen(ref.isbn) + 1];
	strcpy(title, ref.title);
	strcpy(isbn, ref.isbn);
	price = ref.price;
	return *this;
}