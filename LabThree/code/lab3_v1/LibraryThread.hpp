#pragma once
#include<mutex>
#include<map>
#include<deque>
#include<thread>
#include"Book.hpp"
using namespace std;
class BorrowThread{
    friend class BorrowSystem;
    public:
    BorrowThread(int num,int bookNumber,Book* book);
    void Startup();
    void Work();
    static void BorrowThreadMain(void* BorrowthreadObject);

    private:
    int                   book_num=0;
    int                   book_bookNumber=0;
    Book*                 book_book=nullptr;
    thread*               book_thread=nullptr;
    mutable mutex         book_StatusMutex;
};