#include <cstdio>

#include "TruthValue.h"

void test()
{
	printf("Start of tests ...\n\n");

	uint32_t t = 0;

	TruthValue a(t, UNKNOWN);
	TruthValue b(t, FALSE);
	TruthValue c(t, TRUE);

	printf("UNKNOWN = %s\n", a.toString(t).c_str());
	printf("FALSE = %s\n", b.toString(t).c_str());
	printf("TRUE = %s\n\n", c.toString(t).c_str());

	printf("IDENTITY %s = %s\n", a.toString(t).c_str(), a.IDENTITY(t).toString(t).c_str());
	printf("IDENTITY %s = %s\n", b.toString(t).c_str(), b.IDENTITY(t).toString(t).c_str());
	printf("IDENTITY %s = %s\n\n", c.toString(t).c_str(), c.IDENTITY(t).toString(t).c_str());

	printf("NOT %s = %s\n", a.toString(t).c_str(), a.NOT(t).toString(t).c_str());
	printf("NOT %s = %s\n", b.toString(t).c_str(), b.NOT(t).toString(t).c_str());
	printf("NOT %s = %s\n\n", c.toString(t).c_str(), c.NOT(t).toString(t).c_str());

	printf("%s OR %s = %s\n", a.toString(t).c_str(), b.toString(t).c_str(), a.OR(t, b).toString(t).c_str());
	printf("%s OR %s = %s\n", a.toString(t).c_str(), c.toString(t).c_str(), a.OR(t, c).toString(t).c_str());
	printf("%s OR %s = %s\n\n", b.toString(t).c_str(), c.toString(t).c_str(), b.OR(t, c).toString(t).c_str());

	printf("%s AND %s = %s\n", a.toString(t).c_str(), b.toString(t).c_str(), a.AND(t, b).toString(t).c_str());
	printf("%s AND %s = %s\n", a.toString(t).c_str(), c.toString(t).c_str(), a.AND(t, c).toString(t).c_str());
	printf("%s AND %s = %s\n\n", b.toString(t).c_str(), c.toString(t).c_str(), b.AND(t, c).toString(t).c_str());

	printf("... end of tests\n\n");
}

int main()
{
	// For testing only.
	test();

	//
	// Setting up flipping coin test case.
	//

	// Time point 0: Start of the experiment and before flipping the coin.
	uint32_t t = 0;
	TruthValue coinFlipped(t, UNKNOWN);
	TruthValue coinVisibleToObserver(t, FALSE);
	TruthValue coinVisibleToFlipper(t, FALSE);

	// Time point 1: Coin is flipped and catched.
	t++;
	//coinFlipped.setValue(t, UNKNOWN);
	//coinFlipped.setValue(t, FALSE);
	coinFlipped.setValue(t, TRUE);

	// Time point 2: Coin is uncovered to observing person.
	t++;
	coinVisibleToObserver.setValue(t, TRUE);

	// Time point 3: Coin is uncovered to flipping person.
	t++;
	coinVisibleToFlipper.setValue(t, TRUE);

	//
	// Evaluation.
	//
	printf("Start of experiment ...\n\n");

	t = 0;
	printf("Before flipping the coin:\n");
	printf("Coin is flipped and catched? %s\n", coinFlipped.toString(t).c_str());
	auto observerAtStart = coinVisibleToObserver.AND(t, coinFlipped);
	printf("Does the observer know, if heads is up or not? %s\n", observerAtStart.toString(t).c_str());
	auto flipperAtStart = coinVisibleToFlipper.AND(t, coinFlipped);
	printf("Does the flipper know, if heads is up or not? %s\n\n", flipperAtStart.toString(t).c_str());

	t = 1;
	printf("Coin is flipped and catched:\n");
	printf("Coin is flipped and catched? %s\n", coinFlipped.toString(t).c_str());

	// Further evaluation only makes sense, if coin is flipped.
	if (coinFlipped.getValue(t) == TRUE)
	{
		auto observerAfterCatch = coinVisibleToObserver.AND(t, coinFlipped);
		printf("Does the observer know, if heads is up or not? %s\n", observerAfterCatch.toString(t).c_str());
		auto flipperAfterCatch = coinVisibleToFlipper.AND(t, coinFlipped);
		printf("Does the flipper know, if heads is up or not? %s\n\n", flipperAfterCatch.toString(t).c_str());

		t = 2;
		printf("Coin is uncovered to the observer:\n");
		printf("Coin is flipped and catched? %s\n", coinFlipped.toString(t).c_str());
		auto observerAfterUncover = coinVisibleToObserver.AND(t, coinFlipped);
		printf("Does the observer know, if heads is up or not? %s\n", observerAfterUncover.toString(t).c_str());
		auto flipperAfterUncover = coinVisibleToFlipper.AND(t, coinFlipped);
		printf("Does the flipper know, if heads is up or not? %s\n\n", flipperAfterUncover.toString(t).c_str());

		t = 3;
		printf("Coin is uncovered to the flipper:\n");
		printf("Coin is flipped and catched? %s\n", coinFlipped.toString(t).c_str());
		auto observerAfterOwnUncover = coinVisibleToObserver.AND(t, coinFlipped);
		printf("Does the observer know, if heads is up or not? %s\n", observerAfterOwnUncover.toString(t).c_str());
		auto flipperAfterOwnUncover = coinVisibleToFlipper.AND(t, coinFlipped);
		printf("Does the flipper know, if heads is up or not? %s\n", flipperAfterOwnUncover.toString(t).c_str());
	}
	else
	{
		printf(" Not evaluated in this experiment. \n");
	}

	printf("\n... end of experiment.\n");

	return 0;
}
