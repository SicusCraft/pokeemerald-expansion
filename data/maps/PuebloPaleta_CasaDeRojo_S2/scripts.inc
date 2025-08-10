PuebloPaleta_CasaDeRojo_S2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PuebloPaleta_CasaDeRojo_S2_OnTransition
	.byte 0

PuebloPaleta_CasaDeRojo_S2_OnTransition::
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PuebloPaleta_CasaDeRojo_S2_EventScript_SetRespawn
	end

PuebloPaleta_CasaDeRojo_S2_EventScript_SetRespawn::
	setrespawn HEAL_LOCATION_PUEBLO_PALETA
	return

PuebloPaleta_CasaDeRojo_S2_EventScript_Nintendo::
	msgbox PuebloPaleta_CasaDeRojo_S2_Text_Nes, MSGBOX_SIGN
	end

PuebloPaleta_CasaDeRojo_S2_EventScript_Cartel::
	msgbox PuebloPaleta_CasaDeRojo_S2_Text_CartelVacio, MSGBOX_SIGN
	end

PuebloPaleta_CasaDeRojo_S2_EventScript_PC::
	setvar VAR_0x8004, PC_LOCATION_REDS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox PuebloPaleta_CasaDeRojo_S2_Text_PC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

PuebloPaleta_CasaDeRojo_S2_EventScript_PC_Apagada::
	setvar VAR_0x8004, PC_LOCATION_REDS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

PuebloPaleta_CasaDeRojo_S2_Text_CartelVacio:
	.string "Anda, una nota…\p"
	.string "…\p"
	.string "Parece estar vacía…$"

PuebloPaleta_CasaDeRojo_S2_Text_PC:
	.string "{PLAYER} encendió el PC.$"

PuebloPaleta_CasaDeRojo_S2_Text_Nes:
	.string "¡{PLAYER} está jugando a la Nes!\p"
	.string "Bueno, más vale que me ponga\n"
	.string "en marcha.$"
