#ifndef EFFECTS_H
#define EFFECTS_H

typedef struct EffectData {
    char name[12];
    int ratio; // Divide value by ratio to get the end result. So an effect of value 10 with ratio 3 would have a final result of 3.
    char description[128];
} EffectData;

// TODO: should the same effect be separated based on affecting allies vs enemies?
EffectData effect_list[] = {
    "attack", 1, "Deals [value] damage. Simple but effective.",
    "defend", 1, "Blocks [value] damage. Wears off at the start of your turn.",
    "hide", 1, "Gain [value] Hidden which gives 5% dodge chance and 1% crit chance. Lose 1/5 of stacks (rounded up) when either happens.", // TODO: make sure that Hidden is not affected by buff modifiers except Evasion
    "heal", 1, "Restores [value] health. Probably don't want to use this on your enemies.",
    "dud", 1, "Does nothing. Bummer.",
    "purge", 1, "Clears all of a specific buff/debuff from a target.",
    "cleanse", 2, "Clears [value/ratio] in random buffs/debuffs from a target. Removes debuffs from players and buffs from enemies.",
    "channel", 2, "Removes [value/ratio] or that many 10ths of a specific buff/debuff from target and gain the same bonus to your next action.", // TODO: might need to be a pseudo-buff to clearly communicate and preserve effect between rounds
    "copy", 6, "Repeat another die face [value/ratio] times.",
    // Buffs
    "strengthen", 3, "Gain [value/ratio] in Strength. Strength boosts attack damage by 1 per stack.",
    "fortify", 3, "Gain [value/ratio] in Fortification which boosts defend actions by 1 per stack and preserves some block to next round.",
    "evade", 3, "Gain [value/ratio] in Evasion. Gain one more Hidden per stack of Evasion",
    "vigor", 3, "Gain [value/ratio] in Vigor. Gain one more health from all direct healing per stack of Vigor.",
    "regen", 3, "Gain [value/ratio] in Regeneration. Regeneration heals equal to its stacks at the end of each round.",
    "spike", 3, "Gain [value/ratio] in Spikes. Spikes deal damage to attackers when attacked.",
    "haste", 3, "Gain [value/ratio] in Haste. Spend 5 Haste to take another turn. Each extra turn in a round costs twice as much Haste.", // affects the entire team
    "luck", 2, "Gain [value/ratio] in Luck. Spend 1 Luck to reroll a die. Each reroll in a round costs one more Luck.",
    "bless", 5, "Gain [value/ratio] in Blessed. Blessed characters gain that many more stacks of other buffs.",
    // Debuffs
    "weaken", 3, "Apply [value/ratio] in Weakness. Weakness decreases attack damage by one per stack.",
    "vulnerable", 3, "Apply [value/ratio] in Vulnerable. Vulnerable decreases defense effectiveness by one per stack.",
    "mark", 3, "Apply [value/ratio] in Marked. Marked decreases dodge chance by 5% and increases crit chance on the target by 1% per stack.", // TODO: dodge chance below 0% is converted to crit chance at some ratio, maybe 2:1
    "wither", 3, "Apply [value/ratio] in Withered. Withered decreases effectiveness of direct healing by one per stack.",
    "burn", 3, "Apply [value/ratio] in Burning. Burning deals one damage per stack at the end of each round.",
    "freeze", 3, "Apply [value/ratio] in Freezing. Actions with value <= Freezing are lost along with that much Freezing.", // TODO: consider a post-freeze status that reduces the effectiveness of Freezing (not affecting stacks applied)
    "poison", 3, "Apply [value/ratio] in Poison. Characters with health <= poison immediately die.",
    "wound", 4, "Apply [value/ratio] in Wounded. Wounded characters lose extra health from attacks equal to their stacks. Try multi-hits.",
    "curse", 5, "Apply [value/ratio] in Cursed. Cursed characters gain that many more stacks of other debuffs.",
    "doom", 6, "Apply [value/ratio] in Doomed. Doomed characters have their current health set to 1/(1+Doomed stacks) at end of round.",
};

#endif