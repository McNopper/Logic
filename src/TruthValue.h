#ifndef TRUTHVALUE_H_
#define TRUTHVALUE_H_

#include <cstdint>
#include <map>
#include <string>

enum Values {UNKNOWN, FALSE, TRUE};

class TruthValue {
private:

	static uint32_t timePoint;

	std::map<uint32_t, Values> values;

public:

	static uint32_t getTimePoint();

	static void setTimePoint(uint32_t t);

	//

	TruthValue();
	TruthValue(Values value);
	TruthValue(uint32_t t, Values value);
	~TruthValue();

	void addValue(uint32_t t, Values value);

	//

	Values getValue() const;

	//

	TruthValue IDENTITY() const;

	TruthValue NOT() const;

	TruthValue OR(const TruthValue& other) const;

	TruthValue AND(const TruthValue& other) const;

	//

	const std::string& toString() const;

};

#endif /* TRUTHVALUE_H_ */
