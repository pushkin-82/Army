#include "catch.hpp"
#include "../unit/Unit.h"

TEST_CASE( "Test Unit class" ) {
    Unit* unit = new Unit("Unit", 150, 20);

    REQUIRE( unit->getTitle() == "Unit" );
    REQUIRE( unit->getHitPoints() == 150 );
    REQUIRE( unit->getHitPointsLimit() == 150 );
    REQUIRE( unit->getDamage() == 20 );
    
    SECTION( "Unit::takeDamage tests" ) {
        int damage = 10;
        int iterations = unit->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            unit->takeDamage(damage);
            int expectedHP = unit->getHitPointsLimit() - damage * i;
            REQUIRE( unit->getHitPoints() == expectedHP );
        }

        try {
            unit->takeDamage(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( unit->getHitPoints() == 0 );
        }

        try {
            unit->addHitPoints(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( unit->getHitPoints() == 0 );
        }
    }
    
    SECTION( "Unit::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = unit->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            unit->takeMagicDamage(damage);
            int expectedHP = unit->getHitPointsLimit() - damage * i;
            REQUIRE( unit->getHitPoints() == expectedHP );
        }

        try {
            unit->takeMagicDamage(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( unit->getHitPoints() == 0 );
        }

        try {
            unit->addHitPoints(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( unit->getHitPoints() == 0 );
        }
    }
    SECTION( "Unit::addHitPoints tests" ) {
        unit->takeDamage(50);
        REQUIRE( unit->getHitPoints() == 100 );

        unit->addHitPoints(40);
        REQUIRE( unit->getHitPoints() == 140 );

        unit->addHitPoints(10);
        REQUIRE( unit->getHitPoints() == 150 );

        unit->addHitPoints(10);
        REQUIRE( unit->getHitPoints() == 150 );
    }

}