#ifndef ACCOUNT_H
#define ACCOUNT_H
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Account
{
    public:
        Account();
        Account(string account, string password);
        bool Account_is_valid(Account &acco, string account);
        bool Password_is_valid(Account &acco, string account, string password);
        void DisPlay_info();
        Account& operator=(Account &acco);
        // void Read();
    private:
        string account_;
        string password_;
        int sex;
        int profession;
        int max_booking_number;
        int current_booking_number;
        string Get_account();
        string Get_password();
};



Account& Account::operator=(Account &acco)//=的重载
{
	account_ = acco.account_;
    password_ = acco.password_;
    sex = acco.sex;
    profession = acco.profession;
    max_booking_number = acco.max_booking_number;
    current_booking_number = acco.current_booking_number;
	return *this;
}


void Account::DisPlay_info()
{
    cout << "The current account : "<< this->account_ << endl;
    cout << "The student sex is : " << sex << endl;
    cout << "The student profession is : " << profession << endl;
    cout << "The student max booking number is : " << max_booking_number << endl;
    cout << "The student current booking number is : " << current_booking_number << endl;
}


Account::Account()
{
    account_ = nullptr;
    password_ = nullptr;
}

Account::Account(string account, string password)
{
    this->account_ = account;
    this->password_ = password;
}

// void Account::Read()
// {
// 	ifstream ifile;
// 	ifile.open("user.txt", ios::in);

// 	int scount = 0;

// 	if (!ifile.is_open())
// 	{
// 		//cout << "文件打开失败！" << endl;
// 		return;
// 	}

// 	for (int i = 0; !ifile.eof(); i++)
// 	{
// 		ifile >> this->account_;
// 		ifile >> this->password_;
// 		scount++;
// 	}
// 	scount--;
// 	ifile.close();
// }

string Account::Get_account()
{
    return account_;
}

string Account::Get_password()
{
    return password_;
}

bool Account::Account_is_valid(Account &acco, string account)
{
    return acco.Get_account() == account;

}

bool Account::Password_is_valid(Account &acco, string account, string password)
{
    if(Account_is_valid(acco,account))
    {
        return acco.Get_password() == password;
    }
    else 
        return false;
}

#endif