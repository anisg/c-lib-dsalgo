# dsalgo : basic C algorithms library

a short library with simple C data structures and algorithms.

## usage


#### installation

1. extract the zip
2. in the repository, launch shell command `make` 

it will generate a dsalgo.a file

#### compilation

using gcc
`$ gcc yourfile.c dsalgo/dsalgo.a -I dsalgo/include`

#### include in the source

```C
#include <dsalgo.h>
```

## documentation

- **Vector**: dynamic array
- **String manipulation**: split, append, startswith, join ...

### Vector (dynamic array)

- `Vector *vector(int size)`: init a vector in which each element will have a fixed size of `size` bits (ex: an integer is 4 bits).
- `int vpush(Vector *v, void *data)`: copy `data` value and add it at the end of the vector. returns 0 on fail, 1 otherwise.
- `void *vpop(Vector *v)`: remove last element in the vector.
- `int vsize(Vector *v)`: return the number of elements.
- `int vempty(Vector *v)`: return 1 if `v` contains no elements, 0 otherwise.
- `void vprint(Vector *v, char *(*f)(void*))`: output on stdin the vector, with `f` return a string representing one element passed as parameters.
- `void *vzone(Vector *v)`: return the adress of the first element.
- `int vremove(Vector **v)`: release vector memory.

#####\#example 1: initialize a vector, add elements, and print it

```C
int A[] = {1,2,3};
int x = 4;

Vector *v = vector( sizeof(int) );  //here each element of the vector
                                    //is a size of an int 
                                    
vpush(v, A);                        // add A[0] (copy its value)
vpush(v, A + 1);                    // add A[1] 
vpush(v, A + 2);                    // add A[2]
vpush(v, &x);                       // add x

vprint(v, &itos); //output "[1,2,3,4]\n"
```

#####\#example 2: remove last element using vpop

```
//... from previous example

vpop(v);
vprint(v, &itos); //output "[1,2,3]\n"
```

#####\#example 3: iterate through a vector

```C
//...

for (int i = 0; i < vsize(v); i += 1){
	int *x = vget(v, i);
	printf("%d\n", *x );
}
```

#####\#example 4: iterate through a vector by accessing its zone in memory

```C
//...

int *p = vzone(v);
for (int i = 0; i < vsize(v); i += 1){
	printf("%d\n", p[i] );
}
```

### String Manipulation

- `Vector *split(char *s, char *delimiter)`
- `int				startswith(char *s, char *d)`
- `int endswith(char *s, char *d)`
- `int contains(char *s, char *d)`
- `char *prepend(char *s, char *pre)`
- `char *append(char *s, char *app)`
- `char *join(char sep, char **args)`
- `char *str(const char *s)`


#####\#example 1: split a string
```C
Vector *v = split("how are you?", " ");

vprintstr(v); //output: "['how', 'are', 'you?']\n"
```

#####\#example 2: check if a string begins by another string
```C
char *s = "abc hello";

printf("%d\n", startswith(s, "123")); //output "0\n"
printf("%d\n", startswith(s, "abc")); //output "1\n"
```

#####\#example 3: add at the end of string another string
```C
char *s = str("123");

printf("%s\n", s); //output "123\n"

s = append(s, "456");

printf("%s\n", s); //output "123456\n"
```

