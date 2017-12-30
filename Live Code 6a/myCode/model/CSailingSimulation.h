/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CSAILINGSIMULATION.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CSAILINGSIMULATION_H
#define CSAILINGSIMULATION_H
#include "CCaptain.h"
#include "CSailor.h"
#include "CDinghy.h"
#include "CLongboat.h"
#include "CCruiser.h"
class CSailingSimulation {
private:
    /**@link aggregationByValue
     * @supplierCardinality 1..**/
    CCaptain lnkCCaptain;
    /**@link aggregationByValue*/
    CSailor lnkCSailor;
    /**@link aggregationByValue*/
    CDinghy lnkCDinghy;
    /**@link aggregationByValue*/
    CLongboat lnkCLongboat;
    /**@link aggregationByValue*/
    CCruiser lnkCCruiser;
};
/********************
**  CLASS END
*********************/
#endif /* CSAILINGSIMULATION_H */
