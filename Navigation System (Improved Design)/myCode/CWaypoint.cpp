/*
 * CWaypoint.cpp
 *
 *  Created on: 19.10.2017
 *      Author: Fabian Alexander Wilms
 */

#include "CWaypoint.h"

#include <cmath>
#include <iostream>

//#define SHOWADDRESS
//#define DEBUG
#define DEG2RAD M_PI/180

CWaypoint::CWaypoint(std::string name, double latitude, double longitude) {
	set(name, latitude, longitude);
	#ifdef SHOWADDRESS
		std::cout << "The address of the object: " << this << std::endl;
	#endif

	#ifdef DEBUG
		std::cout << "m_name: " << m_name << std::endl;
		std::cout << "m_latitude: " << m_latitude << std::endl;
		std::cout << "m_longitude: " << m_longitude << std::endl;

		std::cout << "size of name: " << sizeof(m_name) << std::endl;
		std::cout << "size of latitude: " << sizeof(m_latitude) << std::endl;
		std::cout << "size of longitude: " << sizeof(m_longitude) << std::endl;
	#endif
}

void CWaypoint::set(std::string name, double latitude, double longitude) {
	m_name = name;

	// ensure a valid latitude value
	if(-90 <= latitude && latitude <= 90) {
		m_latitude = latitude;
	} else {
		m_latitude = 0;
	}

	// ensure a valid longitude value
	if(-180 <= longitude && longitude <= 180) {
		m_longitude = longitude;
	} else {
		m_longitude = 0;
	}
}

std::string CWaypoint::getName() const {
	return m_name;
}

double CWaypoint::getLatitude() const {
	return m_latitude;
}

double CWaypoint::getLongitude() const {
	return m_longitude;
}

void CWaypoint::getAllDataByReference(std::string& name, double& latitude, double& longitude) {
	name = m_name;
	latitude = m_latitude;
	longitude = m_longitude;

	std::cout << "content of parameter \"name\": " << name << std::endl;
	std::cout << "address of parameter \"name\": " << &name << std::endl;
	std::cout << "content of parameter variable \"latitude\": " << latitude << std::endl;
	std::cout << "address of parameter variable \"latitude\": " << &latitude << std::endl;
	std::cout << "content of parameter variable \"longitude\": " << longitude << std::endl;
	std::cout << "address of parameter variable \"longitude\": " << &longitude << std::endl;
}

double CWaypoint::calculateDistance(const CWaypoint& wp) const {
	double R = 6378.17;
	return R*std::acos(std::sin(m_latitude*DEG2RAD)*std::sin(wp.getLatitude()*DEG2RAD)+
			std::cos(m_latitude*DEG2RAD)*std::cos(wp.getLatitude()*DEG2RAD)*std::cos(wp.getLongitude()*DEG2RAD-m_longitude*DEG2RAD));
}

void CWaypoint::print(int format) {
	if(format == DEGREE) {
		std::cout << m_name << " on latitude = " << m_latitude << " and longitude " << m_longitude << std::endl;
	} else if(format == MMSS) {
		// variable to store the angles return via call by reference
		int deg, mm;
		double ss;

		transformLatitude2degmmss(deg, mm, ss);
		std::cout << m_name << " on latitude = " << deg << "deg " << mm << "min " << ss << "s ";

		transformLongitude2degmmss(deg, mm, ss);
		std::cout << " and longitude = " << deg << "deg " << mm << "min " << ss << "s " << std::endl;
	}
}

void CWaypoint::transformLongitude2degmmss(int& deg, int& mm, double& ss) const {
	double longitude = m_longitude;

	// ignore decimal digits
	deg = (int) longitude;
	longitude -= deg;
	mm = (int) (longitude * 60);
	longitude -= mm / 60;
	ss = longitude * 3600;
}

void CWaypoint::transformLatitude2degmmss(int& deg, int& mm, double& ss) const {
	double latitude = m_latitude;

	// ignore decimal digits
	deg = (int) latitude;
	latitude -= deg;
	mm = (int) (latitude * 60);
	latitude -= mm / 60;
	ss = latitude * 3600;
}

// Hint:
// Die Übergabe von »const CWaypoint« als »this«-Argument streicht Qualifizierer
// means: used method must be const, since the argument os also const
std::ostream& operator<< (std::ostream& os, const CWaypoint& wp) {
	// variable to store the angles return via call by reference
	int deg, mm;
	double ss;

	// write contents of wp to stream
	wp.transformLatitude2degmmss(deg, mm, ss);
	os << wp.m_name << " on latitude = " << deg << "deg " << mm << "min " << ss << "s ";

	wp.transformLongitude2degmmss(deg, mm, ss);
	os << " and longitude = " << deg << "deg " << mm << "min " << ss << "s " << std::endl;

	return os;
}

CWaypoint::~CWaypoint() {
}
