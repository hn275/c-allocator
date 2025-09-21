#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct {
	int id;
	float value;
	char *name;
} Foo;

int main() {
	const Foo foo = {12, 1.2, "foo"};
	void* memStart = sbrk(0);
	void* memEnd = sbrk(sizeof(Foo));
	if (memEnd == (void*)-1) {
		printf("failed to allocate memory");
		return 1;
	}

	memcpy(memStart, &foo, sizeof(Foo));

	const Foo* const fooHeap = (Foo*)memStart;
	printf("id: %d, value: %f, name: %s", fooHeap->id, fooHeap->value, fooHeap->name);
	return 0;
}
