#include "atmparams.h"

ATMParams::ATMParams(const size_t atm_id, const size_t bank_id, const QString &bank_name,
                     const bool busy, const bool ready, const long money, const QString lang):
    atm_id_(atm_id),
    bank_id_(bank_id),
    bank_name_(bank_name),
    busy_(busy),
    ready_(ready),
    money_(money),
    language_(lang)
{

}
