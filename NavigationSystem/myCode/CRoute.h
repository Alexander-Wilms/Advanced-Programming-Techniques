/*
 * CRoute.h
 *
 *  Created on: 20.10.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CROUTE_H_
#define CROUTE_H_

#include <string>

#include "CPoiDatabase.h"
#include "CPOI.h"

class CRoute {
public:
	CRoute(unsigned int maxWp, unsigned int maxPoi);
	// copy constructor
	CRoute(const CRoute& origin);
	~CRoute();
	void connectToPoiDatabase(CPoiDatabase* pPoiDB);
	void addWaypoint(std::string namePoi);
	void addPoi(std::string namePoi);
	double getDistanceNextPoi(const CWaypoint& wp, CPOI& poi);
	double getDistanceNextPoi(const CWaypoint& wp);
	void print();
private:
	CWaypoint* m_pWaypoint;
	unsigned int m_maxWp;
	unsigned int m_nextWp;
	CPOI** m_pPoi;
	unsigned int m_maxPoi;
	unsigned int m_nextPoi;
	CPoiDatabase* m_pPoiDatabase;
};

#endif /* CROUTE_H_ */
