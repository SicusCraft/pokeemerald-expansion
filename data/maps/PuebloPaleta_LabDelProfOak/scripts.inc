.set LOCALID_PROF_OAK,  5
.set LOCALID_RIVAL,  4
.set LOCALID_POKEDEX_1,  7
.set LOCALID_POKEDEX_2,  6

PuebloPaleta_LabDelProfOak_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PuebloPaleta_LabDelProfOak_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PuebloPaleta_LabDelProfOak_OnFrame
	.byte 0

PuebloPaleta_LabDelProfOak_OnTransition::
    setflag FLAG_VISITED_OAKS_LAB
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PuebloPaleta_LabDelProfOak_EventScript_Posicion_Oak
	end

PuebloPaleta_LabDelProfOak_OnFrame:
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PuebloPaleta_LabDelProfOak_EventScript_PikachuEcena
	.2byte 0

PuebloPaleta_LabDelProfOak_EventScript_Posicion_Oak::
	setobjectxyperm LOCALID_PROF_OAK, 6, 11
	savebgm MUS_FOLLOW_ME
	return

PuebloPaleta_LabDelProfOak_EventScript_PikachuEcena::
	lockall
	applymovement LOCALID_PROF_OAK, PuebloPaleta_LabDelProfOak_Movement_OakMov1
	waitmovement 0
	removeobject LOCALID_PROF_OAK
	setobjectxyperm LOCALID_PROF_OAK, 6, 3
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
	applymovement OBJ_EVENT_ID_PLAYER, PuebloPaleta_LabDelProfOak_Movement_PlayerMov1
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceLeft
	waitmovement 0
	clearflag FLAG_DONT_TRANSITION_MUSIC
	savebgm MUS_DUMMY
	fadedefaultbgm
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_2
	closemessage
	delay 15
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_1
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_2
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_3
	playse SE_PIN
	applymovement LOCALID_PROF_OAK, Common_Movement_ExclamationMark
	waitmovement 0
	delay 40
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_3
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_4
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceDown
	waitmovement 0
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_5
	givemon SPECIES_PIKACHU, 5
	playfanfare MUS_LEVEL_UP
	message PuebloPaleta_LabDelProfOak_Text_PikachuObtenido
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_PIKACHU
	msgbox PuebloPaleta_LabDelProfOak_Text_NombreDePikachu, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PuebloPaleta_LabDelProfOak_EventScript_NombreDePikachu
	goto_if_eq VAR_RESULT, NO, PuebloPaleta_LabDelProfOak_EventScript_ReaccionDeAzul
	end
	
PuebloPaleta_LabDelProfOak_EventScript_NombreDePikachu::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto PuebloPaleta_LabDelProfOak_EventScript_ReaccionDeAzul
	end

PuebloPaleta_LabDelProfOak_EventScript_ReaccionDeAzul::
	closemessage
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_RIVAL, Common_Movement_FaceRight
	waitmovement 0
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_4
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_6
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2
	setflag FLAG_SYS_POKEMON_GET
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceDown
	waitmovement 0
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_8
	setvar VAR_OAK_LAB_STATE, 1
	callnative UpdateFollowingPokemon
	releaseall
	end

PuebloPaleta_LabDelProfOak_EventScript_Cientifico::
	msgbox PuebloPaleta_LabDelProfOak_Text_Cientifico, MSGBOX_NPC
	end

PuebloPaleta_LabDelProfOak_EventScript_Trabajadora::
	msgbox PuebloPaleta_LabDelProfOak_Text_Chica, MSGBOX_NPC
	end

PuebloPaleta_LabDelProfOak_EventScript_Oak::
    lock
	faceplayer
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_7
	release
	end

