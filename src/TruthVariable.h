#ifndef TRUTHVARIABLE_H_
#define TRUTHVARIABLE_H_

#include <cstdint>
#include <map>
#include <string>

enum TruthValue {FALSE = - 1, UNKNOWN = 0, TRUE = 1};

class TruthVariable {
private:

	/**
	 * The current time point for all truth variables. Can be changed to evaluate truth values at different time points.
	 */
	static uint32_t timePoint;

	/**
	 * Mapping of time point and given truth value. Always contains at least time point 0 with the truth value unknown.
	 */
	std::map<uint32_t, TruthValue> truthValues;

public:

	/**
	 * Returns the current and global time point.
	 *
	 * @return time point
	 */
	static uint32_t getTimePoint();

	/**
	 * Sets the current and global time point.
	 *
	 * @param t The new global time point
	 */
	static void setTimePoint(uint32_t t);

	//

	/**
	 * Using time point 0 and truth value unknown.
	 */
	TruthVariable();

	/**
	 * Using time point 0 with a given truth value.
	 *
	 * @param truthValue The truth value at time point 0
	 */
	TruthVariable(TruthValue truthValue);

	/**
	 * Using time point t with a given truth value.
	 * Time point 0 and truth value unknown is also set.
	 *
	 * @param t          The used time point
	 * @param truthValue The truth value at given time point
	 */
	TruthVariable(uint32_t t, TruthValue truthValue);

	~TruthVariable();

	/**
	 * Add truth value at given time point.
	 * Existing value is overwritten.
	 *
	 * @param t          The used time point
	 * @param truthValue The truth value at given time point
	 */
	void addTruthValue(uint32_t t, TruthValue truthValue);

	/**
	 * Removes a truth value at given time point.
	 * If the time point does not exist, the function does not fail.
	 *
	 * @param t          The used time point
	 */
	void removeTruthValue(uint32_t t);

	//

	/**
	 * Returns the truth value from the global set time point.
	 * If not present, the latest truth value is returned.
	 * If not truth value has been set, this is the unknown truth value.
	 *
	 * @return TruthValue The truth value gathered from the global time point
	 */
	TruthValue getTruthValue() const;

	//

	/**
	 * Identity IDENTITY
     * https://en.wikipedia.org/wiki/Law_of_identity
	 *
	 * @return TruthVariable Result of the identity operation
	 */
	TruthVariable IDENTITY() const;

	/**
	 * Negation NOT
     * https://en.wikipedia.org/wiki/Negation
	 *
	 * @return TruthVariable Result of the identity operation
	 */
	TruthVariable NOT() const;

	/**
	 * Disjunction OR
     * https://en.wikipedia.org/wiki/Logical_disjunction
	 *
	 * @param other The other truth variable
	 *
	 * @return TruthVariable Result of the identity operation
	 */
	TruthVariable OR(const TruthVariable& other) const;

	/**
	 * Conjunction AND
	 * https://en.wikipedia.org/wiki/Logical_conjunction
	 *
	 * @param other The other truth variable
	 *
	 * @return TruthVariable Result of the identity operation
	 */
	TruthVariable AND(const TruthVariable& other) const;

	//

	/**
	 * Returns a human readable string.
	 *
	 * @return const char* Human readable string.
	 */
	const char* toString() const;

};

#endif /* TRUTHVARIABLE_H_ */
