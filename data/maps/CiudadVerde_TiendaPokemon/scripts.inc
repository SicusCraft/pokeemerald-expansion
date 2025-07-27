.set LOCALID_CLERK, 1

CiudadVerde_TiendaPokemon_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CiudadVerde_TiendaPokemon_OnFrame
	.byte 0

CiudadVerde_TiendaPokemon_OnFrame::
	map_script_2 VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 0, CiudadVerde_TiendaPokemon_EventScript_CorreoDeOak
	.2byte 0

CiudadVerde_TiendaPokemon_EventScript_CorreoDeOak::
	lockall
	turnobject LOCALID_CLERK, DIR_SOUTH
	msgbox CiudadVerde_TiendaPokemon_Text_Empleado_1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CiudadVerde_TiendaPokemon_Movement_Player_1
	waitmovement 0
	turnobject LOCALID_CLERK, DIR_EAST
	msgbox CiudadVerde_TiendaPokemon_Text_Empleado_2, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message CiudadVerde_TiendaPokemon_Text_CorreoDeOak
	waitmessage
	waitfanfare
	msgbox CiudadVerde_TiendaPokemon_Text_Empleado_3, MSGBOX_DEFAULT
	closemessage
	additem ITEM_OAKS_PARCEL
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 2
	setvar VAR_MAP_SCENE_POKEDEX, 1
	release
	end

CiudadVerde_TiendaPokemon_EventScript_Empleado_1::
	lock
	faceplayer
	goto_if_le VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 2, CiudadVerde_TiendaPokemon_EventScript_Empleado_2
	message gText_HowMayIServeYou
	waitmessage
	pokemart CiudadVerde_TiendaPokemon_Items
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

CiudadVerde_TiendaPokemon_EventScript_Empleado_2::
	msgbox CiudadVerde_TiendaPokemon_Text_Empleado_3, MSGBOX_DEFAULT
	release
	end

CiudadVerde_TiendaPokemon_EventScript_Chica::
	msgbox CiudadVerde_TiendaPokemon_Text_Chica_1, MSGBOX_NPC
	end

CiudadVerde_TiendaPokemon_EventScript_Joven::
	msgbox CiudadVerde_TiendaPokemon_Text_Joven, MSGBOX_NPC
	end

CiudadVerde_TiendaPokemon_Text_Empleado_1::
    .string "{COLOR BLUE}¡Oye Chico!\n"
    .string "¿Vives en Pueblo Paleta?\p"
    .string "… …\p"
    .string "¡Bien! ¿Puedes hacerme un\n"
    .string "pequeño favor?$"

CiudadVerde_TiendaPokemon_Text_Empleado_2::
    .string "{COLOR BLUE}¿Conoces al Profesor Oak?\p"
    .string "Tiene correo.\n"
    .string "¿Se lo puedes llevar por mí?$"

CiudadVerde_TiendaPokemon_Text_CorreoDeOak::
    .string "¡El empleado de la Tienda Pkmn le\n"
    .string "dio a {PLAYER} el Correo de Oak!$"

CiudadVerde_TiendaPokemon_Text_Empleado_3::
    .string "{COLOR BLUE}¡Gracias por la ayuda Chico!\n"
    .string "¿Puedes saludar al Prof.Oak de\l"
    .string "mi parte?$"

CiudadVerde_TiendaPokemon_Text_Chica_1::
    .string "{COLOR RED}En esta tienda venden muchos\n"
    .string "Antídotos, creo.$"

CiudadVerde_TiendaPokemon_Text_Joven::
    .string "{COLOR BLUE}Yo tengo algunas Pociones.\p"
    .string "Nunca sabes cuándo pueden\n"
    .string "necesitarlas tus Pokémon.$"

CiudadVerde_TiendaPokemon_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_NONE
	release
	end

CiudadVerde_TiendaPokemon_Movement_Player_1::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end