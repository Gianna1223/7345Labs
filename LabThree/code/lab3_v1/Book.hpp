#pragma once
class Book {
    friend class LibraryThread;
    friend class System;
private:
	int num;
	double price;
	int BookNumber;
public:
	Book(int n, double p, int BookNumber);
	int getNum();
	double getPrice();
	int getBookNumber();
	void borrow();
};