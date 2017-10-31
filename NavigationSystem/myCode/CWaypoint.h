/*
 * CWaypint.h
 *
 *  Created on: 19.10.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_

#define DEGREE 1
#define MMSS 2

#include <string>

class CWaypoint {
public:
	CWaypoint(std::string name = "myWaypoint", double latitude = 37, double longitude = 42);
	void set(std::string name, double latitude, double longitude);
	std::string getName() const;
	double getLatitude() const;
	double getLongitude() const;
	void getAllDataByReference(std::string& name, double& latitude, double& longitude);
	double calculateDistance(const CWaypoint& wp) const;
	void print(int format);
	virtual ~CWaypoint();

protected:
	std::string m_name;
	double m_latitude;
	double m_longitude;

private:
	void transformLongitude2degmmss(int& deg, int& mm, double& ss);
	void transformLatitude2degmmss(int& deg, int& mm, double& ss);
};

#endif /* CWAYPOINT_H_ */
