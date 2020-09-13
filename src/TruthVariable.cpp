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

void TruthVariable::removeTruthValue(uint32_t t)
{
	auto it = truthValues.find(t);
	if (it != truthValues.end())
	{
		truthValues.erase(it);
	}
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

TruthVariable TruthVariable::IDENTITY() const
{
	TruthValue currentTruthValue = getTruthValue();

	return TruthVariable(timePoint, currentTruthValue);
}

TruthVariable TruthVariable::NOT() const
{
	TruthValue currentTruthValue = getTruthValue();

	TruthValue newTruthValue = (TruthValue)-(int32_t)currentTruthValue;

	return TruthVariable(timePoint, newTruthValue);
}

TruthVariable TruthVariable::OR(const TruthVariable& other) const
{
	TruthValue currentTruthValue = getTruthValue();
	TruthValue otherTruthValue = other.getTruthValue();

	TruthValue newTruthValue = (TruthValue)(std::max((int32_t)currentTruthValue, (int32_t)otherTruthValue));

	return TruthVariable(timePoint, newTruthValue);
}

TruthVariable TruthVariable::AND(const TruthVariable& other) const
{
	TruthValue currentTruthValue = getTruthValue();
	TruthValue otherTruthValue = other.getTruthValue();

	TruthValue newTruthValue = (TruthValue)(std::min((int32_t)currentTruthValue, (int32_t)otherTruthValue));

	return TruthVariable(timePoint, newTruthValue);
}

//

const char* TruthVariable::toString() const
{
	static const std::string StringTruthValues[3] = {"FALSE", "UNKNOWN", "TRUE"};

	TruthValue currentTruthValue = getTruthValue();

	return StringTruthValues[(int32_t)currentTruthValue + 1].c_str();
}
