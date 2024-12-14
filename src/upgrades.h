#ifndef UPGRADES_H
#define UPGRADES_H

typedef struct UpgradeData {
    char name[12];
    char description[256];
} UpgradeData;

/* 
 Effects are applied in the order applied to the die face,
 so a vigor face upgraded with healing could benefit from the increased healing immediately,
 while a healing face upgraded with vigor, would perform the heal before gaining the bonus
 */
// TODO: can sides upgraded with internal/external have their effect swapped with replace?
UpgradeData upgrades[] = {
    "plus", "adds a fixed value to an effect, costs more depending on the effect",
    "echo", "halves an effect's value (minimum 1) but causes it to apply an extra time",
    "sweep", "applies the effect to all valid targets",
    "bonus", "gives a bonus effect that scales with face value",
    "chain", "gives a bonus effect that scales with the result of the base action",
    "replace", "replaces a current effect with a different one, keeping the face value",
    "merge", "gives one die face the effects of another, then turns the other into a dud",
    "duplicate", "replaces one die face with another",
    "tertiary", "allows an effect with a secondary effect to have another. For example, this could change a purge [burn] into a purge [burn, poison]. Applying this to channel allows it to remove either type of debuff based on their combined stacks.",
    "internal", "doubles the face's value but can only target self/allies, only allowed on harmful faces. Sides with both beneficial and harmful effects are allowed. Might be allowed once per harmful effect on the face.",
    "external", "doubles the face's value but can only target enemies, only allowed on beneficial faces. Sides with both beneficial and harmful effects are allowed. Might be allowed once per beneficial effect on the face."
};

#endif