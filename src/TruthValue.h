#ifndef TRUTHVALUE_H_
#define TRUTHVALUE_H_

#include <cstdint>
#include <map>
#include <string>

enum Values {UNKNOWN, FALSE, TRUE};

class TruthValue {
private:

	std::map<uint32_t, Values> values;

public:

	TruthValue();
	TruthValue(Values value);
	TruthValue(uint32_t t, Values value);
	~TruthValue();

	//

	Values getValue(uint32_t t) const;

	void setValue(uint32_t t, Values value);

	//

	TruthValue IDENTITY(uint32_t t) const;

	TruthValue NOT(uint32_t t) const;

	TruthValue OR(uint32_t t, const TruthValue& other) const;

	TruthValue AND(uint32_t t, const TruthValue& other) const;

	//

	const std::string& toString(uint32_t t) const;

};

#endif /* TRUTHVALUE_H_ */
