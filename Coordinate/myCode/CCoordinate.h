/*
 * CCoordinate.h
 *
 *  Created on: 22.10.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CCOORDINATE_H_
#define CCOORDINATE_H_

typedef enum {CARTESIAN, CYLINDER, POLAR} t_coordinate;

class CCoordinate {
public:
	CCoordinate(float x = 0, float y = 0, float z = 0);
	~CCoordinate();
	void getCartesian(float& x, float& y, float& z);
	void setCartesian(float x, float y, float z);
	void add(CCoordinate c);
	void print(t_coordinate style);
private:
	float m_x;
	float m_y;
	float m_z;

	void getPolar(float& r, float& phi, float& theta);
	void getCylinder(float& r, float& phi, float& h);
};

#endif /* CCOORDINATE_H_ */