PuebloPaleta_LabDelProfOak_EventScript_PokeDexRecibida::
    lock
	applymovement OBJ_EVENT_ID_PLAYER, PuebloPaleta_LabDelProfOak_Movement_PlayerMov3
	waitmovement 0
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_9
	playfanfare MUS_OBTAIN_TMHM
	message PuebloPaleta_LabDelProfOak_Text_CorreoOak
	waitmessage
	waitfanfare
	removeitem ITEM_OAKS_PARCEL
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_10
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_6
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceDown
	waitmovement 0
	setobjectxyperm LOCALID_RIVAL, 5, 11
	addobject LOCALID_RIVAL
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_UP
	applymovement LOCALID_RIVAL, PuebloPaleta_LabDelProfOak_Movement_AzulMov7
	waitmovement 0
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	fadedefaultbgm
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_7
	closemessage
	delay 30
	playse SE_PIN
	applymovement LOCALID_PROF_OAK, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PROF_OAK, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceDown
	waitmovement 0
    delay 10
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceLeft
	waitmovement 0
    delay 10
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceDown
	waitmovement 0
    delay 15
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_11
	closemessage
	applymovement LOCALID_PROF_OAK, PuebloPaleta_LabDelProfOak_Movement_OakMov2
	waitmovement 0
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_12
	closemessage
	delay 40
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_13
	closemessage
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	removeobject LOCALID_POKEDEX_1
	delay 10
	removeobject LOCALID_POKEDEX_2
	delay 25
	applymovement LOCALID_PROF_OAK, PuebloPaleta_LabDelProfOak_Movement_OakMov3
	waitmovement 0
	delay 10
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox PuebloPaleta_LabDelProfOak_Text_Pokedex
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	special EnableNationalPokedex
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_14
	giveitem ITEM_POKE_BALL, 5
	@PuebloPaleta_LabDelProfOak_Text_Pokebolas 
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_15
	msgbox PuebloPaleta_LabDelProfOak_Text_Oak_16
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_8
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_9
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_RIVAL, PuebloPaleta_LabDelProfOak_Movement_AzulMov8
	waitmovement 0
	removeobject LOCALID_RIVAL
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 3
	setvar VAR_MAP_SCENE_POKEDEX, 2
	setflag FLAG_HIDE_POKEDEX_ON_TABLE
    setflag FLAG_HIDE_OLD_MAN_LYING_DOWN
	clearflag FLAG_HIDE_OLD_MAN_IN_VIRIDIAN_CITY
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN_POTION, 1
	setvar VAR_MAP_SCENE_ROUTE22, 1
	fadedefaultbgm
	release
	end

PuebloPaleta_LabDelProfOak_EventScript_Azul::
    lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PuebloPaleta_LabDelProfOak_EventScript_AzulPresumiendo
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_1
	release
	end

PuebloPaleta_LabDelProfOak_EventScript_AzulPresumiendo::
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_5
	release
	end

PuebloPaleta_LabDelProfOak_EventScript_BatallaConAzulMedio::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	delay 8
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_Pre_Batalla
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement LOCALID_RIVAL, PuebloPaleta_LabDelProfOak_Movement_AzulMov1
	waitmovement 0
	trainerbattle_no_whiteout_continue_script TRAINER_BLUE, PuebloPaleta_LabDelProfOak_Text_Azul_Batalla1, PuebloPaleta_LabDelProfOak_Text_Azul_Batalla2, PuebloPaleta_LabDelProfOak_EventScript_AzulSePira 
	end

PuebloPaleta_LabDelProfOak_EventScript_AzulSePira::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PuebloPaleta_LabDelProfOak_EventScript_AzulDerrotado
	goto PuebloPaleta_LabDelProfOak_EventScript_AzulVictorioso
	end

PuebloPaleta_LabDelProfOak_EventScript_BatallaConAzulIzquierda::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	delay 8
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_Pre_Batalla
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement LOCALID_RIVAL, PuebloPaleta_LabDelProfOak_Movement_AzulMov3
	waitmovement 0
	trainerbattle_no_whiteout_continue_script TRAINER_BLUE, PuebloPaleta_LabDelProfOak_Text_Azul_Batalla1, PuebloPaleta_LabDelProfOak_Text_Azul_Batalla2, PuebloPaleta_LabDelProfOak_EventScript_AzulSePira2 
	end

