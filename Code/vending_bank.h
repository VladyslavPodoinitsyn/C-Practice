#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_

#include <iostream>

#include <string>
#include <unordered_map>

class VendingBank {
public:
    //Constructors
    VendingBank();
    VendingBank(int id, int pennies, int nickels, int dimes, int quarters);
    VendingBank(int id);

    //Getters
    int id() const;
    double balance() const;

    //Setters
    void set_snack_price(const std::string& snack_name, double price);
    bool SetQuarters();
    bool SetDimes();
    bool SetPennies();
    bool SetNickles();

    //Action Verbs
    int Balance();
    bool AddCoins(int pennies, int nickels, int dimes, int quarters);
    bool MakeChange(int amount);
    bool RemoveAmount(int amount);

    //Core Functionality
    void insert_coin(double amount);
    bool dispense_snack(const std::string& snack_name);
    void reset_balance();

    //Utility Functions
    bool has_sufficient_balance(const std::string& snack_name) const;

private:
    int id_;
    double balance_;
    int pennies_;
    int nickels_;
    int dimes_;
    int quarters_;
    std::unordered_map<std::string, double> snack_prices_;
};

#endif