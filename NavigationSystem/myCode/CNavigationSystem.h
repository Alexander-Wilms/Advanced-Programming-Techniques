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
#include "CRoute.h"

/**
 * The navigation system, which allows interacting with a route
 * and the GPS sensor
 */
class CNavigationSystem {
public:
	CNavigationSystem();
	void run();
private:
	CGPSSensor m_GPSSensor;
	CRoute m_route;
	CPoiDatabase m_PoiDatabase;

	// testcases
	void addPOIsToDatabase();
	void enterRoute();
	void printRoute();
	void printDistanceCurPosNextPoi();
};

#endif /* CNAVIGATIONSYSTEM_H_ */
