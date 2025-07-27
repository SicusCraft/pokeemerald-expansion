.set LOCALID_NURSE, 1

CiudadVerde_CentroPokemon_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CiudadVerde_CentroPokemon_OnTransition
	.byte 0

CiudadVerde_CentroPokemon_OnTransition::
	setrespawn HEAL_LOCATION_CIUDAD_VERDE
	end

CiudadVerde_CentroPokemon_EventScript_Enfermera::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

CiudadVerde_CentroPokemon_EventScript_Chico::
	msgbox CiudadVerde_CentroPokemon_Text_Chico, MSGBOX_NPC
	end

CiudadVerde_CentroPokemon_EventScript_Caballero::
	msgbox CiudadVerde_CentroPokemon_Text_Caballero, MSGBOX_NPC
	end

CiudadVerde_CentroPokemon_EventScript_Joven::
	msgbox CiudadVerde_CentroPokemon_Text_Joven, MSGBOX_NPC
	end

CiudadVerde_CentroPokemon_Text_Caballero::
    .string "{COLOR BLUE}Sientete libre de usar la Pc\n"
    .string "de la esquina.\p"
    .string "¡Eso me dijo la recepcionista!\n"
    .string "¡Es muy amable!$"

CiudadVerde_CentroPokemon_Text_Chico::
    .string "{COLOR BLUE}En cada Ciudad de Kanto hay un\n"
    .string "Centro Pokémon.\p"
    .string "Son gratuitos, Así que no\n"
    .string "tengas pena en pedir que\l"
    .string "curen a tus Pokémon$"

CiudadVerde_CentroPokemon_Text_Joven::
    .string "{COLOR BLUE}¡Los Centros Pokémon curan a tus\n"
    .string "Pokémon heridos o debilitados!$"
