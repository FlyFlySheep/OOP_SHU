#include <iostream>
#include "account.h"
#include "node.h"

enum STATUS{BOOKED, NOACCEESS, SUCCESS, FULL};

STATUS Booking_court_time(Court_node &court_node, int time, Account &acco, bool can_order)
{
    Time_node *p = nullptr;
    
    if(can_order)
    {
        if(!court_node.Is_full())
        {
            p = court_node.Get_first_time_node();
            if(p == nullptr)
            {
                Time_node* q = new Time_node(time, acco, nullptr);
                p = q;
            }
            else
            {
                for(; p = p->Show_Next_Time_node(); p != nullptr)
                {  
                    if(p->Show_time() < time && p ->Show_Next_Time_node()->Show_time() > time)
                    {
                        Time_node* q = new Time_node(time, acco, nullptr);
                        q->Set_Next_node(p->Show_Next_Time_node());
                        p->Set_Next_node(q);
                    }
                }
            }
        }
        else
        return FULL;
    }
    else
    return NOACCEESS;
}

void Show_free_court(Court_node* first_court_node, int max_booking)
{

}