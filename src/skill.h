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
void al_scavenge(int sp); // increases chance of battle item drop
void al_tp_regen(int sp, struct class *al); // restores TP every turn
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
void al_chop(int sp); // Chop wood for materials at item points

// Dark Hunter
void dh_hp_up(int sp, struct class *dh); // increases dh HP
void dh_tp_up(int sp, struct class *dh); // increases dh TP
void dh_atk_up(int sp, struct class *dh); // increases dh ATK
void dh_whips(int sp); // increases whip damage
void dh_swords(int sp); // increases sword damage
void dh_boost_up(int sp); // increase the improvement gained when boosted
void fury(int sp); // increase damage dealt when HP is low
void dh_cloak(int sp); // enemy won’t target you
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
void dh_take(int sp); // gather plants for materials at item points

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
void la_mine(int sp); // mine for materials at item points

// Survivalist
void su_hp_up(int sp, struct class *su); // increases su HP
void su_tp_up(int sp, struct class *su); // increases su TP
void su_agi_up(int sp, struct class *su); // increases su AGI
void su_bows(int sp); // increases bow damage
void ambush(int sp); // increase premptive chance
void aware(int sp); // decreases enemy premptive chance
void 1st_hit(int sp); // chance of acting first next turn
void trickery(int sp); // lowers all enemy accuracy
void quicken(int sp); // increases speed of party
void su_cloak(int sp); // enemy won’t target you
void escape(int sp); // increase escape chance
void 1st_turn(int sp); // targeted party member will act just after you cast
void trueshot(int sp); // powerful, piercing bow skill
void multihit(int sp); // fires 2-3 shots at once
void disable(int sp); // damage and chance to bind legs
void apollon(int sp); // the ultimate bow skill that takes 3 turns
void owl_eye(int sp); // able to see far away FOEs
void su_stalker(int sp); // reduces enemy encounter rate
void su_chop(int sp); // Chop wood for materials at item points
void su_mine(int sp); // mine for materials at item points
void su_take(int sp); // gather plants for materials at item points

// Troubadour
void tr_hp_up(int sp, struct class *tr); // increases tr HP
void tr_tp_up(int sp, struct class *tr); // increases tr TP
void songs(int sp); // needed to learn songs
void divinity(int sp); // increases exp gain for entire party
void bravery(int sp); // increases strength for entire party
void shelter(int sp); // increases defense for entire party
void mercury(int sp); // increases speed for entire party
void erasure(int sp); // removes buffs from all enemies
void recovery(int sp); // allows the entire party to recover from status ailments quicker
void stamina(int sp); // increases max HP for entire party
void blaze(int sp); // adds the element of fire to one party member's weapon
void frost(int sp); // adds the element of ice to one party member's weapon
void shock(int sp); // adds the element of lightning to one party member's weapon
void ifrit(int sp); // increases fire resistance for entire party/decreases for enemies
void ymir(int sp); // increases ice resistance for entire party/decreases for enemies
void taranis(int sp); // increases volt resistance for entire party/decreases for enemies
void healing(int sp); // small amount of HP is restored to the entire party every turn
void relaxing(int sp); // small amount of TP is restored to the entire party every turn
void tr_stalker(int sp); // reduces enemy encounter rate
void tr_return(int sp); // takes party back to previous floor
void tr_take(int sp); // gather plants for materials at item points

// Medic
void me_hp_up(int sp, struct class *me); // increases me HP
void me_tp_up(int sp, struct class *me); // increases me TP
void me_atk_up(int sp, struct class *me); // increases me ATK
void caduceus(int sp); // attack with a chance of stunning an enemy
void healer(int sp); // increase healing
void patch_up(int sp); // heal after battle
void me_scavenge(int sp); // increases chance of battle item drop
void me_tp_regen(int sp, struct class *me); // restores TP every turn
void cure(int sp); // small healing for a party member
void cure_ii(int sp); // medium healing for a party member
void cure_iii(int sp); // full healing for a party member
void salve(int sp); // small healing for entire party
void salve_ii(int sp); // medium healing for entire party
void unbind(int sp); // removes binds from a party member
void immunize(int sp); // increases elemental resistance for party
void refresh(int sp); // remove amount of debufs from party member as SP val
void regen(int sp); // small healing for a party member each turn
void cpr(int sp); // chance for entire party to survive mortal blows with 1 HP
void revive(int sp); // revive party member from the dead
void h_touch(int sp); // healing for a party member outside battle for small TP
void me_chop(int sp); // Chop wood for materials at item points
