#include <stdio.h>
#include <stdlib.h>

typedef struct Vec Vec;

struct Vec {
	unsigned char *ptr;
	int len;
	int capacity;
};

void push(Vec *self, unsigned char element) {
	if (self->capacity == 0) {
		self->capacity = 1;
		self->ptr = (unsigned char *)malloc(sizeof(unsigned char));
		self->ptr[0] = element;
	}
	else if (self->len == self->capacity) {
		self->capacity *= 2;
		unsigned char buffer[self->len];
		for (int i = 0; i < self->len; i++) {
			buffer[i] = self->ptr[i];
		}
		self->ptr = (unsigned char *)realloc(self->ptr, sizeof(unsigned char) * self->capacity);
		for (int i = 0; i < self->len; i++) {
			self->ptr[i] = buffer[i]; 
		}
	}
	self->ptr[self->len] = element;
	self->len++;
	return;
}

int main(void) {
	Vec my_vec;
	for (int i = 0; i < 10; i++) {
		push(&my_vec, i + 1);
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", my_vec.ptr[i]);
	}
}