PuebloPaleta_LabDelProfOak_EventScript_BatallaConAzulDerecha::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	delay 8
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_Pre_Batalla
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement LOCALID_RIVAL, PuebloPaleta_LabDelProfOak_Movement_AzulMov5
	waitmovement 0
	trainerbattle_no_whiteout_continue_script TRAINER_BLUE, PuebloPaleta_LabDelProfOak_Text_Azul_Batalla1, PuebloPaleta_LabDelProfOak_Text_Azul_Batalla2, PuebloPaleta_LabDelProfOak_EventScript_AzulSePira3 
	end

PuebloPaleta_LabDelProfOak_EventScript_AzulSePira2::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PuebloPaleta_LabDelProfOak_EventScript_AzulDerrotado2
	goto PuebloPaleta_LabDelProfOak_EventScript_AzulVictorioso2
	end

PuebloPaleta_LabDelProfOak_EventScript_AzulSePira3::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PuebloPaleta_LabDelProfOak_EventScript_AzulDerrotado3
	goto PuebloPaleta_LabDelProfOak_EventScript_AzulVictorioso3
	end

PuebloPaleta_LabDelProfOak_EventScript_AzulVictorioso::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_Batalla4, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_RIVAL, PuebloPaleta_LabDelProfOak_Movement_AzulMov2
	waitmovement 0
	removeobject LOCALID_RIVAL
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_OAK_LAB_STATE, 2
	setflag FLAG_HIDE_RIVAL_IN_LAB
	callnative UpdateFollowingPokemon
	releaseall
	end

PuebloPaleta_LabDelProfOak_EventScript_AzulDerrotado::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_Batalla3, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_RIVAL, PuebloPaleta_LabDelProfOak_Movement_AzulMov2
	waitmovement 0
	delay 10
	removeobject LOCALID_RIVAL
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_OAK_LAB_STATE, 2
	setflag FLAG_HIDE_RIVAL_IN_LAB
	releaseall
	end

PuebloPaleta_LabDelProfOak_EventScript_AzulDerrotado2::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_Batalla3, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_RIVAL, PuebloPaleta_LabDelProfOak_Movement_AzulMov4
	waitmovement 0
	delay 10
	removeobject LOCALID_RIVAL
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_OAK_LAB_STATE, 2
	setflag FLAG_HIDE_RIVAL_IN_LAB
	releaseall
	end

PuebloPaleta_LabDelProfOak_EventScript_AzulVictorioso2::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_Batalla4, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_RIVAL, PuebloPaleta_LabDelProfOak_Movement_AzulMov4
	waitmovement 0
	removeobject LOCALID_RIVAL
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_OAK_LAB_STATE, 2
	setflag FLAG_HIDE_RIVAL_IN_LAB
	callnative UpdateFollowingPokemon
	releaseall
	end

PuebloPaleta_LabDelProfOak_EventScript_AzulDerrotado3::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_Batalla3, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_RIVAL, PuebloPaleta_LabDelProfOak_Movement_AzulMov6
	waitmovement 0
	delay 10
	removeobject LOCALID_RIVAL
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_OAK_LAB_STATE, 2
	setflag FLAG_HIDE_RIVAL_IN_LAB
	releaseall
	end

PuebloPaleta_LabDelProfOak_EventScript_AzulVictorioso3::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox PuebloPaleta_LabDelProfOak_Text_Azul_Batalla4, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_RIVAL, PuebloPaleta_LabDelProfOak_Movement_AzulMov6
	waitmovement 0
	removeobject LOCALID_RIVAL
	playse SE_EXIT
	fadedefaultbgm
	setvar VAR_OAK_LAB_STATE, 2
	setflag FLAG_HIDE_RIVAL_IN_LAB
	callnative UpdateFollowingPokemon
	releaseall
	end

PuebloPaleta_LabDelProfOak_EventScript_Pokedex::
	msgbox PuebloPaleta_LabDelProfOak_Text_EnciclopediaEnBlanco, MSGBOX_NPC
	end

