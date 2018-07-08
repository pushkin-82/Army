#include "catch.hpp"
#include "../unit/Vampire.h"

TEST_CASE( "Test Vampire class" ) {
    Vampire* unit = new Vampire("Unit", 150, 20);

    REQUIRE( unit->getTitle() == "Unit" );
    REQUIRE( unit->getHitPoints() == 150 );
    REQUIRE( unit->getHitPointsLimit() == 150 );
    REQUIRE( unit->getDamage() == 20 );

    Vampire* vampire = new Vampire();

    REQUIRE( vampire->getTitle() == "Vampire" );
    REQUIRE( vampire->getHitPoints() == 200 );
    REQUIRE( vampire->getHitPointsLimit() == 200 );
    REQUIRE( vampire->getDamage() == 40 );
    
    SECTION( "Vampire::takeDamage tests" ) {
        int damage = 10;
        int iterations = vampire->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            vampire->takeDamage(damage);
            int expectedHP = vampire->getHitPointsLimit() - damage * i;
            REQUIRE( vampire->getHitPoints() == expectedHP );
        }

        try {
            vampire->takeDamage(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( vampire->getHitPoints() == 0 );
        }

        try {
            vampire->addHitPoints(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( vampire->getHitPoints() == 0 );
        }
    }
    
    SECTION( "Vampire::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = vampire->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            vampire->takeMagicDamage(damage);
            int expectedHP = vampire->getHitPointsLimit() - damage * i;
            REQUIRE( vampire->getHitPoints() == expectedHP );
        }

        try {
            vampire->takeMagicDamage(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( vampire->getHitPoints() == 0 );
        }

        try {
            vampire->addHitPoints(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( vampire->getHitPoints() == 0 );
        }
    }

    SECTION( "Vampire::addHitPoints tests" ) {
        vampire->takeDamage(50);
        REQUIRE( vampire->getHitPoints() == 150 );

        vampire->addHitPoints(40);
        REQUIRE( vampire->getHitPoints() == 190 );

        vampire->addHitPoints(10);
        REQUIRE( vampire->getHitPoints() == 200 );

        vampire->addHitPoints(10);
        REQUIRE( vampire->getHitPoints() == 200 );
    }

    SECTION ( "Vampire::attack tests" ) {
        Vampire* enemy = new Vampire("Enemy", 200, 20);

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoints() == 200 );
        REQUIRE( enemy->getHitPointsLimit() == 200);
        REQUIRE( enemy->getDamage() == 20);

        vampire->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 160 );
        REQUIRE( vampire->getHitPoints() == 200 );

        vampire->attack(enemy);
        vampire->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 80 );
        REQUIRE( vampire->getHitPoints() == 200 );

        enemy->takeDamage(40);

        REQUIRE( enemy->getHitPoints() == 40 );

        try {
            vampire->attack(enemy);
        } catch ( IsDeadException obj) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( vampire->getHitPoints() == 200 );
        }

        try {
            enemy->attack(vampire);
        } catch ( IsDeadException obj ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( vampire->getHitPoints() == 200 );
        }

    }

}