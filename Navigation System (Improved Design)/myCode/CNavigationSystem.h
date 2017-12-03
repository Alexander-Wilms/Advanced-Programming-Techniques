/*
 * CNavigationSystem.h
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CNAVIGATIONSYSTEM_H_
#define CNAVIGATIONSYSTEM_H_

#include "CGPSSensor.h"
#include "CPoiDatabase.h"
#include "CWpDatabase.h"
#include "CRoute.h"

/**
 * The navigation system, which allows interacting with a route
 * and the GPS sensor
 */
class CNavigationSystem {
public:
	/**
	 * Constructor of CNavigationSystem
	 *
	 * calls the constructor of the member m_route, otherwise
	 * a constructor CRoute::CRoute() without arguments is required
	 *
	 * m_PoiDatabase() is initialized like this, since cppcheck suggested it for performance reasons
	 */
	CNavigationSystem();

	/**
	 * Starts the navigation system
	 */
	void run();
private:
	/**
	 * The navigation system's GPS sensor
	 */
	CGPSSensor m_GPSSensor;

	/**
	 * A model of a route that should be traveled
	 */
	CRoute m_route;

	/**
	 * A database of all known POIs
	 */
	CPoiDatabase m_PoiDatabase;

	/**
	 * A database of all known Waypoints
	 */
	CWpDatabase m_WpDatabase;

	/**
	 * test cases
	 */
	void addPOIsAndWpsToDatabase();

	/**
	 * Allows the user to enter coordinates for waypoints and POIs of the given route
	 */
	void enterRoute();

	/**
	 * Wrapper method to print all waypoints and POIs of the route
	 */
	void printRoute();

	/**
	 * Requests the current location from the GPS sensor and prints the
	 * distance to the next POI of the route
	 */
	void printDistanceCurPosNextPoi();
};

#endif /* CNAVIGATIONSYSTEM_H_ */
