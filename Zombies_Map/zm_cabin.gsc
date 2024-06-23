#using scripts\codescripts\struct;

#using scripts\shared\array_shared;
#using scripts\shared\callbacks_shared;
#using scripts\shared\clientfield_shared;
#using scripts\shared\compass;
#using scripts\shared\exploder_shared;
#using scripts\shared\flag_shared;
#using scripts\shared\laststand_shared;
#using scripts\shared\math_shared;
#using scripts\shared\scene_shared;
#using scripts\shared\util_shared;

#insert scripts\shared\shared.gsh;
#insert scripts\shared\version.gsh;

#insert scripts\zm\_zm_utility.gsh;

#using scripts\zm\_load;
#using scripts\zm\_zm;
#using scripts\zm\_zm_audio;
#using scripts\zm\_zm_powerups;
#using scripts\zm\_zm_utility;
#using scripts\zm\_zm_weapons;
#using scripts\zm\_zm_zonemgr;

#using scripts\shared\ai\zombie_utility;

//Perks
#using scripts\zm\_zm_pack_a_punch;
#using scripts\zm\_zm_pack_a_punch_util;
#using scripts\zm\_zm_perk_additionalprimaryweapon;
#using scripts\zm\_zm_perk_doubletap2;
#using scripts\zm\_zm_perk_deadshot;
#using scripts\zm\_zm_perk_juggernaut;
#using scripts\zm\_zm_perk_quick_revive;
#using scripts\zm\_zm_perk_sleight_of_hand;
#using scripts\zm\_zm_perk_staminup;
#using scripts\zm\_zm_perk_electric_cherry;
#using scripts\zm\_zm_perk_widows_wine;
#using scripts\zm\_zm_perk_vulture_aid;
#using scripts\zm\_zm_perk_whoswho;
#using scripts\zm\_zm_perk_tombstone;
#using scripts\zm\_zm_perk_phdflopper;
#using scripts\zm\_zm_perk_elemental_pop;
#using scripts\zm\_zm_perk_random;

//Powerups
#using scripts\zm\_zm_powerup_double_points;
#using scripts\zm\_zm_powerup_carpenter;
#using scripts\zm\_zm_powerup_fire_sale;
#using scripts\zm\_zm_powerup_free_perk;
#using scripts\zm\_zm_powerup_full_ammo;
#using scripts\zm\_zm_powerup_insta_kill;
#using scripts\zm\_zm_powerup_nuke;
#using scripts\zm\_zm_powerup_weapon_minigun;


//Traps
#using scripts\zm\_zm_trap_electric;

#using scripts\zm\zm_usermap;

#using scripts\zm\_hb21_zm_magicbox;

#using scripts\zm\_zm_spawner;

#using scripts\zm\_zm_perks;

//*****************************************************************************
// MAIN
//*****************************************************************************

function main()
{
	zm_usermap::main();
	
	level._zombie_custom_add_weapons =&custom_add_weapons;
	level.player_starting_points = 50000;
	level.perk_purchase_limit = 20;
	level.start_weapon = GetWeapon("t9_pi_1911");
	level thread free_perk_easteregg();
	
	//Setup the levels Zombie Zone Volumes
	level.zones = [];
	level.zone_manager_init_func =&usermap_test_zone_init;
	init_zones[0] = "start_zone";
	level thread zm_zonemgr::manage_zones( init_zones );


	level.pathdist_type = PATHDIST_ORIGINAL;

	say_hello();
}

function usermap_test_zone_init()
{
	zm_zonemgr::add_adjacent_zone("start_zone", "z2", "ez2");
	zm_zonemgr::add_adjacent_zone("start_zone", "z2b", "ez2");
	zm_zonemgr::add_adjacent_zone("z2", "z3", "ez3");

	level flag::init( "always_on" );
	level flag::set( "always_on" );
}	

function custom_add_weapons()
{
	zm_weapons::load_weapon_spec_from_table("gamedata/weapons/zm/zm_levelcommon_weapons.csv", 1);
}

function say_hello()
{
	wait(5);
	IPrintLnBold( "Welcome to The Cabin!" );
}

function free_perk_easteregg()
{
	trigs = GetEntArray("free_perk_trigs", "targetname");

	level.perk_trigs_activated = 0;

	foreach(trig in trigs)
	{
		trig thread activate_trigger();
	}
}

function activate_trigger()
{
	self SetHintString("Hold ^3[{+activate}]^7 to activate");
	self SetCursorHint("HINT_NOICON");
	self UseTriggerRequireLookAt();
	self TriggerEnable(false);
	level waittill("power_on");
	self TriggerEnable(true);
	self waittill("trigger", player);
	self Delete();
	level.perk_trigs_activated ++;

	if(level.perk_trigs_activated == 3)
	{
		foreach(player in GetPlayers())
		{
			player zm_perks::give_random_perk();	
		}
	}
}