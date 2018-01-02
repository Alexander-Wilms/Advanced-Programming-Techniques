/*
 * CSetOfMeasurementValues.h
 *
 *  Created on: 22.10.2017
 *      Author: awilms
 */

#ifndef CSETOFMEASUREMENTVALUES_H_
#define CSETOFMEASUREMENTVALUES_H_

#include <string>

typedef enum {A, V, S, W, NONE} t_unit;

#define MAXVALUE 10
#define NOVALUE -9999

class CSetOfMeasurementValues {
public:
	CSetOfMeasurementValues(std::string name = "unnamed", t_unit unit = NONE);
	void setValue(unsigned int pos, double value);
	void setRandomValues(int min, int max);
	void print();
	double getValue(unsigned int pos);
	double getAverage();
	double getMax();
	double getMin();
private:
	double m_value[10];
	t_unit m_unit;
	std::string m_name;

	void printSingleValue(unsigned int pos);
};

#endif /* CSETOFMEASUREMENTVALUES_H_ */
