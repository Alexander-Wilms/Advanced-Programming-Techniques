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

#include <iostream>
#include <string>

class CWaypoint {
public:
	/**
	 * Constructor
	 *
	 * @param name			The waypoint's name
	 * @param latitude 		The waypoint's latitude
	 * @param longitude 	The waypoint's longitude
	 */
	explicit CWaypoint(std::string name = "myWaypoint", double latitude = 37, double longitude = 42);

	virtual ~CWaypoint();

	/**
	 * Sets the waypoint's properties
	 *
	 * @param name 			The waypoint's name
	 * @param latitude 		The waypoint's latitude
	 * @param longitude 	The waypoint's longitude
	 */
	void set(std::string name, double latitude, double longitude);

	/**
	 * Returns the waypoint's name
	 *
	 * @return The name
	 */
	std::string getName() const;

	/**
	 * Returns the waypoint's latitude
	 *
	 * @return The latitude
	 */
	double getLatitude() const;

	/*
	 * Return the waypoint's longitude
	 *
	 * @return The longitude
	 */
	double getLongitude() const;

	/**
	 * Returns all properties of the waypoint by reference
	 *
	 * @param name 			The variable where to store the name
	 * @param latitude 		The variable where to store the latitude
	 * @param longitude 	The variable where to store the longitude
	 */
	void getAllDataByReference(std::string& name, double& latitude, double& longitude);

	/**
	 * Calculates the distance between this CWaypoint instance and another
	 *
	 * @param wp 	The other waypoint
	 *
	 * @return	 	The distance between both waypoints
	 */
	double calculateDistance(const CWaypoint& wp) const;

	/**
	 * Prints the waypoint
	 *
	 * @param format 	The format used to print the coordinate (DEGREE or MMSS)
	 */
	void print(int format);

	/**
	 * Transforms longitude into degrees, minutes and seconds
	 *
	 * @param deg 	variable where to store the degrees
	 * @param mm 	variable where to store the minutes
	 * @param ss 	variable where to store the seconds
	 */
	void transformLongitude2degmmss(int& deg, int& mm, double& ss) const;

	/**
	 * Transforms latitude into degrees, minutes and seconds
	 *
	 * @param deg 	variable where to store the degrees
	 * @param mm 	variable where to store the minutes
	 * @param ss 	variable where to store the seconds
	 */
	void transformLatitude2degmmss(int& deg, int& mm, double& ss) const;

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

	/**
	 * output operator
	 */
	friend std::ostream& operator<< (std::ostream& os, const CWaypoint& wp);
};

#endif /* CWAYPOINT_H_ */
