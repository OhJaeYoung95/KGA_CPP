#pragma once

class Book
{
protected:
	char* title;	// 책 제목
	char* isbn;		// 국제표준 도서번호
	int price;		// 책의 정가
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