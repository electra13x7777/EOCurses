// File: skill.h
// Author: Alex Barney
//
// Description: Prototypes skills

// Alchemist
void al_tp_up(int sp, struct class *al); // increases alc TP
void fire_up(int sp, int fd); // increases Fire
void ice_up(int sp, int id); // increases Ice
void volt_up(int sp, int vd); // increases Volt
void toxins(int sp); // increases Poison
void scavenge(int sp); // increases chance of battle item drop
void tp_regen(int sp, struct class *al); // restores TP every turn
void fire(int sp); // fire damage
void flame(int sp); // large fire damage
void inferno(int sp); // large multitarget fire damage
void ice(int sp); // ice damage
void freeze(int sp); // large ice damage
void cocytus(int sp); // large multitarget ice damage
void volt(int sp); // volt damage
void thunder(int sp); // large volt damage
void thor(int sp); // large multitarget volt damage
void poison(int sp); // inflicts poison
void venom(int sp); // inflicts poison to multiple targets
void sight(int sp); // see all FOEs on the map
void warp(int sp); // warp to the last visited Geomagnetic Field
void chop(int sp); // Chop wood for materials at item points

// Dark Hunter
void dh_hp_up(int sp, struct class *dh); // increases dh HP
void dh_tp_up(int sp, struct class *dh); // increases dh TP
void dh_atk_up(int sp, struct class *dh); // increases dh ATK
void dh_whips(int sp); // increases whip damage
void dh_swords(int sp); // increases sword damage
void dh_boost_up(int sp); // increase the improvement gained when boosted
void fury(int sp); // increase damage dealt when HP is low
void cloak(int sp); // enemy won’t target you
void viper(int sp); // whip attack with a chance of poisoning the enemy
void gag(int sp); // whip attack with a chance of binding the enemy's head
void shackles(int sp); // whip attack with a chance of binding the enemy's legs
void cuffs(int sp); // whip attack with a chance of binding the enemy's arms
void ecstacy(int sp); // whip attack that does a ton of damage to enemy w/ 3 binds
void climax(int sp); // whip skill that may kill and drain enemies with low HP
void hypnos(int sp); // sword stab with a chance of putting the enemy to sleep
void nerve(int sp); // sword stab at the enemy’s nerves with a chance of paralyzing it
void mirage(int sp); // sword stab at the enemy’s skull with a chance of confusing it
void drain(int sp); // sword stab that drains the enemy’s HP through the blade
void bait(int sp); // sword skill that uses comrades on either side to bait a trap
void petrify(int sp); // sword stab at the enemy’s muscles with a chance of stoning
void take(int sp); // gather plants for materials at item points

// Landsknecht
void la_hp_up(int sp, struct class *la); // increases la HP
void la_tp_up(int sp, struct class *la); // increases la TP
void la_atk_up(int sp, struct class *la); // increases la ATK
void la_def_up(int sp, struct class *la); // increases la DEF
void la_axes(int sp); // increases axe damage
void la_swords(int sp); // increases sword damage
void 2_hit(int sp); // normal weapon attacks have a chance of hitting twice
void war_cry(int sp); // increase attack power at the expense of defense
void hell_cry(int sp); // abandon defense and stamina for greatly strengthened attack
void arm_heal(int sp); // regain the use of bound arms
void flee(int sp); // sacrifice HP to escape from battle to the previous floor
void cleaver(int sp); // a rushing sword slash
void tornado(int sp); // a whirling sword skill that strikes adjacent enemies
void allslash(int sp); // a sword skill that hits a group of enemies 2-4 times
void blazer(int sp); // sword skill that follows fire magic with a flaming slash
void freezer(int sp); // sword skill that follows fire magic with a freezing slash
void shocker(int sp); // sword skill that follows fire magic with a shocking slash
void crush(int sp); // a charging axe strike
void stunner(int sp); // an axe attack that puts the enemy off-balance
void silencer(int sp); // an axe skill with a chance of binding the enemy's head
void mine(int sp); // mine for materials at item points
