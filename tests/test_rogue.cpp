#include "catch.hpp"
#include "../unit/Rogue.h"

TEST_CASE( "Test Rogue class" ) {
    Rogue* unit = new Rogue("Unit", 150, 20);

    REQUIRE( unit->getTitle() == "Unit" );
    REQUIRE( unit->getHitPoints() == 150 );
    REQUIRE( unit->getHitPointsLimit() == 150 );
    REQUIRE( unit->getDamage() == 20 );

    Rogue* rogue = new Rogue();

    REQUIRE( rogue->getTitle() == "Rogue" );
    REQUIRE( rogue->getHitPoints() == 80 );
    REQUIRE( rogue->getHitPointsLimit() == 80 );
    REQUIRE( rogue->getDamage() == 20 );
    
    SECTION( "Rogue::takeDamage tests" ) {
        int damage = 10;
        int iterations = rogue->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            rogue->takeDamage(damage);
            int expectedHP = rogue->getHitPointsLimit() - damage * i;
            REQUIRE( rogue->getHitPoints() == expectedHP );
        }

        try {
            rogue->takeDamage(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( rogue->getHitPoints() == 0 );
        }

        try {
            rogue->addHitPoints(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( rogue->getHitPoints() == 0 );
        }
    }
    
    SECTION( "Rogue::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = rogue->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            rogue->takeMagicDamage(damage);
            int expectedHP = rogue->getHitPointsLimit() - damage * i;
            REQUIRE( rogue->getHitPoints() == expectedHP );
        }

        try {
            rogue->takeMagicDamage(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( rogue->getHitPoints() == 0 );
        }

        try {
            rogue->addHitPoints(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( rogue->getHitPoints() == 0 );
        }
    }
    SECTION( "Rogue::addHitPoints tests" ) {
        rogue->takeDamage(50);
        REQUIRE( rogue->getHitPoints() == 30 );

        rogue->addHitPoints(40);
        REQUIRE( rogue->getHitPoints() == 70 );

        rogue->addHitPoints(10);
        REQUIRE( rogue->getHitPoints() == 80 );

        rogue->addHitPoints(10);
        REQUIRE( rogue->getHitPoints() == 80 );
    }

    SECTION ( "Rogue::attack tests" ) {
        Rogue* enemy = new Rogue("Enemy", 150, 20);

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150);
        REQUIRE( enemy->getDamage() == 20);

        rogue->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 130 );
        REQUIRE( rogue->getHitPoints() == 80 );

        rogue->attack(enemy);
        rogue->attack(enemy);
        rogue->attack(enemy);
        rogue->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 50 );
        REQUIRE( rogue->getHitPoints() == 80 );

        enemy->takeDamage(40);

        REQUIRE( enemy->getHitPoints() == 10 );

        try {
            rogue->attack(enemy);
        } catch ( IsDeadException obj) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( rogue->getHitPoints() == 80 );
        }

        try {
            enemy->attack(rogue);
        } catch ( IsDeadException obj ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( rogue->getHitPoints() == 80 );
        }

    }

}