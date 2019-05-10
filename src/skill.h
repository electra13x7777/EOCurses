// File: skill.h
// Author: Alex Barney
//
// Description: Prototypes skills

// Alchemist
void al_tp_up(struct class *c); // increases alc TP
void fire_up(struct class *c, int fd); // increases Fire
void ice_up(struct class *c, int id); // increases Ice
void volt_up(struct class *c, int vd); // increases Volt
void toxins(struct class *c); // increases Poison
void al_scavenge(struct class *c); // increases chance of battle item drop
void al_tp_regen(struct class *c); // restores TP every turn
void fire(struct class *c); // fire damage
void flame(struct class *c); // large fire damage
void inferno(struct class *c); // large multitarget fire damage
void ice(struct class *c); // ice damage
void freeze(struct class *c); // large ice damage
void cocytus(struct class *c); // large multitarget ice damage
void volt(struct class *c); // volt damage
void thunder(struct class *c); // large volt damage
void thor(struct class *c); // large multitarget volt damage
void poison(struct class *c); // inflicts poison
void venom(struct class *c); // inflicts poison to multiple targets
void sight(struct class *c); // see all FOEs on the map
void warp(struct class *c); // warp to the last visited Geomagnetic Field
void al_chop(struct class *c); // Chop wood for materials at item points

// Dark Hunter
void dh_hp_up(struct class *c); // increases dh HP
void dh_tp_up(struct class *c); // increases dh TP
void dh_atk_up(struct class *c); // increases dh ATK
void dh_whips(struct class *c); // increases whip damage
void dh_swords(struct class *c); // increases sword damage
void dh_boost_up(struct class *c); // increase the improvement gained when boosted
void fury(struct class *c); // increase damage dealt when HP is low
void dh_cloak(struct class *c); // enemy won’t target you
void viper(struct class *c); // whip attack with a chance of poisoning the enemy
void gag(struct class *c); // whip attack with a chance of binding the enemy's head
void shackles(struct class *c); // whip attack with a chance of binding the enemy's legs
void cuffs(struct class *c); // whip attack with a chance of binding the enemy's arms
void ecstacy(struct class *c); // whip attack that does a ton of damage to enemy w/ 3 binds
void climax(struct class *c); // whip skill that may kill and drain enemies with low HP
void hypnos(struct class *c); // sword stab with a chance of putting the enemy to sleep
void nerve(struct class *c); //sword stab at enemy’s nerves with a chance of paralyzing it
void mirage(struct class *c); // sword stab at enemy’s skull with a chance of confusing it
void drain(struct class *c); // sword stab that drains the enemy’s HP through the blade
void bait(struct class *c); //sword skill that uses comrades on either side to bait a trap
void petrify(struct class *c); //sword stab at enemy’s muscles with a chance of stoning
void dh_take(struct class *c); // gather plants for materials at item points

// Landsknecht
void la_hp_up(struct class *c); // increases la HP
void la_tp_up(struct class *c); // increases la TP
void la_atk_up(struct class *c); // increases la ATK
void la_def_up(struct class *c); // increases la DEF
void la_axes(struct class *c); // increases axe damage
void la_swords(struct class *c); // increases sword damage
void 2_hit(struct class *c); // normal weapon attacks have a chance of hitting twice
void war_cry(struct class *c); // increase attack power at the expense of defense
void hell_cry(struct class *c); // abandon defense and stamina for greatly strength attack
void arm_heal(struct class *c); // regain the use of bound arms
void flee(struct class *c); // sacrifice HP to escape from battle to the previous floor
void cleaver(struct class *c, struct enemy *e); // a rushing sword slash
void tornado(struct class *c, struct enemy *e); // a whirling sword skill that strikes adjacent enemies
void allslash(struct class *c); // a sword skill that hits a group of enemies 2-4 times
void blazer(struct class *c); // sword skill that follows fire magic with a flaming slash
void freezer(struct class *c); //sword skill that follows fire magic with a freezing slash
void shocker(struct class *c); //sword skill that follows fire magic with a shocking slash
void crush(struct class *c); // a charging axe strike
void stunner(struct class *c); // an axe attack that puts the enemy off-balance
void silencer(struct class *c); // an axe skill with a chance of binding the enemy's head
void la_mine(struct class *c); // mine for materials at item points

