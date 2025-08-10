.set LOCALID_RIVAL, 1

Ruta22_MapScripts::
	.byte 0

Ruta22_EventScript_RivalMedio::
	lockall
	clearflag FLAG_HIDE_RIVAL_ROUTE_22
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Ruta22_Movement_RivalMov1
	waitmovement 0
	delay 6
	msgbox Ruta22_Text_Azul_1
	trainerbattle_no_intro TRAINER_BLUE_RUTA_22, Ruta22_Text_Azul_Derrotado
	msgbox Ruta22_Text_Azul_2
	closemessage
	delay 10
	playbgm MUS_RG_RIVAL_EXIT, 0
	applymovement LOCALID_RIVAL, Ruta22_Movement_RivalMov2
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	setvar VAR_MAP_SCENE_ROUTE22, 2
	releaseall
	end

Ruta22_Text_Azul_1::
    .string "{COLOR BLUE}Azul: ¡Hey! ¡{PLAYER}!\n"
    .string "¿Vas a la Liga Pokémon?\p"
    .string "¡Olvídalo! ¡Seguro que no tienes\n"
    .string "ninguna Medalla!\p"
    .string "¡El guardia no te dejará pasar!\p"
    .string "¡Dime, ¿ya son más fuertes tus\n"
    .string "Pokémon?$"

Ruta22_Text_Azul_2::
    .string "{COLOR BLUE}Dicen que los Entrenadores de la\n"
    .string "Liga Pokémon son muy fuertes.\p"
    .string "¡Tengo que buscar una forma de\n"
    .string "vencerlos!\p"
    .string "¡Deja de perder el tiempo y\n"
    .string "muévete!$"

Ruta22_Text_Azul_Derrotado::
    .string "¡Auuu!\n"
    .string "¡Tuviste suerte!$"

Ruta22_Movement_RivalMov1::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Ruta22_Movement_RivalMov2::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
