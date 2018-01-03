#include "CCircle.h"
#include "CCoordinate.h"
#include "CPlane.h"
#include "CRectangle.h"
#include "CTriangle.h"

#include <iostream>
#include <stdlib.h>

int main(void) {
	// Overall test result
	bool failed = false;

	GraSys::CCoordinate coord(37, 42);
	coord.move(-1, 2);
	if (!(coord.getX() == 36 && coord.getY() == 44)) {
		std::cout << "Testcase move coordinate failed" << std::endl;
		failed = true;
	}

	GraSys::CCoordinate trianglecorner1(0, 0);
	GraSys::CCoordinate trianglecorner2(3, 7);
	GraSys::CCoordinate trianglecorner3(37, 42);
	GraSys::CTriangle triangle("blue", trianglecorner1, trianglecorner2,
			trianglecorner3);
	triangle.move(1, 2);
	if (!(triangle.getCoordinate(0) == GraSys::CCoordinate(1, 2)
			&& triangle.getCoordinate(1) == GraSys::CCoordinate(4, 9)
			&& triangle.getCoordinate(2) == GraSys::CCoordinate(38, 44))) {
		std::cout << "Testcase move triangle failed" << std::endl;
		failed = true;
	}

	GraSys::CCoordinate corner1(0, 0);
	GraSys::CCoordinate corner2(37, 42);
	GraSys::CRectangle rectangle("black", corner1, corner2);
	rectangle.move(1, 2);

	if (!(rectangle
			== GraSys::CRectangle("black", GraSys::CCoordinate(1, 2),
					GraSys::CCoordinate(38, 44)))) {
		std::cout << "Testcase move rectangle failed" << std::endl;
		failed = true;
	}

	GraSys::CCircle circle("red");
	GraSys::CCoordinate center(10, 10);
	circle.setCenter(center);
	circle.setRadius(5);
	circle.move(1, 2);

	if (!(circle == GraSys::CCircle("red", GraSys::CCoordinate(11, 12), 5))) {
		std::cout << "Testcase move circle failed" << std::endl;
		failed = true;
	}

	GraSys::CPlane plane;

	plane.addElement(triangle);
	plane.printScreen();
	GraSys::CRectangle boundingbox = plane.boundingBox("", "");
	boundingbox.print();

	plane.addElement(rectangle);
	boundingbox = plane.boundingBox("", "");
	boundingbox.print();

	plane.addElement(circle);
	boundingbox = plane.boundingBox("", "");
	boundingbox.print();

	// Finally output overall result
	if (failed) {
		std::cout << "Some test cases failed" << std::endl;
	} else {
		std::cout << "All test cases completed successfully" << std::endl;
	}

	return 0;
}
