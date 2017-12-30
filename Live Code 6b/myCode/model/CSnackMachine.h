/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CSNACKMACHINE.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CSNACKMACHINE_H
#define CSNACKMACHINE_H
#include "CTray.h"
#include "CDisplay.h"
#include "CKeyboard.h"
#include "CSnackArray.h"
#include "CPaymentSlot.h"
class CSnackMachine {
private:
    void checkPayment();
    /**@link aggregationByValue*/
    CTray m_tray;
    /**@link aggregationByValue*/
    CDisplay m_display;
    /**@link aggregationByValue*/
    CKeyboard m_keyboard;
    /**@link aggregationByValue*/
    CSnackArray m_snackArray;
    /**@link aggregationByValue*/
    CPaymentSlot m_paymentSlot;
public:


    void run();
};
/********************
**  CLASS END
*********************/
#endif /* CSNACKMACHINE_H */
