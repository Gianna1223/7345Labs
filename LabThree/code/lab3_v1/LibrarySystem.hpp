#pragma once
#include <mutex>
#include <map>
#include <deque>
#include <thread>
#include <vector>
using namespace std;
class BorrowThread;
class Book;
class BorrowSystem
{
    friend class BorrowThread;

public:
    BorrowSystem();
    static BorrowSystem *CreateOrGet();
    void CreateBorrowThread(int num, int BookNumber, Book *book);

    static BorrowSystem *book_BorrowSystem;
    vector<BorrowThread *> book_BorrowThreads;
    mutable mutex book_BorrowThreadsMutex;
    vector<Book *> book_Books;
    mutex book_BorrowMutex;
};
