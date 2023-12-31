#ifndef NODE_H
#define NODE_H
#define _CRT_SECURE_NO_WARNINGS
#include "account.h"

class Time_node
{
    public:
        Time_node(){};
        Time_node(int time, Account acco, Time_node* next);

        void Show_time(int time);
        int Show_time();
        void Show_book_acco();
        Time_node* Show_Next_Time_node();
        void Set_Next_node(Time_node* next);
    private:
        int time_;
        Account acco_;
        Time_node* next_time_node;
};

Time_node::Time_node(int time, Account acco, Time_node* next)
{
    time_ = time;
    acco_ = acco;
    next_time_node = next;
}

void Time_node::Show_time(int time)
{
    switch (time)
    {
    case 1:
        cout << " 8:00 ~ 9:00 ";
        break;
    case 2:
        cout << " 9:00 ~ 10:00 ";
        break;
    case 3:
        cout << " 10:00 ~ 11:00 ";
        break;
    case 4:
        cout << " 13:00 ~ 14:00 ";
        break;
    case 5:
        cout << " 15:00 ~ 16:00 ";
        break;
    default:
        break;
    }

}

int Time_node::Show_time()
{
    return time_;
}

void Time_node::Show_book_acco()
{
    acco_.DisPlay_info();
}

Time_node* Time_node::Show_Next_Time_node()
{
    return next_time_node;
}

void Time_node::Set_Next_node(Time_node* next)
{
    next_time_node = next;
}


class Court_node
{
    public:
		Court_node(){};
        Court_node(Time_node *time_first,int court_num,int max_booking, int current_booking, Court_node *next_cou);
        int Get_current_order_num();
        int Get_court_number();
        Time_node* Get_first_time_node();
        bool Is_full();
        void Display_court();
        friend class Time_node;
    private:
		Time_node *time_first_node;       //指向的时间链表
        int court_number;                    //当前场地的编号
        int max_booking_num;                 //一个场地最多有多少个时间段可以被预约
        int current_booking_num;             //当前已经有多少个时间段被预约了
        Court_node *next_court;
};

Court_node::Court_node(Time_node *time_first,int court_num, int max_booking, int current_booking, Court_node *next_cou)
{
    time_first_node = time_first;
    court_number = court_num;
    max_booking_num = max_booking;
    current_booking_num = current_booking;
    next_court = next_cou;
}

int Court_node::Get_current_order_num()
{
    return current_booking_num;
}

int Court_node::Get_court_number()
{
  
    return court_number;
}

Time_node* Court_node::Get_first_time_node()
{
    return time_first_node;
}

bool Court_node::Is_full()
{
    return current_booking_num == max_booking_num;
}

void Court_node::Display_court()
{
    
}

#endif