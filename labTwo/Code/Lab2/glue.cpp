
#include <emscripten.h>

extern "C" {

// Not using size_t for array indices as the values used by the javascript code are signed.

EM_JS(void, array_bounds_check_error, (size_t idx, size_t size), {
  throw 'Array index ' + idx + ' out of bounds: [0,' + size + ')';
});

void array_bounds_check(const int array_size, const int array_idx) {
  if (array_idx < 0 || array_idx >= array_size) {
    array_bounds_check_error(array_idx, array_size);
  }
}

// VoidPtr

void EMSCRIPTEN_KEEPALIVE emscripten_bind_VoidPtr___destroy___0(void** self) {
  delete self;
}

// Book

Book* EMSCRIPTEN_KEEPALIVE emscripten_bind_Book_Book_0() {
  return new Book();
}

Book* EMSCRIPTEN_KEEPALIVE emscripten_bind_Book_Book_3(int id, double price, int number) {
  return new Book(id, price, number);
}

int EMSCRIPTEN_KEEPALIVE emscripten_bind_Book_get_id_0(Book* self) {
  return self->get_id();
}

int EMSCRIPTEN_KEEPALIVE emscripten_bind_Book_get_number_0(Book* self) {
  return self->get_number();
}

double EMSCRIPTEN_KEEPALIVE emscripten_bind_Book_get_price_0(Book* self) {
  return self->get_price();
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_Book_set_number_1(Book* self, int n_number) {
  self->set_number(n_number);
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_Book_set_id_1(Book* self, int id) {
  self->set_id(id);
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_Book_set_price_1(Book* self, double price) {
  self->set_price(price);
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_Book___destroy___0(Book* self) {
  delete self;
}

// Library

Library* EMSCRIPTEN_KEEPALIVE emscripten_bind_Library_Library_0() {
  return new Library();
}

int EMSCRIPTEN_KEEPALIVE emscripten_bind_Library_get_m_0(Library* self) {
  return self->get_m();
}

bool EMSCRIPTEN_KEEPALIVE emscripten_bind_Library_search_0(Library* self) {
  return self->search();
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_Library_set_book1_3(Library* self, int id, double price, int number) {
  self->set_book1(id, price, number);
}

bool EMSCRIPTEN_KEEPALIVE emscripten_bind_Library_borrow_book_2(Library* self, int id, int num) {
  return self->borrow_book(id, num);
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_Library_show_0(Library* self) {
  self->show();
}

double EMSCRIPTEN_KEEPALIVE emscripten_bind_Library_sale_sum_0(Library* self) {
  return self->sale_sum();
}

double EMSCRIPTEN_KEEPALIVE emscripten_bind_Library_sale_average_0(Library* self) {
  return self->sale_average();
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_Library_sale_show_2(Library* self, double sum, double average) {
  self->sale_show(sum, average);
}

void EMSCRIPTEN_KEEPALIVE emscripten_bind_Library___destroy___0(Library* self) {
  delete self;
}

}

