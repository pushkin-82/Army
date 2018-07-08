#include "Summon.h"
#include "../spellcaster/Warlock.h"
#include "../unit/Daemon.h"

Summon::Summon(std::string title, int cost, int points) : Spell(title, cost, points) {}
Summon::~Summon() {}

