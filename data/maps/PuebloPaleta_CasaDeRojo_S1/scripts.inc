PuebloPaleta_CasaDeRojo_S1_MapScripts::
	.byte 0

PuebloPaleta_CasaDeRojo_S1_EventScript_Tv::
	msgbox PuebloPaleta_CasaDeRojo_S1_Text_Television, MSGBOX_SIGN
	end

PuebloPaleta_CasaDeRojo_S1_EventScript_Madre::
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PuebloPaleta_CasaDeRojo_S1_EventScript_MadreCuracion
	msgbox PuebloPaleta_CasaDeRojo_S1_Text_Madre, MSGBOX_NPC
	end

PuebloPaleta_CasaDeRojo_S1_EventScript_MadreCuracion::
	msgbox PuebloPaleta_CasaDeRojo_S1_Text_Madre_2, MSGBOX_NPC
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox PuebloPaleta_CasaDeRojo_S1_Text_Madre_3
	release
	end

PuebloPaleta_CasaDeRojo_S1_Text_Television:
	.string "¡Hay una pelí en la TV!\n"
	.string "Cuatro niños caminan sobre vías\l"
	.string "de tren.\p"
	.string "Bueno, mejor me pongo en marcha…$"

PuebloPaleta_CasaDeRojo_S1_Text_Madre:
	.string "{COLOR RED}Mamá: En fin…\n"
	.string "Todos los niños se van de casa\l"
	.string "algún día. ¡Así es la vida!\p"
	.string "Ah, nuestro vecino, el Prof. Oak,\n"
	.string "quería verte.$"

PuebloPaleta_CasaDeRojo_S1_Text_Madre_2:
	.string "{COLOR RED}Mamá: ¡{PLAYER}!\n"
	.string "Deberías tomarte un descanso.$"

PuebloPaleta_CasaDeRojo_S1_Text_Madre_3:
	.string "{COLOR RED}Mamá: ¡Muy bien! ¡Tú y tus\n"
	.string "Pokémon estan en plena forma!\p"
	.string "¡Cuídate!$"
