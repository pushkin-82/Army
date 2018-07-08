#include "catch.hpp"
#include "../unit/Soldier.h"

TEST_CASE( "Test Soldier class" ) {
    Soldier* unit = new Soldier("Unit", 150, 20);

    REQUIRE( unit->getTitle() == "Unit" );
    REQUIRE( unit->getHitPoints() == 150 );
    REQUIRE( unit->getHitPointsLimit() == 150 );
    REQUIRE( unit->getDamage() == 20 );

    Soldier* soldier = new Soldier();

    REQUIRE( soldier->getTitle() == "Soldier" );
    REQUIRE( soldier->getHitPoints() == 100 );
    REQUIRE( soldier->getHitPointsLimit() == 100 );
    REQUIRE( soldier->getDamage() == 10 );
    
    SECTION( "Soldier::takeDamage tests" ) {
        int damage = 10;
        int iterations = soldier->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            soldier->takeDamage(damage);
            int expectedHP = soldier->getHitPointsLimit() - damage * i;
            REQUIRE( soldier->getHitPoints() == expectedHP );
        }

        try {
            soldier->takeDamage(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( soldier->getHitPoints() == 0 );
        }

        try {
            soldier->addHitPoints(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( soldier->getHitPoints() == 0 );
        }
    }
    
    SECTION( "Soldier::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = soldier->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            soldier->takeMagicDamage(damage);
            int expectedHP = soldier->getHitPointsLimit() - damage * i;
            REQUIRE( soldier->getHitPoints() == expectedHP );
        }

        try {
            soldier->takeMagicDamage(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( soldier->getHitPoints() == 0 );
        }

        try {
            soldier->addHitPoints(damage);
        } catch ( IsDeadException obj ) {
            REQUIRE( soldier->getHitPoints() == 0 );
        }
    }
    
    SECTION( "Soldier::addHitPoints tests" ) {
        soldier->takeDamage(50);
        REQUIRE( soldier->getHitPoints() == 50 );

        soldier->addHitPoints(40);
        REQUIRE( soldier->getHitPoints() == 90 );

        soldier->addHitPoints(10);
        REQUIRE( soldier->getHitPoints() == 100 );

        soldier->addHitPoints(10);
        REQUIRE( soldier->getHitPoints() == 100 );
    }

    SECTION ( "Soldier::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150);
        REQUIRE( enemy->getDamage() == 20);

        soldier->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 140 );
        REQUIRE( soldier->getHitPoints() == 90 );

        soldier->attack(enemy);
        soldier->attack(enemy);
        soldier->attack(enemy);
        soldier->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 100 );
        REQUIRE( soldier->getHitPoints() == 50 );

        enemy->takeDamage(90);

        REQUIRE( enemy->getHitPoints() == 10 );

        try {
            soldier->attack(enemy);
        } catch ( IsDeadException obj) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( soldier->getHitPoints() == 50 );
        }

        try {
            enemy->attack(soldier);
        } catch ( IsDeadException obj ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( soldier->getHitPoints() == 50 );
        }

    }

}