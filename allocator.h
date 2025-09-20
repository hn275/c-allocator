#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstddef>

void *memalloc(size_t n);

void memfree(void *ptr);

#endif
