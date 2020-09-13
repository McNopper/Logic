#include <cstdio>

#include "TruthValue.h"

void test()
{
	printf("Start of tests ...\n\n");

	TruthValue a(UNKNOWN);
	TruthValue b(FALSE);
	TruthValue c(TRUE);

	printf("UNKNOWN = %s\n", a.toString().c_str());
	printf("FALSE = %s\n", b.toString().c_str());
	printf("TRUE = %s\n\n", c.toString().c_str());

	printf("IDENTITY %s = %s\n", a.toString().c_str(), a.IDENTITY().toString().c_str());
	printf("IDENTITY %s = %s\n", b.toString().c_str(), b.IDENTITY().toString().c_str());
	printf("IDENTITY %s = %s\n\n", c.toString().c_str(), c.IDENTITY().toString().c_str());

	printf("NOT %s = %s\n", a.toString().c_str(), a.NOT().toString().c_str());
	printf("NOT %s = %s\n", b.toString().c_str(), b.NOT().toString().c_str());
	printf("NOT %s = %s\n\n", c.toString().c_str(), c.NOT().toString().c_str());

	printf("%s OR %s = %s\n", a.toString().c_str(), b.toString().c_str(), a.OR(b).toString().c_str());
	printf("%s OR %s = %s\n", a.toString().c_str(), c.toString().c_str(), a.OR(c).toString().c_str());
	printf("%s OR %s = %s\n\n", b.toString().c_str(), c.toString().c_str(), b.OR(c).toString().c_str());

	printf("%s AND %s = %s\n", a.toString().c_str(), b.toString().c_str(), a.AND(b).toString().c_str());
	printf("%s AND %s = %s\n", a.toString().c_str(), c.toString().c_str(), a.AND(c).toString().c_str());
	printf("%s AND %s = %s\n\n", b.toString().c_str(), c.toString().c_str(), b.AND(c).toString().c_str());

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
	//coinFlipped.addValue(t, UNKNOWN);
	//coinFlipped.addValue(t, FALSE);
	coinFlipped.addValue(t, TRUE);

	// Time point 2: Coin is uncovered to observing person.
	t++;
	coinVisibleToObserver.addValue(t, TRUE);

	// Time point 3: Coin is uncovered to flipping person.
	t++;
	coinVisibleToFlipper.addValue(t, TRUE);

	//
	// Evaluation.
	//
	printf("Start of experiment ...\n\n");

	t = 0;
	TruthValue::setTimePoint(t);
	printf("Before flipping the coin:\n");
	printf("Coin is flipped and catched? %s\n", coinFlipped.toString().c_str());
	auto observerAtStart = coinVisibleToObserver.AND(coinFlipped);
	printf("Does the observer know, if heads is up or not? %s\n", observerAtStart.toString().c_str());
	auto flipperAtStart = coinVisibleToFlipper.AND(coinFlipped);
	printf("Does the flipper know, if heads is up or not? %s\n\n", flipperAtStart.toString().c_str());

	t = 1;
	TruthValue::setTimePoint(t);
	printf("Coin is flipped and catched:\n");
	printf("Coin is flipped and catched? %s\n", coinFlipped.toString().c_str());

	// Further evaluation only makes sense, if coin is flipped.
	if (coinFlipped.getValue() == TRUE)
	{
		auto observerAfterCatch = coinVisibleToObserver.AND(coinFlipped);
		printf("Does the observer know, if heads is up or not? %s\n", observerAfterCatch.toString().c_str());
		auto flipperAfterCatch = coinVisibleToFlipper.AND(coinFlipped);
		printf("Does the flipper know, if heads is up or not? %s\n\n", flipperAfterCatch.toString().c_str());

		t = 2;
		TruthValue::setTimePoint(t);
		printf("Coin is uncovered to the observer:\n");
		printf("Coin is flipped and catched? %s\n", coinFlipped.toString().c_str());
		auto observerAfterUncover = coinVisibleToObserver.AND(coinFlipped);
		printf("Does the observer know, if heads is up or not? %s\n", observerAfterUncover.toString().c_str());
		auto flipperAfterUncover = coinVisibleToFlipper.AND(coinFlipped);
		printf("Does the flipper know, if heads is up or not? %s\n\n", flipperAfterUncover.toString().c_str());

		t = 3;
		TruthValue::setTimePoint(t);
		printf("Coin is uncovered to the flipper:\n");
		printf("Coin is flipped and catched? %s\n", coinFlipped.toString().c_str());
		auto observerAfterOwnUncover = coinVisibleToObserver.AND(coinFlipped);
		printf("Does the observer know, if heads is up or not? %s\n", observerAfterOwnUncover.toString().c_str());
		auto flipperAfterOwnUncover = coinVisibleToFlipper.AND(coinFlipped);
		printf("Does the flipper know, if heads is up or not? %s\n", flipperAfterOwnUncover.toString().c_str());
	}
	else
	{
		printf(" Not evaluated in this experiment. \n");
	}

	printf("\n... end of experiment.\n");

	return 0;
}
