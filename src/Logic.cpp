#include <cstdio>

#include "TruthVariable.h"

void test()
{
	printf("Start of tests ...\n\n");

	TruthVariable a(TRUE);
	TruthVariable b(UNKNOWN);
	TruthVariable c(FALSE);

	// Test correct lookup of string.
	printf("TRUE = %s\n", a.toString().c_str());
	printf("UNKNOWN = %s\n", b.toString().c_str());
	printf("FALSE = %s\n\n", c.toString().c_str());

	// Test IDENTITY operation.
	printf("IDENTITY %s = %s\n", a.toString().c_str(), a.IDENTITY().toString().c_str());
	printf("IDENTITY %s = %s\n", b.toString().c_str(), b.IDENTITY().toString().c_str());
	printf("IDENTITY %s = %s\n\n", c.toString().c_str(), c.IDENTITY().toString().c_str());

	// Test NOT operation.
	printf("NOT %s = %s\n", a.toString().c_str(), a.NOT().toString().c_str());
	printf("NOT %s = %s\n", b.toString().c_str(), b.NOT().toString().c_str());
	printf("NOT %s = %s\n\n", c.toString().c_str(), c.NOT().toString().c_str());

	// Test OR operation.
	printf("%s OR %s = %s\n", a.toString().c_str(), a.toString().c_str(), a.OR(a).toString().c_str());
	printf("%s OR %s = %s\n", a.toString().c_str(), b.toString().c_str(), a.OR(b).toString().c_str());
	printf("%s OR %s = %s\n", a.toString().c_str(), c.toString().c_str(), a.OR(c).toString().c_str());
	printf("%s OR %s = %s\n", b.toString().c_str(), b.toString().c_str(), b.OR(b).toString().c_str());
	printf("%s OR %s = %s\n", b.toString().c_str(), c.toString().c_str(), b.OR(c).toString().c_str());
	printf("%s OR %s = %s\n\n", c.toString().c_str(), c.toString().c_str(), c.OR(c).toString().c_str());

	// Test AND operation.
	printf("%s AND %s = %s\n", a.toString().c_str(), a.toString().c_str(), a.AND(a).toString().c_str());
	printf("%s AND %s = %s\n", a.toString().c_str(), b.toString().c_str(), a.AND(b).toString().c_str());
	printf("%s AND %s = %s\n", a.toString().c_str(), c.toString().c_str(), a.AND(c).toString().c_str());
	printf("%s AND %s = %s\n", b.toString().c_str(), b.toString().c_str(), b.AND(b).toString().c_str());
	printf("%s AND %s = %s\n", b.toString().c_str(), c.toString().c_str(), b.AND(c).toString().c_str());
	printf("%s AND %s = %s\n\n", c.toString().c_str(), c.toString().c_str(), c.AND(c).toString().c_str());

	printf("... end of tests\n\n");
}

int main()
{
	// Execute the tests.
	test();

	return 0;
}
