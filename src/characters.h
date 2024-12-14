#include "dice.h"

#ifndef CHARACTERS_H
#define CHARACTERS_H

#define BASE_HEALTH 50

// Warrior and Rogue are base types that will be completely replaced by versions with better scaling as part of meta-progression
#define WARRIOR_DESC "A simple fighter with straightforward attack and defense."
#define ROGUE_DESC "A stealthy fighter that dodges attacks and uses critical hits."
#define APPRENTICE_DESC "A beginner mage with minor buffing abilities."
#define PALADIN_DESC "A defensive fighter with a pocket heal."
#define VAMPIRE_DESC "A self-healing fighter with damage and healing buffs."
#define PYROMANCER_DESC "A deadly mage that builds up damage over time with burn."
#define CRYOMANCER_DESC "A defensive mage that freezes enemies in their tracks."
#define WARLOCK_DESC "A peculiar mage that gives enemies regeneration only to turn it into poison or claim it for themself."
#define PLAGUE_DESC "A peculiar mage that poisons themself before spreading it to enemies or healing their team."
#define ASSASSIN_DESC "A deadly fighter that bursts from the shadows for devastating damage."
#define CHRONOMANCER_DESC "A cunning mage that buys their team extra time to defeat their enemies."
#define GAMBLER_DESC "A lucky mage that gives their team extra chances or uses the luck themself for attack or defense."
#define DRUID_DESC "A nature mage that gives regeneration and spikes to their team." // regen/spikes
#define DERVISH_DESC "A deadly fighter specializing in flurries of blows." // multi-hit
#define HEXER_DESC "A curse-focused mage that amplifies all debuffs applied to enemies."
#define ANGEL_DESC "A healer focused on blessing allies and applying regeneration to them."

typedef struct Character {
    char name[12];
    char description[128];
    char faces[128]; // contains comma/semicolon separated data for each die face. Semicolons separate faces, commas separate effects/upgrades for a given face. Effects are abbreviated with 2 letters (followed by face value for first effect). Upgrades are abbreviated with one letter letter followed by any secondary effect information.
} Character;


Character Normal_Characters[] = {
    "warrior", WARRIOR_DESC, "at5;at4;at3;at2;de4;de3",
    "rogue", ROGUE_DESC, "at5;at4;at3;hi4;hi3;hi2",
    "apprentice", APPRENTICE_DESC, "at4;at3;st4;de3;de2;fo4",
    "paladin", PALADIN_DESC, "at5;at4;de4;de2;he3;fo3",
    "vampire", VAMPIRE_DESC, "at4,che;at3,che;st4;vi4;du1;du1",
    "pyromancer", PYROMANCER_DESC, "at3,cbu;at2,cbu;de3,cbu;de2,cbu;bu4;bu4",
    "cryomancer", CRYOMANCER_DESC, "at3,cfr;at2,cfr;de3,cfr;de2,cfr;fr4;fr4",
    "warlock", WARLOCK_DESC, "re10,e;re6,e;ch4re;ch4re;po3;re3",
    "plague", PLAGUE_DESC, "po10,i;po6,i;ch4po;ch4po;po1,s;he1,s",
    "assassin", ASSASSIN_DESC, "hi5;hi4;hi3;ch8hi,i;ch8hi,i;at2;at2",
    "chronomancer", CHRONOMANCER_DESC, "co6;co6;ha4;ha4;ha3;ha3",
    "gambler", GAMBLER_DESC, "lu6;lu5;lu4;ch8lu,i;at3;de3",
    "druid", DRUID_DESC, "re6;re3,s;re3;sp6;sp3,s;sp3",
    "dervish", DERVISH_DESC, "wo4;wo4;at1,ee;at1,e;at1;st3",
    "hexer", HEXER_DESC, "do6;cu5;cu5;bu3;po3;du1",
    "angel", ANGEL_DESC, "bl5,s;bl5;re3,s;re3;du1;du1",
};

Die get_character(int character_id){
    // do stuff
};

#endif