PuebloPaleta_LabDelProfOak_Movement_OakMov1::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PuebloPaleta_LabDelProfOak_Movement_OakMov2::
	walk_up
	walk_left
	delay_4
	walk_in_place_down
	step_end

PuebloPaleta_LabDelProfOak_Movement_OakMov3::
	walk_right
	walk_down
	step_end

PuebloPaleta_LabDelProfOak_Movement_PlayerMov1::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PuebloPaleta_LabDelProfOak_Movement_PlayerMov2::
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

PuebloPaleta_LabDelProfOak_Movement_PlayerMov3::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PuebloPaleta_LabDelProfOak_Movement_AzulMov1::
	walk_down
	walk_down
	walk_right
	walk_down
	step_end

PuebloPaleta_LabDelProfOak_Movement_AzulMov2::
    walk_left
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

PuebloPaleta_LabDelProfOak_Movement_AzulMov3::
	walk_down
	walk_down
	walk_down
	step_end

PuebloPaleta_LabDelProfOak_Movement_AzulMov4::
    walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PuebloPaleta_LabDelProfOak_Movement_AzulMov5::
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

PuebloPaleta_LabDelProfOak_Movement_AzulMov6::
    walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PuebloPaleta_LabDelProfOak_Movement_AzulMov7::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PuebloPaleta_LabDelProfOak_Movement_AzulMov8::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PuebloPaleta_LabDelProfOak_Text_Cientifico:
	.string "{COLOR BLUE}Estudio a los Pokémon.\n"
	.string "¡Soy ayudante del Prof. Oak!$"

PuebloPaleta_LabDelProfOak_Text_Chica:
	.string "{COLOR RED}¡El Prof. Oak tiene mucho\n"
	.string "conocimiento sobre los Pokémon!\p"
	.string "¡Es admirado por muchos de los\n"
	.string "Entrenadores Pokémon!$"

PuebloPaleta_LabDelProfOak_Text_Azul_1:
	.string "{COLOR BLUE}Azul: ¡Hola {PLAYER}!\n"
	.string "¡El abuelo no está!$"

PuebloPaleta_LabDelProfOak_Text_Azul_2:
	.string "{COLOR BLUE}Azul: ¡Abuelo! ¿Donde estabas?\n"
	.string "¡Llevo esperándote hace más de\l"
	.string "15 minutos!\p"
	.string "Supuestamente me necesitabas para\n"
	.string "una investigación o algo así, ¿no?$"

PuebloPaleta_LabDelProfOak_Text_Oak_1:
	.string "{COLOR BLUE}Prof.Oak: Es cierto, sí, pero es\n"
	.string "un tema que es mejor tratar luego.\p"
	.string "Aún eres un novato referido a los\n"
	.string "Pokémon, no entenderías mucho.$"

PuebloPaleta_LabDelProfOak_Text_Oak_2:
	.string "{COLOR BLUE}Pero cambiando de tema, {PLAYER},\n"
	.string "Pensabas salir del Pueblo sin un\l"
	.string "Pokémon, ¿Cierto?\p"
	.string "Mal, los Pokémon salvajes son muy\n"
	.string "peligrosos, debes tener cuidado\l"
	.string "con ellos.$"

PuebloPaleta_LabDelProfOak_Text_Oak_3:
	.string "{COLOR BLUE}Por eso, {PLAYER}, en la mesa\n"
	.string "he dejado tres Pokebo…$"

PuebloPaleta_LabDelProfOak_Text_Azul_3:
	.string "{COLOR BLUE}Azul: Parece que ya has entregado\n"
	.string "todos los Pokémon que tenías\l"
	.string "Abuelo.$"

PuebloPaleta_LabDelProfOak_Text_Oak_4:
	.string "{COLOR BLUE}Prof.Oak: Mmm, bueno, no pasa nada.$"

PuebloPaleta_LabDelProfOak_Text_Oak_5:
	.string "{COLOR BLUE}En ese caso, {PLAYER}, ¡te voy a\n"
	.string "dar el Pikachu que eh atrapado\l"
	.string "recientemente!$"