// Survivalist
void su_hp_up(struct class *c); // increases su HP
void su_tp_up(struct class *c); // increases su TP
void su_agi_up(struct class *c); // increases su AGI
void su_bows(struct class *c); // increases bow damage
void ambush(struct class *c); // increase premptive chance
void aware(struct class *c); // decreases enemy premptive chance
void 1st_hit(struct class *c); // chance of acting first next turn
void trickery(struct class *c); // lowers all enemy accuracy
void quicken(struct class *c); // increases speed of party
void su_cloak(struct class *c); // enemy won’t target you
void escape(struct class *c); // increase escape chance
void 1st_turn(struct class *c); // targeted party member will act just after you cast
void trueshot(struct class *c); // powerful, piercing bow skill
void multihit(struct class *c); // fires 2-3 shots at once
void disable(struct class *c); // damage and chance to bind legs
void apollon(struct class *c); // the ultimate bow skill that takes 3 turns
void owl_eye(struct class *c); // able to see far away FOEs
void su_stalker(struct class *c); // reduces enemy encounter rate
void su_chop(struct class *c); // Chop wood for materials at item points
void su_mine(struct class *c); // mine for materials at item points
void su_take(struct class *c); // gather plants for materials at item points

// Troubadour
void tr_hp_up(struct class *c); // increases tr HP
void tr_tp_up(struct class *c); // increases tr TP
void songs(struct class *c); // needed to learn songs
void divinity(struct class *c); // increases exp gain for entire party
void bravery(struct class *c); // increases strength for entire party
void shelter(struct class *c); // increases defense for entire party
void mercury(struct class *c); // increases speed for entire party
void erasure(struct class *c); // removes buffs from all enemies
void recovery(struct class *c); // allows the entire party to recover from status ailments quicker
void stamina(struct class *c); // increases max HP for entire party
void blaze(struct class *c); // adds the element of fire to one party member's weapon
void frost(struct class *c); // adds the element of ice to one party member's weapon
void shock(struct class *c); // adds the element of lightning to one party member's weapon
void ifrit(struct class *c); // increases fire resistance for entire party/decreases for enemies
void ymir(struct class *c); // increases ice resistance for entire party/decreases for enemies
void taranis(struct class *c); // increases volt resistance for entire party/decreases for enemies
void healing(struct class *c); // small amount of HP is restored to the entire party every turn
void relaxing(struct class *c); // small amount of TP is restored to the entire party every turn
void tr_stalker(struct class *c); // reduces enemy encounter rate
void tr_return(struct class *c); // takes party back to previous floor
void tr_take(struct class *c); // gather plants for materials at item points

// Medic
void me_hp_up(struct class *c); // increases me HP
void me_tp_up(struct class *c); // increases me TP
void me_atk_up(struct class *c); // increases me ATK
void caduceus(struct class *c); // attack with a chance of stunning an enemy
void healer(struct class *c); // increase healing
void patch_up(struct class *c); // heal after battle
void me_scavenge(struct class *c); // increases chance of battle item drop
void me_tp_regen(struct class *c); // restores TP every turn
void cure(struct class *c); // small healing for a party member
void cure_ii(struct class *c); // medium healing for a party member
void cure_iii(struct class *c); // full healing for a party member
void salve(struct class *c); // small healing for entire party
void salve_ii(struct class *c); // medium healing for entire party
void unbind(struct class *c); // removes binds from a party member
void immunize(struct class *c); // increases elemental resistance for party
void refresh(struct class *c); // remove amount of debufs from party member as SP val
void regen(struct class *c); // small healing for a party member each turn
void cpr(struct class *c); // chance for entire party to survive mortal blows with 1 HP
void revive(struct class *c); // revive party member from the dead
void h_touch(struct class *c); // healing for a party member outside battle for small TP
void me_chop(struct class *c); // Chop wood for materials at item points
