#ifndef EFFECTS_H
#define EFFECTS_H

typedef struct EffectData {
    char name[12];
    int ratio; // Divide value by ratio to get the end result. So an effect of value 10 with ratio 3 would have a final result of 3.
    char description[128];
};

// TODO: should the same effect be separated based on affecting allies vs enemies?
struct EffectData effect_list[] = {
    "attack", 1, "Deals damage. Simple but effective.",
    "defend", 1, "Blocks damage. Wears off at the start of your turn.",
    "hide", 1, "Gain Hidden which gives 5% dodge chance and 1% crit chance per stack. Lose 1/5 of stacks (rounded up) when either happens.",
    "heal", 1, "Restores a target's health. Probably don't want to use this on your enemies.",
    "dud", 1, "Does nothing. Bummer.",
    "purge", 1, "Clears all of a specific buff/debuff from a target.",
    "cleanse", 2, "Clears [ratio] value in random buffs/debuffs from a target. Removes debuffs from players and buffs from enemies.",
    "channel", 2, "Removes [ratio] value of a specific buff/debuff from a target and boosts your next action based on stacks removed.",
    "copy", 6, "Repeat another die face [ratio] of value times.",
    // Buffs
    "strengthen", 3, "Gain [ratio] of value in Strength. Strength boosts attack damage by 1 per stack.",
    "fortify", 3, "Gain [ratio] of value in Fortification which boosts defend actions by 1 per stack and preserves some block to next round.",
    "evade", 3, "Gain [ratio] of value in Evasion. Gain one more Hidden per stack of Evasion",
    "vigor", 3, "Gain [ratio] of value in Vigor. Gain one more health from all direct healing per stack of Vigor.",
    "regen", 3, "Gain [ratio] of value in Regeneration. Regeneration heals equal to its stacks at the end of each round.",
    "spike", 3, "Gain [ratio] of value in Spikes. Spikes deal damage to attackers when attacked.",
    "haste", 3, "Gain [ratio] of value in Haste. Spend 5 Haste to take another turn. Each extra turn in a round costs twice as much Haste.",
    "luck", 2, "Gain [ratio] of value in Luck. Spend 5 Luck to reroll a die. Each reroll in a round costs one more Luck.",
    "bless", 6, "Gain [ratio] of value in Blessed. Blessed characters gain that many more stacks of other buffs.",
    // Debuffs
    "weaken", 3, "Apply [ratio] of value in Weakness. Weakness decreases attack damage by one per stack.",
    "vulnerable", 3, "Apply [ratio] of value in Vulnerable. Vulnerable decreases defense effectiveness by one per stack.",
    "mark", 3, "Apply [ratio] of value in Marked. Marked decreases dodge chance by 5% and increases crit chance on the target by 1% per stack.",
    "wither", 3, "Apply [ratio] of value in Withered. Withered decreases effectiveness of direct healing by one per stack.",
    "burn", 3, "Apply [ratio] of value in Burning. Burning deals one damage per stack at the end of each round.",
    "freeze", 3, "Apply [ratio] of value in Freezing. Actions with value <= Freezing are lost along with that much Freezing.",
    "poison", 3, "Apply [ratio] of value in Poison. Characters with health <= poison immediately die.",
    "wound", 4, "Apply [ratio] of value in Wounded. Wounded characters lose extra health from attacks equal to their stacks. Try multi-hits.",
    "curse", 5, "Apply [ratio] of value in Cursed. Cursed characters gain that many more stacks of other debuffs.",
    "doom", 6, "Apply [ratio] of value in Doomed. Doomed characters have their current health set to 1/(1+Doomed stacks) at end of round.",
};

#endif