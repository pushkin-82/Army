#include "catch.hpp"
#include "../unit/Berserker.h"

TEST_CASE( "Test Berserker class" ) {
    Berserker* unit = new Berserker("Unit", 150, 20);

    REQUIRE( unit->getTitle() == "Unit" );
    REQUIRE( unit->getHitPoints() == 150 );
    REQUIRE( unit->getHitPointsLimit() == 150 );
    REQUIRE( unit->getDamage() == 20 );

    Berserker* berserker = new Berserker();

    REQUIRE( berserker->getTitle() == "Berserker" );
    REQUIRE( berserker->getHitPoints() == 100 );
    REQUIRE( berserker->getHitPointsLimit() == 100 );
    REQUIRE( berserker->getDamage() == 15 );
    
    SECTION( "Berserker::takeDamage tests" ) {
        int damage = 10;
        int iterations = berserker->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            berserker->takeDamage(damage);
            int expectedHP = berserker->getHitPointsLimit() - damage * i;
            REQUIRE( berserker->getHitPoints() == expectedHP );
        }

        try {
            berserker->takeDamage(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( berserker->getHitPoints() == 0 );
        }

        try {
            berserker->addHitPoints(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( berserker->getHitPoints() == 0 );
        }
    }
    
    SECTION( "Berserker::takeMagicDamage tests" ) {
        int damage = 20;

        try {
            berserker->takeMagicDamage(damage);
        } catch ( TotalMagicResistanceException obj ) {
            REQUIRE( berserker->getHitPoints() == 100 );
        }
    }
    SECTION( "Berserker::addHitPoints tests" ) {
        berserker->takeDamage(50);
        REQUIRE( berserker->getHitPoints() == 50 );

        try {
            berserker->addHitPoints(50);
        } catch ( TotalMagicResistanceException obj ) {
            REQUIRE( berserker->getHitPoints() == 50 );
        }

    }

    SECTION ( "Berserker::attack tests" ) {
        Berserker* enemy = new Berserker("Enemy", 150, 20);

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150);
        REQUIRE( enemy->getDamage() == 20);

        berserker->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 135 );
        REQUIRE( berserker->getHitPoints() == 90 );

        berserker->attack(enemy);
        berserker->attack(enemy);
        berserker->attack(enemy);
        berserker->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 75 );
        REQUIRE( berserker->getHitPoints() == 50 );

        enemy->takeDamage(65);

        REQUIRE( enemy->getHitPoints() == 10 );

        try {
            berserker->attack(enemy);
        } catch ( IsDeadException obj) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( berserker->getHitPoints() == 50 );
        }

        try {
            enemy->attack(berserker);
        } catch ( IsDeadException obj ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( berserker->getHitPoints() == 50 );
        }

    }

}