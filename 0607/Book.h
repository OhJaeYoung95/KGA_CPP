#pragma once

class Book
{
protected:
	char* title;	// å ����
	char* isbn;		// ����ǥ�� ������ȣ
	int price;		// å�� ����
public:
	Book();
	Book(const char* _title, const char* _isbn, int price);
	Book(Book& ref);

	int GetTitleLen();
	int GetIsbnLen();
	virtual void ShowBookInfo();
	virtual ~Book();

	Book& operator= (const Book& ref);
};