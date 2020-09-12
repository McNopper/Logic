#include "TruthValue.h"

#include <algorithm>

TruthValue::TruthValue()
{
	values[0] = UNKNOWN;
}

TruthValue::TruthValue(Values value)
{
	values[0] = value;
}

TruthValue::TruthValue(uint32_t t, Values value)
	: TruthValue()
{
	values[t] = value;
}

TruthValue::~TruthValue()
{
}

//

Values TruthValue::getValue(uint32_t t) const
{
	Values currentValue = values.at(0);

	for (const auto it : values)
	{
		if (it.first > t)
		{
			break;
		}
		currentValue = it.second;
	}

	return currentValue;
}

void TruthValue::setValue(uint32_t t, Values value)
{
	values[t] = value;
}

//

// see https://en.wikipedia.org/wiki/Law_of_identity
TruthValue TruthValue::IDENTITY(uint32_t t) const
{
	Values currentValue = getValue(t);

	return TruthValue(t, currentValue);
}

// see https://en.wikipedia.org/wiki/Negation
TruthValue TruthValue::NOT(uint32_t t) const
{
	// Note: Not unknown is either true or false, which is unknown again.
	static const Values MappingValues[3] = {UNKNOWN, TRUE, FALSE};

	Values currentValue = getValue(t);

	Values newValue = MappingValues[(int32_t)currentValue];

	return TruthValue(t, newValue);
}

// see https://en.wikipedia.org/wiki/Logical_disjunction
TruthValue TruthValue::OR(uint32_t t, const TruthValue& other) const
{
	Values currentValue = getValue(t);
	Values otherValue = other.getValue(t);

	Values newValue = (Values)(std::max((int32_t)currentValue, (int32_t)otherValue));

	return TruthValue(t, newValue);
}

// see https://en.wikipedia.org/wiki/Logical_conjunction
TruthValue TruthValue::AND(uint32_t t, const TruthValue& other) const
{
	Values currentValue = getValue(t);
	Values otherValue = other.getValue(t);

	Values newValue = (Values)(std::min((int32_t)currentValue, (int32_t)otherValue));

	return TruthValue(t, newValue);
}

//

const std::string& TruthValue::toString(uint32_t t) const
{
	static const std::string StringValues[3] = {"UNKNOWN", "FALSE", "TRUE"};

	Values currentValue = getValue(t);

	return StringValues[(int32_t)currentValue];
}
