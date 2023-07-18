#include <iostream>
#include "account.h"
#include "node.h"

enum STATUS{BOOKED, NOACCEESS, SUCCESS, FULL};

STATUS Booking_court_time(Court_node &court_node, int time)
{
    Time_node *p = nullptr;
    if(court_node.Get_can_be_order())
    {
        if(!court_node.Is_full())
        {
            for(p = court_node.Get_first_time_node(); p = p->Show_Next_Time_node(); p != nullptr)
            {
                if(p->Show_Can_be_order())
                {
                    if(!p->Show_IS_ordered())
                    {
                        p->Change_order_status(true);
                        return SUCCESS;
                    }
                    else
                    return BOOKED;
                }
                else
                return NOACCEESS;
            }
        }
        else
        return FULL;
    }
    else
    return NOACCEESS;
}

void Show_free_court()
{
    

}