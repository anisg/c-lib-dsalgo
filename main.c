#include <dsalgo.h>

int main(){

	char *s = str("coucou");
	s = prepend(s, "OK -- ");

	printf("|%s|\n", s);

	int x = 4;
	Vector *v = vector(sizeof(int));
	vpush(v, &x);
	vpush(v, &x);
	vprint(v, itos);
}
