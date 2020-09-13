#include "TruthVariable.h"

#include <algorithm>

uint32_t TruthVariable::timePoint = 0u;

uint32_t TruthVariable::getTimePoint()
{
	return timePoint;
}

void TruthVariable::setTimePoint(uint32_t t)
{
	timePoint = t;
}

//

TruthVariable::TruthVariable()
{
	truthValues[0] = UNKNOWN;
	truthValues[timePoint] = UNKNOWN;
}

TruthVariable::TruthVariable(TruthValue truthValue)
{
	truthValues[0] = UNKNOWN;
	truthValues[timePoint] = truthValue;
}

TruthVariable::TruthVariable(uint32_t t, TruthValue truthValue)
{
	truthValues[0] = UNKNOWN;
	truthValues[t] = truthValue;
}

TruthVariable::~TruthVariable()
{
}

void TruthVariable::addTruthValue(uint32_t t, TruthValue truthValue)
{
	truthValues[t] = truthValue;
}

//

TruthValue TruthVariable::getTruthValue() const
{
	TruthValue currentTruthValue = truthValues.at(0);

	for (const auto it : truthValues)
	{
		if (it.first > timePoint)
		{
			break;
		}
		currentTruthValue = it.second;
	}

	return currentTruthValue;
}

//

// see https://en.wikipedia.org/wiki/Law_of_identity
TruthVariable TruthVariable::IDENTITY() const
{
	TruthValue currentTruthValue = getTruthValue();

	return TruthVariable(timePoint, currentTruthValue);
}

// see https://en.wikipedia.org/wiki/Negation
TruthVariable TruthVariable::NOT() const
{
	// Note: Not unknown is either true or false, which is unknown again.
	static const TruthValue MappingTruthValues[3] = {UNKNOWN, TRUE, FALSE};

	TruthValue currentTruthValue = getTruthValue();

	TruthValue newTruthValue = MappingTruthValues[(int32_t)currentTruthValue];

	return TruthVariable(timePoint, newTruthValue);
}

// see https://en.wikipedia.org/wiki/Logical_disjunction
TruthVariable TruthVariable::OR(const TruthVariable& other) const
{
	TruthValue currentTruthValue = getTruthValue();
	TruthValue otherTruthValue = other.getTruthValue();

	TruthValue newTruthValue = (TruthValue)(std::max((int32_t)currentTruthValue, (int32_t)otherTruthValue));

	return TruthVariable(timePoint, newTruthValue);
}

// see https://en.wikipedia.org/wiki/Logical_conjunction
TruthVariable TruthVariable::AND(const TruthVariable& other) const
{
	TruthValue currentTruthValue = getTruthValue();
	TruthValue otherTruthValue = other.getTruthValue();

	TruthValue newTruthValue = (TruthValue)(std::min((int32_t)currentTruthValue, (int32_t)otherTruthValue));

	return TruthVariable(timePoint, newTruthValue);
}

//

const std::string& TruthVariable::toString() const
{
	static const std::string StringTruthValues[3] = {"UNKNOWN", "FALSE", "TRUE"};

	TruthValue currentTruthValue = getTruthValue();

	return StringTruthValues[(int32_t)currentTruthValue];
}
