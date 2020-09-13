#include "TruthValue.h"

#include <algorithm>

uint32_t TruthValue::timePoint = 0u;

uint32_t TruthValue::getTimePoint()
{
	return timePoint;
}

void TruthValue::setTimePoint(uint32_t t)
{
	timePoint = t;
}

//

TruthValue::TruthValue()
{
	values[0] = UNKNOWN;
	values[timePoint] = UNKNOWN;
}

TruthValue::TruthValue(Values value)
{
	values[0] = UNKNOWN;
	values[timePoint] = value;
}

TruthValue::TruthValue(uint32_t t, Values value)
{
	values[0] = UNKNOWN;
	values[t] = value;
}

TruthValue::~TruthValue()
{
}

void TruthValue::addValue(uint32_t t, Values value)
{
	values[t] = value;
}

//

Values TruthValue::getValue() const
{
	Values currentValue = values.at(0);

	for (const auto it : values)
	{
		if (it.first > timePoint)
		{
			break;
		}
		currentValue = it.second;
	}

	return currentValue;
}

//

// see https://en.wikipedia.org/wiki/Law_of_identity
TruthValue TruthValue::IDENTITY() const
{
	Values currentValue = getValue();

	return TruthValue(timePoint, currentValue);
}

// see https://en.wikipedia.org/wiki/Negation
TruthValue TruthValue::NOT() const
{
	// Note: Not unknown is either true or false, which is unknown again.
	static const Values MappingValues[3] = {UNKNOWN, TRUE, FALSE};

	Values currentValue = getValue();

	Values newValue = MappingValues[(int32_t)currentValue];

	return TruthValue(timePoint, newValue);
}

// see https://en.wikipedia.org/wiki/Logical_disjunction
TruthValue TruthValue::OR(const TruthValue& other) const
{
	Values currentValue = getValue();
	Values otherValue = other.getValue();

	Values newValue = (Values)(std::max((int32_t)currentValue, (int32_t)otherValue));

	return TruthValue(timePoint, newValue);
}

// see https://en.wikipedia.org/wiki/Logical_conjunction
TruthValue TruthValue::AND(const TruthValue& other) const
{
	Values currentValue = getValue();
	Values otherValue = other.getValue();

	Values newValue = (Values)(std::min((int32_t)currentValue, (int32_t)otherValue));

	return TruthValue(timePoint, newValue);
}

//

const std::string& TruthValue::toString() const
{
	static const std::string StringValues[3] = {"UNKNOWN", "FALSE", "TRUE"};

	Values currentValue = getValue();

	return StringValues[(int32_t)currentValue];
}
