/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : LIDAR.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef LIDAR_H
#define LIDAR_H
#include "CMeasurementValue.h"
#include "CUart.h"

/** @interface */
class Lidar {

    private:
        /**
         * @link aggregationByValue
         * @clientCardinality 1
         * @supplierCardinality 1..* 
         */
        CMeasurementValue * m_pScan;
        /**@link association*/
        CUart m_CUart;
};
/********************
**  CLASS END
*********************/
#endif /* LIDAR_H */