PuebloPaleta_LabDelProfOak_Text_Azul_4:
	.string "{COLOR BLUE}Azul: Así que un Pikachu, ¿Eh?\p"
	.string "Dudo mucho que ese pequeñín sea\n"
	.string "rival para mi equipo Pokémon,\l"
	.string "ja, ja.$"

PuebloPaleta_LabDelProfOak_Text_Oak_6:
	.string "{COLOR BLUE}Prof.Oak: No deberías subestimar a los\n"
	.string "Pokémon, Azul.\p"
	.string "Seguro que ese pequeñín te pone en\n"
	.string "una situación complicada dentro de\l"
	.string "poco.$"

PuebloPaleta_LabDelProfOak_Text_Oak_7:
	.string "{COLOR BLUE}Prof.Oak: Si quieres que cierto Pokémon\n"
	.string "te siga a todos lados, simplemente\l"
	.string "debes tenerlo como primer Pokémon.\p"
	.string "¡Es una manera fácil de Fortalecer\n"
	.string "la amistad con tus Pokémon!$"

PuebloPaleta_LabDelProfOak_Text_Oak_8:
	.string "{COLOR BLUE}Prof.Oak: Una última cosa {PLAYER}.\p"
	.string "Si quieres que cierto Pokémon\n"
	.string "te siga a todos lados, simplemente\l"
	.string "debes tenerlo como primer Pokémon.\p"
	.string "¡Es una manera fácil de Fortalecer\n"
	.string "la amistad con tus Pokémon!$"


PuebloPaleta_LabDelProfOak_Text_Azul_5:
	.string "{COLOR BLUE}Azul: ¡Mis Pokémon son mejores\n"
	.string "que el tuyo!$"

PuebloPaleta_LabDelProfOak_Text_PikachuObtenido:
	.string "¡Has obtenido un Pikachu\n"
	.string "como tu inicial!$"

PuebloPaleta_LabDelProfOak_Text_NombreDePikachu:
	.string "¿Quieres darle un Nombre a\n"
	.string "tu Pikachu?$"

PuebloPaleta_LabDelProfOak_Text_Azul_Batalla1:
	.string "{COLOR BLUE}¡Probemos a nuestros Pokémon!\p"
	.string "¡Vamos, luchemos!$"

PuebloPaleta_LabDelProfOak_Text_Azul_Batalla2:
	.string "¡Increíble!\n"
	.string "¡Ese Pikachu me venció!$"

PuebloPaleta_LabDelProfOak_Text_Azul_Batalla3:
	.string "{COLOR BLUE}¡Bien, ire a hacer fuertes a\n"
	.string "mis Pokémon!\p"
	.string "¡{PLAYER}! ¡Abuelo!\n"
	.string "¡Hasta luego!$"

PuebloPaleta_LabDelProfOak_Text_Azul_Batalla4:
	.string "{COLOR BLUE}¡Ja! ¡Era de esperar! un\n"
	.string "Pikachu no sera suficiente para\l"
	.string "ganarme a mi {PLAYER}.\p"
	.string "¡Bien, seguire fortaleciendo\n"
	.string "a mis Pokémon!\p"
	.string "¡{PLAYER}! ¡Abuelo!\n"
	.string "¡Hasta luego!$"

PuebloPaleta_LabDelProfOak_Text_Azul_Pre_Batalla:
	.string "{COLOR BLUE}Azul: ¡Oye! ¡Espera, {PLAYER}!$"

PuebloPaleta_LabDelProfOak_Text_EnciclopediaEnBlanco::
    .string "Es como una enciclopedia, pero\n"
    .string "las páginas están en blanco.$"

PuebloPaleta_LabDelProfOak_Text_Oak_9::
    .string "{COLOR BLUE}Prof. Oak: ¡Ah, {PLAYER}!\n"
    .string "¿Cómo va tu nuevo Pokémon??\p"
    .string "Bueno, Parece que te\n"
    .string "a agarrado cariño.\p"
    .string "¡Parece que tienes talento\n"
    .string "entrenando Pokémon!\p"
    .string "¿Cómo?\n"
    .string "¿Tienes algo para mí?$"

