.set LOCALID_TOWN_MAP, 1
.set LOCALID_DAISY,    2

PuebloPaleta_CasaDeRival_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, PuebloPaleta_CasaDeRival_OnTransition
	.byte 0

PuebloPaleta_CasaDeRival_OnTransition::
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PuebloPaleta_CasaDeRival_EventScript_DaisyEnLaMesa
	end

PuebloPaleta_CasaDeRival_EventScript_DaisyEnLaMesa::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_DAISY, 5, 4
	return

PuebloPaleta_CasaDeRival_EventScript_Daisy::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PuebloPaleta_CasaDeRival_EventScript_Daisy2
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, PuebloPaleta_CasaDeRival_EventScript_DaisyMapa
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PuebloPaleta_CasaDeRival_EventScript_LuchasteContraAzul
	msgbox PuebloPaleta_CasaDeRival_Text_Daisy1
	closemessage
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PuebloPaleta_CasaDeRival_EventScript_LuchasteContraAzul::
	msgbox PalletTown_RivalsHouse_Text_Daisy2
	release
	end

PuebloPaleta_CasaDeRival_EventScript_Daisy2::
	msgbox PalletTown_RivalsHouse_Text_Daisy5
	release
	end

PuebloPaleta_CasaDeRival_EventScript_DaisyMapa::
	msgbox PalletTown_RivalsHouse_Text_Daisy3
	closemessage
	checkitemspace ITEM_TOWN_MAP
	applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	removeobject LOCALID_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	delay 15
	applymovement LOCALID_DAISY, Common_Movement_FacePlayer
	waitmovement 0
	delay 12
	giveitem ITEM_TOWN_MAP
	msgbox PalletTown_RivalsHouse_Text_Daisy4
	setflag FLAG_HIDE_TOWN_MAP
	release
	end

PuebloPaleta_CasaDeRival_EventScript_CuadroCleafairy::
	msgbox PalletTown_RivalsHouse_Text_Cuadro
	release
	end

PuebloPaleta_CasaDeRival_EventScript_MapaDeKanto::
	msgbox PalletTown_RivalsHouse_Text_Mapa
	release
	end

PuebloPaleta_CasaDeRival_Text_Daisy1::
    .string "{COLOR RED}Daisy: ¡Hola, {PLAYER}!\p"
    .string "Mi hermano, Azul, está en\n"
    .string "el Laboratorio del Abuelo.$"

PalletTown_RivalsHouse_Text_Daisy2::
    .string "{COLOR RED}Daisy: ¡{PLAYER}, eh oído que\n"
    .string "luchaste contra Azul!\p"
    .string "Ojalá haber visto eso.$"

PalletTown_RivalsHouse_Text_Daisy3::
    .string "{COLOR RED}Daisy: ¿Te encargó algo el abuelo?\p"
    .string "¡Toma esto!\n"
    .string "¡Te ayudará!$"

PalletTown_RivalsHouse_Text_Daisy4::
    .string "{COLOR RED}Daisy: Usa el Mapa para saber\n"
    .string "dónde te encuentras.$"

PalletTown_RivalsHouse_Text_Daisy5::
    .string "{COLOR RED}Daisy: ¡Hola, {PLAYER}!\p"
    .string "Estaba por tomar un poco\n"
    .string "de té.\p"
    .string "¿Quieres uno?$"

PalletTown_RivalsHouse_Text_Cuadro::
    .string "“El Cariñoso y dulce\n"
    .string "Clefairy”$"

PalletTown_RivalsHouse_Text_Mapa::
    .string "Es un gran mapa de Kanto.\n"
    .string "¡Qué útil!$"
