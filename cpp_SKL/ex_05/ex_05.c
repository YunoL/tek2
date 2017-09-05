
#include <stdio.h>
#include <assert.h>

#include "array.h"
#include "float.h"
#include "int.h"
#include "new.h"


int main()
{
    Object* array = new(Array, 10, Float, 0.0f);
    Object* it = begin(array);
    Object* it_end = end(array);

    printf("array size: %zu\n", len(array));
    setitem(array, 5, 12.f);
    setitem(array, 6, 13.f);
    while (lt(it, it_end))
    {
        printf("%s\n", str(getval(it)));
        incr(it);
    }
    delete(it);
    delete(it_end);
    delete(array);
    return 0;
}
