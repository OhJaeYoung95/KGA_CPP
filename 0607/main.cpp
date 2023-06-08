#include <iostream>
#include "Point.h"
#include "Police.h"
#include "Gun.h"
#include "Book.h"
#include "EBook.h"

void Practice1()
{
	Point pos1;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos1;
	cout << pos1;

	Point pos2;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> pos2;
	cout << pos2;
}

void Practice2()
{
	Police pman1(5, 3);
	Police pman2(pman1);
	Police pman3 = pman2;
	pman2.Shot();
	pman2.PutHandcuff();
	pman3.Shot();
	pman3.PutHandcuff();
}

void Practice3()
{
	Book book1("좋은 C++", "555-12345-890-0", 20000);
	Book book2;
	book2 = book1;
	Book book3(book2);
	book2.ShowBookInfo();
	book3.ShowBookInfo();
	EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2(ebook1);
	EBook ebook3;
	ebook3 = ebook2;
	ebook2.ShowBookInfo();
	ebook3.ShowBookInfo();
}

int main()
{
	Practice3();
	return 0;
}