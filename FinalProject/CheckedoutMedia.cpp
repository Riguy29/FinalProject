#include "CheckedoutMedia.h"

void CheckedoutMedia::ReturnMedia()
{
}

void CheckedoutMedia::SetFee(double fee)
{
    lateFee = fee;
}

double CheckedoutMedia::GetFee()
{
    return 0.0;
}

void CheckedoutMedia::SetCheckoutDate(Date currDate)
{
    checkoutDate = currDate;
}

Date CheckedoutMedia::GetCheckoutDate()
{
    return checkoutDate;
}

void CheckedoutMedia::SetDueDate(Date dueDate)
{
    this->dueDate = dueDate;
}

Date CheckedoutMedia::GetDueDate()
{
    return dueDate;
}
