#include <cstdio>

#include "TruthVariable.h"

void test()
{
	printf("Start of tests ...\n\n");

	TruthVariable a(TRUE);
	TruthVariable b(UNKNOWN);
	TruthVariable c(FALSE);

	// Test correct lookup of string.
	printf("TRUE = %s\n", a.toString());
	printf("UNKNOWN = %s\n", b.toString());
	printf("FALSE = %s\n\n", c.toString());

	// Test IDENTITY operation.
	printf("IDENTITY %s = %s\n", a.toString(), a.IDENTITY().toString());
	printf("IDENTITY %s = %s\n", b.toString(), b.IDENTITY().toString());
	printf("IDENTITY %s = %s\n\n", c.toString(), c.IDENTITY().toString());

	// Test NOT operation.
	printf("NOT %s = %s\n", a.toString(), a.NOT().toString());
	printf("NOT %s = %s\n", b.toString(), b.NOT().toString());
	printf("NOT %s = %s\n\n", c.toString(), c.NOT().toString());

	// Test OR operation.
	printf("%s OR %s = %s\n", a.toString(), a.toString(), a.OR(a).toString());
	printf("%s OR %s = %s\n", a.toString(), b.toString(), a.OR(b).toString());
	printf("%s OR %s = %s\n", a.toString(), c.toString(), a.OR(c).toString());
	printf("%s OR %s = %s\n", b.toString(), b.toString(), b.OR(b).toString());
	printf("%s OR %s = %s\n", b.toString(), c.toString(), b.OR(c).toString());
	printf("%s OR %s = %s\n\n", c.toString(), c.toString(), c.OR(c).toString());

	// Test AND operation.
	printf("%s AND %s = %s\n", a.toString(), a.toString(), a.AND(a).toString());
	printf("%s AND %s = %s\n", a.toString(), b.toString(), a.AND(b).toString());
	printf("%s AND %s = %s\n", a.toString(), c.toString(), a.AND(c).toString());
	printf("%s AND %s = %s\n", b.toString(), b.toString(), b.AND(b).toString());
	printf("%s AND %s = %s\n", b.toString(), c.toString(), b.AND(c).toString());
	printf("%s AND %s = %s\n\n", c.toString(), c.toString(), c.AND(c).toString());

	printf("... end of tests\n\n");
}

int main()
{
	// Execute the tests.
	test();

	return 0;
}
