#ifndef UPGRADES_H

// Effects are applied in the order applied to the die face,
// so a vigor face upgraded with healing could benefit from the increased healing immediately,
// while a healing face upgraded with vigor, would perform the heal before gaining the bonus
// TODO: consider removing flat bonus due to the addition of ratios
enum upgrades {
    PLUS, // adds a fixed value to an effect, costs more depending on the effect
    REPEAT, // halves an effect's value (minimum 1) but causes it to apply an extra time
    SWEEP, // applies the effect to all valid targets, more interesting on positive die faces if each die is a separate character as in Slice & Dice
    BONUS, // gives a bonus effect that scales with face value
    CHAIN, // gives a bonus effect that scales with the effectiveness of the base action
    REPLACE, // replaces the current effect with a different one, keeping the face value
    MERGE, // gives one die face the effects of another, then turns the other into a dud
    DUPLICATE, // replaces one die face with another
    SECONDARY, // allows an effect with a secondary effect to have another. For example, this could change a purge [burn] into a purge [burn, poison]. Applying this to channel allows it to remove either type of debuff totalling up to the channel value.
};

#endif