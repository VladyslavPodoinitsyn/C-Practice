#include <iostream>
#include "vending_bank.h"

void testVendingBank() {
    // Create an instance of VendingBank
    VendingBank vendingBank(1001, 10, 10, 10, 10);
    
    // Test the balance calculation
    double expectedBalance = 0.10 * 10 + 0.05 * 10 + 0.10 * 10 + 0.25 * 10;
    if (vendingBank.balance() == expectedBalance) {
        std::cout << "Balance calculation test passed." << std::endl;
    } else {
        std::cout << "Balance calculation test failed." << std::endl;
    }
    
    // Test setting snack prices
    vendingBank.set_snack_price("Chips", 1.50);
    vendingBank.set_snack_price("Soda", 2.00);
    if (vendingBank.has_sufficient_balance("Chips") && vendingBank.has_sufficient_balance("Soda")) {
        std::cout << "Set snack prices test passed." << std::endl;
    } else {
        std::cout << "Set snack prices test failed." << std::endl;
    }
    
    // Add some coins and test adding coins functionality
    vendingBank.AddCoins(5, 5, 5, 5);
    if (vendingBank.balance() == expectedBalance + 0.01 * 5 + 0.05 * 5 + 0.10 * 5 + 0.25 * 5) {
        std::cout << "Add coins test passed." << std::endl;
    } else {
        std::cout << "Add coins test failed." << std::endl;
    }
}
