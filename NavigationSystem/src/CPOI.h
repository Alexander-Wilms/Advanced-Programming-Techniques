/*
 * CPOI.h
 *
 *  Created on: 19.10.2017
 *      Author: awilms
 */

#ifndef CPOI_H_
#define CPOI_H_

#include "CWaypoint.h"
#include <string>

typedef enum {RESTAURANT, TOURISTIC, GASSTATION, UNIVERSITY} t_poi;

class CPOI : public CWaypoint {
public:
	void print();
	CPOI(t_poi type, std::string name, std::string description, double latitude, double longitude);
	void getAllDataByReference(std::string& name, double& latitude, double& longitude, t_poi& type, std::string& description);
private:
	t_poi m_type;
	std::string m_description;
};

#endif /* CPOI_H_ */
