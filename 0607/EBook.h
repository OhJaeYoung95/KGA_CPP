#pragma once
#include "Book.h"

class EBook : public Book
{
private:
	char* DRMKey;	// 보안관련 키
public:
	EBook();
	EBook(const char* _title, const char* _isbn, int _price, const char* _DRMKey);
	EBook(EBook& ref);

	int GetDRMKeyLen();
	void ShowBookInfo() override;
	virtual ~EBook();

	EBook& operator= (const EBook& ref);
};