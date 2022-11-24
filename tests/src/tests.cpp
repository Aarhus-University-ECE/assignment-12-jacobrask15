#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file.

#include "duration.hpp"

TEST_CASE("constructor med input") /*d*/
{
    Duration fem(5);
    REQUIRE(fem.getDuration() == 5);
    Duration hundredogni(109);
    REQUIRE(hundredogni.getDuration() == 109);
    Duration nul(0);
    REQUIRE(nul.getDuration() == 0);
}

TEST_CASE("tick") /*e*/
{
    Duration fem(5);
    fem.tick();
    fem.tick();
    fem.tick(); /*5+3*/
    REQUIRE(fem.getDuration() == 8);
    Duration hundredogni(109);
    hundredogni.tick();
    hundredogni.tick(); /*109 + 2*/
    REQUIRE(hundredogni.getDuration() == 111);
    Duration nul;
    nul.tick();
    nul.tick();
    nul.tick();
    nul.tick();
    nul.tick(); /*0+5*/
    REQUIRE(nul.getDuration() == 5);
}

TEST_CASE("tick(n)") /*f*/
{
    Duration fem(5);
    fem.tick(1);
    fem.tick(2);
    fem.tick(3); /*5+6*/
    REQUIRE(fem.getDuration() == 11);
    Duration hundredogni(109);
    hundredogni.tick(0);
    hundredogni.tick(2); /*109 + 2*/
    REQUIRE(hundredogni.getDuration() == 111);
    Duration nul;
    nul.tick(100);
    nul.tick(300);
    nul.tick(50);
    nul.tick(25);
    nul.tick(25); /*0+500*/
    REQUIRE(nul.getDuration() == 500);
}

TEST_CASE("alarm") /*g*/
{
    Duration fem(5);
    fem.tick(1);
    fem.tick(2);
    fem.tick(3);                    /*5+6*/
    REQUIRE(fem.tick(10) == false); /*no alarm set*/

    Duration hundredogni(109);
    hundredogni.tick(0);
    hundredogni.tick(2); /*109 + 2*/
    hundredogni.setalarm(112);
    REQUIRE(hundredogni.tick(2) == true); /*time should be 1 over alarm and tick should return true*/

    Duration nul;
    REQUIRE(nul.tick(100) == false); /*no alarm set*/
    nul.setalarm(500);
    nul.tick(300);
    nul.tick(50);
    nul.tick(25);
    REQUIRE(nul.tick(25) == false);    /*time is 500, alarm is 500. tick should return false*/
    REQUIRE(nul.getDuration() == 500); /*this should still hold*/
    REQUIRE(nul.tick(1) == true);      /*alarm should go off*/

    Duration seks(6);
    seks.setalarm(3);
    REQUIRE(seks.tick() == false); /*alarm was set in the past*/
    seks.setalarm(10);
    REQUIRE(seks.tick(4) == true); /*alarm was set correctly*/
    REQUIRE(seks.tick() == false); /*alarms should be reset*/
}
