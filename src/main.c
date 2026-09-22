#include <stdio.h>
#include <stdlib.h>

typedef struct Vec Vec;

struct Vec {
	unsigned char *ptr;
	int len;
	int capacity;
};

Vec new(void) {
	Vec self;
	self.ptr = NULL;
	self.len = 0;
	self.capacity = 0;
	return self;
}

void format(Vec *self) {
	printf("Vec {");
	for (int i = 0; i < self->len; i++) {
		if (i == (self->len - 1)) {
			printf("%d}\n", self->ptr[i]);
		} else {
			printf("%d, ", self->ptr[i]);
		}
	}
	return;
}

void push(Vec *self, unsigned char element) {
	if (self->len == self->capacity) {
		self->capacity = (self->capacity == 0) ? 1 : self->capacity * 2;
		unsigned char *temp = realloc(self->ptr, sizeof(unsigned char) * self->capacity);
		if (!temp) {
			printf("Error: out of memory");
			exit(EXIT_FAILURE);
		}
		self->ptr = temp;
	}
	self->ptr[self->len] = element;
	self->len++;
	return;
}

int main(void) {
	Vec my_vec = new();
	for (int i = 0; i < 0xff; i++) {
		push(&my_vec, i + 1);
	}
	format(&my_vec);
	return EXIT_SUCCESS;
}