PuebloPaleta_LabDelProfOak_Text_CorreoOak::
    .string "{PLAYER} entregó el Correo de Oak.$"

PuebloPaleta_LabDelProfOak_Text_Oak_10::
    .string "{COLOR BLUE}¡Ah, sí!\n"
    .string "¡Es la Pokébola que encargue!\p"
    .string "¡Gracias!$"

PuebloPaleta_LabDelProfOak_Text_Azul_6::
    .string "{COLOR BLUE}Azul: ¡Abuelo!$"

PuebloPaleta_LabDelProfOak_Text_Azul_7::
    .string "{COLOR BLUE}Azul: ¿Qué quieres de mí?$"

PuebloPaleta_LabDelProfOak_Text_Oak_11::
    .string "{COLOR BLUE}Prof. Oak: ¡Oh, es cierto!\n"
    .string "Quería pedirles un favor.$"

PuebloPaleta_LabDelProfOak_Text_Oak_12::
    .string "{COLOR BLUE}¡En la mesa hay un invento mío,\n"
    .string "el Pokédex!\p"
    .string "¡Registra automáticamente datos\n"
    .string "sobre los Pokémon que hayan\l"
	.string "visto o capturado!\p"
    .string "¡Es una tecno-enciclopedia!$"

PuebloPaleta_LabDelProfOak_Text_Oak_13::
    .string "{COLOR BLUE}Prof. Oak: {PLAYER} y Azul.\n"
    .string "Tomen los Pokédex.$"

PuebloPaleta_LabDelProfOak_Text_Pokedex::
    .string "¡{PLAYER} obtuvo un POKéDEX\n"
    .string "de manos del Prof. Oak!$"

PuebloPaleta_LabDelProfOak_Text_Oak_14::
    .string "{COLOR BLUE}Prof. Oak: No se aprenden cosas sobre\n"
    .string "los Pokémon con sólo viendolos.\p"
    .string "Hay que atraparlos.\p"
    .string "Esto es lo que hace falta\n"
    .string "para atraparlos…$"

PuebloPaleta_LabDelProfOak_Text_Pokebolas::
    .string "¡{PLAYER} obtuvo 5 POKéBOLAS!$"

PuebloPaleta_LabDelProfOak_Text_Oak_15::
    .string "{COLOR BLUE}Prof. Oak: Cuando aparezca un Pokémon\n"
    .string "salvaje, deberán luchar\l"
    .string "contra él.\p"
    .string "¡Luego deben lanzarle una Pokébola\n"
    .string "para capturarlo!\p"
    .string "Aunque…\n"
    .string "esto no siempre funciona.\p"
    .string "¡Un Pokémon sano podría huir!\n"
    .string "¡También cuenta la suerte!$"

PuebloPaleta_LabDelProfOak_Text_Oak_16::
    .string "{COLOR BLUE}Quería hacer una guía de todos\n"
    .string "los Pokémon del mundo…\p"
    .string "¡Ese era mi sueño!\p"
    .string "Pero ya soy muy viejo y no puedo\n"
    .string "hacerlo.\p"
    .string "Así que quiero que\n"
    .string "hagan realidad ese sueño.\p"
    .string "¡Adelante, vayan en su busqueda!\p"
    .string "¡Será una gran proeza en la\n"
    .string "historia Pokémon!$"

PuebloPaleta_LabDelProfOak_Text_Azul_8::
    .string "{COLOR BLUE}Azul: ¡Tranquilo abuelo!\n"
    .string "¡Dejamelo a mí!$"

PuebloPaleta_LabDelProfOak_Text_Azul_9::
    .string "{COLOR BLUE}{PLAYER}, No suelo decir esto, pero,\n"
    .string "no necesitare tu ayuda.\p"
    .string "¡Le pediré a mi hermana su\n"
    .string "Mapa!\p"
    .string "¡Y le diré que no te deje ninguno\n"
    .string "a ti! ¡Ja, ja, ja!\p"
    .string "¡No te molestes en venir a mi Casa\n"
    .string "luego de esto!$"
