.set LOCALID_WOMAN, 5
.set LOCALID_OLD_MAN_LYING_DOWN,  4
.set LOCALID_OLD_MAN_2,  5

CiudadVerde_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CiudadVerde_OnTransition
	.byte 0

CiudadVerde_OnTransition::
	setflag FLAG_VISITED_VIRIDIAN_CITY
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN_POTION, 1, CiudadVerde_EventScript_AncianoEnPie
	end

CiudadVerde_EventScript_AncianoEnPie::
	setobjectxyperm LOCALID_OLD_MAN_2, 21, 11
	setobjectmovementtype LOCALID_OLD_MAN_2, MOVEMENT_TYPE_LOOK_AROUND
	return

CiudadVerde_EventScript_CaminoBloqueado::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox CiudadVerde_Text_EstoEsPropiedadPrivada
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CiudadVerde_Movement_MovAbajo
	waitmovement 0
	releaseall
	end

CiudadVerde_EventScript_AncianoTirado::
	msgbox CiudadVerde_Text_EstoEsPropiedadPrivada
	closemessage
	release
	end

CiudadVerde_EventScript_Mujer::
	lock
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, CiudadVerde_EventScript_MujerCaminoBloqueado
	faceplayer
	msgbox CiudadVerde_Text_Mujer_2
	release
	end

CiudadVerde_EventScript_MujerCaminoBloqueado::
	msgbox CiudadVerde_Text_Mujer_1
	faceplayer
	msgbox CiudadVerde_Text_Mujer_3
	closemessage
	applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CiudadVerde_EventScript_AncianoPocion_Derecha::
	lockall
	applymovement LOCALID_OLD_MAN_2, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox CiudadVerde_Text_Anciano_Derecha
	giveitem ITEM_POTION
	msgbox CiudadVerde_Text_Anciano_Derecha_2
	closemessage
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN_POTION, 2
	release
	end

CiudadVerde_EventScript_AncianoPocion::
    faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN_POTION, 2, CiudadVerde_EventScript_AncianoEnPie2
	msgbox CiudadVerde_Text_Anciano_Derecha
	giveitem ITEM_POTION
	msgbox CiudadVerde_Text_Anciano_Derecha_2
	closemessage
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	release
	end

CiudadVerde_EventScript_AncianoEnPie2::
	msgbox CiudadVerde_Text_Anciano_2 MSGBOX_NPC
	release
	end

CiudadVerde_EventScript_Chico::
	msgbox CiudadVerde_Text_Chico, MSGBOX_NPC
	end

CiudadVerde_EventScript_AncianoGimnasio::
	msgbox CiudadVerde_Text_Anciano_1
	release
	end

CiudadVerde_EventScript_Joven::
	lock
	faceplayer
	msgbox CiudadVerde_Text_Joven_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CiudadVerde_EventScript_DiferenciasEntreBichos
	goto_if_eq VAR_RESULT, NO, CiudadVerde_EventScript_NoGracias
	end

CiudadVerde_EventScript_DiferenciasEntreBichos::
	msgbox CiudadVerde_Text_Joven_2
	release
	end

CiudadVerde_EventScript_NoGracias::
	msgbox CiudadVerde_Text_Joven_3
	release
	end

CiudadVerde_EventScript_PistasEntrenador::
	msgbox CiudadVerde_Text_Cartel_1
	release
	end

CiudadVerde_EventScript_CartelDePueblo::
	msgbox CiudadVerde_Text_Cartel_2
	release
	end

CiudadVerde_EventScript_PistasEntrenador2::
	msgbox CiudadVerde_Text_Cartel_3
	release
	end

CiudadVerde_FindItem_Pocion::
	finditem ITEM_POTION, 1
	end

CiudadVerde_Text_Mujer_1::
    .string "{COLOR RED}¡Oh, abuelo!\n"
    .string "¡No seas tan malo!$"

CiudadVerde_Text_Mujer_2::
    .string "{COLOR RED}Cuando voy de compras a\n"
    .string "Ciudad Plateada, tomo el sinuoso\l"
    .string "camino del Bosque Verde.$"

CiudadVerde_Text_Mujer_3::
    .string "{COLOR RED}Lo siento, todavía no se ha tomado\n"
    .string "su café…$"

CiudadVerde_Text_EstoEsPropiedadPrivada::
    .string "{COLOR BLUE}¡Oye! ¡No puedes pasar por aquí!\p"
    .string "¡Es propiedad privada!$"

CiudadVerde_Text_Chico::
    .string "{COLOR BLUE}Estás llevando Pokébolas,\n"
    .string "¿verdad?\p"
    .string "¡Entonces tú tienes Pokémon!\p"
    .string "Es genial poder llevar y usar los\n"
    .string "Pokémon en cualquier momento\l"
    .string "y lugar.$"

CiudadVerde_Text_Anciano_1::
    .string "{COLOR BLUE}Este Gimnasio siempre está\n"
    .string "cerrado\p"
    .string "¿Quién será el líder?$"

CiudadVerde_Text_Anciano_2::
    .string "{COLOR BLUE}¡Hola! ¡Chico!\n"
    .string "¿Cómo va la Pokédex?$"

CiudadVerde_Text_Joven_1::
    .string "{COLOR BLUE}Hola, ¿Quieres saber algo\n"
    .string "sobre los 2 tipos de orugas\l"
    .string "Pokémon de Kanto?$"

CiudadVerde_Text_Joven_2::
    .string "{COLOR BLUE}¡Caterpie no tiene veneno; pero\n"
    .string "Weedle, sí!\p"
    .string "¡Ten cuidado con su Picotazo\n"
    .string "Venenoso!$"

CiudadVerde_Text_Joven_3::
    .string "{COLOR BLUE}Bueno, pues nada…$"

CiudadVerde_Text_Cartel_1::
    .string "Pistas Entrenador\p"
    .string "La cantidad de veces que un Pokémon\n"
    .string "puede ejecutar un movimiento\l"
    .string "está limitada por los PPs.\p"
    .string "Para restaurarlos acude al\n"
    .string "Centro Pokémon.$"

CiudadVerde_Text_Cartel_2::
    .string "Ciudad Verde\n"
    .string "El eterno paraíso verde.$"

CiudadVerde_Text_Cartel_3::
    .string "Pistas Entrenador\p"
    .string "¡Atrapa los Pokémon y amplía\n"
    .string "tu colección!\p"
    .string "¡Cuantos más tengas, más fácil\n"
    .string "te será luchar!$"

CiudadVerde_Text_Anciano_Derecha::
    .string "{COLOR BLUE}¡Ahh! ¡Después de tomarme mi café,\n"
    .string "me siento genial!\p"
    .string "Bueno, ¡Puedes pasar!\p"
    .string "Lamento ser tan rudo contigo...\p"
    .string "¿Mmm?, ¿Y esa caja roja que llevas\n"
    .string "ahí?\p"
    .string "Ah, así que estás trabajando\n"
    .string "en tu Pokédex...\p"
    .string "¡Bien! ¡Déjame darte un consejo\n"
    .string "chico!\p"
    .string "Siempre debes llevar contigo una\n"
    .string "de estas...$"

CiudadVerde_Text_Anciano_Derecha_2::
    .string "{COLOR BLUE}¡Las Pociones pueden llegar a\n"
    .string "salvarte en determinadas\l"
    .string "Situaciones!\p"
    .string "Te servirán bastante\n"
    .string "en tu aventura.\p"
	.string "¡Ten eso en cuenta!$"

CiudadVerde_Movement_MovAbajo::
	walk_down
	step_end
