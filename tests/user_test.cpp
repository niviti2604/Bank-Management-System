#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/user.h"

// Utility to create a basic user without triggering user input
User createTestUser(const std::string& name = "Test User", Type type = SAVINGS, double balance = 0.0) {
    User user;
    user.setUserName(name);
    user.setAccountType(type);
    user.setBalance(balance);
    return user;
}

TEST_CASE("Deposit increases balance correctly", "[deposit]") {
    User u = createTestUser();
    u.deposit(100.0);
    REQUIRE(u.getBalance() == Approx(100.0));
}

TEST_CASE("Withdraw reduces balance if sufficient", "[withdraw]") {
    User u = createTestUser("Withdraw Test", SAVINGS, 200.0);
    bool result = u.withdraw(150.0);
    REQUIRE(result == true);
    REQUIRE(u.getBalance() == Approx(50.0));
}

TEST_CASE("Withdraw fails with insufficient balance", "[withdraw]") {
    User u = createTestUser("Low Funds", CURRENT, 50.0);
    bool result = u.withdraw(100.0);
    REQUIRE(result == false);
    REQUIRE(u.getBalance() == Approx(50.0));
}

TEST_CASE("Account type is correctly set and exported", "[account_type]") {
    User u = createTestUser("Typed User", CURRENT);
    json j = u.toJson();
    REQUIRE(j["account_type"] == "Current");
}
