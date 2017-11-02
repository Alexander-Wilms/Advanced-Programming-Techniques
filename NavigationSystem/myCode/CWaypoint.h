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
	explicit CWaypoint(std::string name = "myWaypoint", double latitude = 37, double longitude = 42);
	void set(std::string name, double latitude, double longitude);
	std::string getName();
	double getLatitude() const;
	double getLongitude() const;
	void getAllDataByReference(std::string& name, double& latitude, double& longitude);
	double calculateDistance(const CWaypoint& wp) const;
	void print(int format);

protected:
	/**
	 * The name of this waypoint
	 */
	std::string m_name;

	/**
	 * The waypoint's latitude
	 */
	double m_latitude;

	/**
	 * The waypoint's longitude
	 */
	double m_longitude;

private:
	void transformLongitude2degmmss(int& deg, int& mm, double& ss);
	void transformLatitude2degmmss(int& deg, int& mm, double& ss);
};

#endif /* CWAYPOINT_H_ */
