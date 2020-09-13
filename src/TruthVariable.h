#ifndef TRUTHVARIABLE_H_
#define TRUTHVARIABLE_H_

#include <cstdint>
#include <map>
#include <string>

enum TruthValue {UNKNOWN, FALSE, TRUE};

class TruthVariable {
private:

	static uint32_t timePoint;

	std::map<uint32_t, TruthValue> truthValues;

public:

	static uint32_t getTimePoint();

	static void setTimePoint(uint32_t t);

	//

	TruthVariable();
	TruthVariable(TruthValue truthValue);
	TruthVariable(uint32_t t, TruthValue truthValue);
	~TruthVariable();

	void addTruthValue(uint32_t t, TruthValue truthValue);

	//

	TruthValue getTruthValue() const;

	//

	TruthVariable IDENTITY() const;

	TruthVariable NOT() const;

	TruthVariable OR(const TruthVariable& other) const;

	TruthVariable AND(const TruthVariable& other) const;

	//

	const std::string& toString() const;

};

#endif /* TRUTHVARIABLE_H_ */
