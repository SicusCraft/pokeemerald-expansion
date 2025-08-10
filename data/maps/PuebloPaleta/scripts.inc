.set LOCALID_PROF_OAK,  2

PuebloPaleta_MapScripts::
	.byte 0

PuebloPaleta_EventScript_Chica::
	msgbox PuebloPaleta_Text_Chica, MSGBOX_NPC
	end

PuebloPaleta_EventScript_Chico::
	msgbox PuebloPaleta_Text_Tecnologia, MSGBOX_NPC
	end

PuebloPaleta_EventScript_CartelDePueblo::
	msgbox PuebloPaleta_Text_Cartel, MSGBOX_SIGN
	end

PuebloPaleta_EventScript_Consejo::
	msgbox PuebloPaleta_Text_Consejo, MSGBOX_SIGN
	end

PuebloPaleta_EventScript_LabDeOak::
	msgbox PuebloPaleta_Text_LabOak, MSGBOX_SIGN
	end

PuebloPaleta_EventScript_CasaDeRojo::
	msgbox PuebloPaleta_Text_CasaDeRojo, MSGBOX_SIGN
	end

PuebloPaleta_EventScript_CasaDeAzul::
	msgbox PuebloPaleta_Text_CasaDeAzul, MSGBOX_SIGN
	end

PuebloPaleta_EventScript_OakEntradaIzquierda::
	lockall
	delay 30
	playbgm MUS_RG_OAK, 0
	message PuebloPaleta_Text_NoTeVayas
	waitmessage
	delay 85
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	addobject LOCALID_PROF_OAK
	applymovement LOCALID_PROF_OAK, PuebloPaleta_Movement_OakEncuentroIzquierdo
	waitmovement 0
	delay 30
	msgbox PuebloPaleta_Text_HierbaInsegura
	closemessage
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	delay 15
	playse SE_PIN
	applymovement LOCALID_PROF_OAK, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 15
	special SavePlayerParty
	special LoadOakEevee
	special StartOakTutorialBattle
	waitstate
	special LoadPlayerParty
	msgbox PuebloPaleta_Text_PikachuAtrapado
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PuebloPaleta_Text_PokemonPropio
	closemessage
	delay 30
	playbgm MUS_FOLLOW_ME, 0
	applymovement LOCALID_PROF_OAK, PuebloPaleta_Movement_LaboratorioCaminoIzquierdo
	applymovement OBJ_EVENT_ID_PLAYER, PuebloPaleta_Movement_RojoLaboratorioCaminoIzquierdo
	waitmovement 0
	opendoor 16, 13
	waitdooranim
	applymovement LOCALID_PROF_OAK, PuebloPaleta_Movement_OakEntrandoAlLaboratorio
	applymovement OBJ_EVENT_ID_PLAYER, PuebloPaleta_Movement_PlayerEntrandoAlLaboratorio
	waitmovement 0
	closedoor 16, 13
	waitdooranim
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 2
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
	setflag FLAG_DONT_TRANSITION_MUSIC
	warp MAP_PUEBLO_PALETA_LAB_DEL_PROF_OAK, 6, 12
	waitstate
	releaseall
	end

PuebloPaleta_EventScript_OakEntradaDerecha::
	lockall
	delay 30
	playbgm MUS_RG_OAK, 0
	message PuebloPaleta_Text_NoTeVayas
	waitmessage
	delay 85
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 30
	addobject LOCALID_PROF_OAK
	applymovement LOCALID_PROF_OAK, PuebloPaleta_Movement_OakEncuentroDerecho
	waitmovement 0
	delay 30
	msgbox PuebloPaleta_Text_HierbaInsegura
	closemessage
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	delay 15
	playse SE_PIN
	applymovement LOCALID_PROF_OAK, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 15
	special SavePlayerParty
	special LoadOakEevee
	special StartOakTutorialBattle
	waitstate
	special LoadPlayerParty
	msgbox PuebloPaleta_Text_PikachuAtrapado
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PuebloPaleta_Text_PokemonPropio
	closemessage
	delay 30
	playbgm MUS_FOLLOW_ME, 0
	applymovement LOCALID_PROF_OAK, PuebloPaleta_Movement_LaboratorioCaminoDerecho
	applymovement OBJ_EVENT_ID_PLAYER, PuebloPaleta_Movement_RojoLaboratorioCaminoDerecho
	waitmovement 0
	opendoor 16, 13
	waitdooranim
	applymovement LOCALID_PROF_OAK, PuebloPaleta_Movement_OakEntrandoAlLaboratorio
	applymovement OBJ_EVENT_ID_PLAYER, PuebloPaleta_Movement_PlayerEntrandoAlLaboratorio
	waitmovement 0
	closedoor 16, 13
	waitdooranim
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 2
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
	setflag FLAG_DONT_TRANSITION_MUSIC
	warp MAP_PUEBLO_PALETA_LAB_DEL_PROF_OAK, 6, 12
	waitstate
	releaseall
	end

PuebloPaleta_Text_Chica:
	.string "{COLOR RED}¡Yo estoy entrenando a mis\n"
	.string "Pokémon!\p"
	.string "¡Cuando se hagan fuertes me\n"
	.string "protegerán!$"

PuebloPaleta_Text_Tecnologia:
	.string "{COLOR BLUE}¡La tecnología es increíble!\p"
	.string "¡Ahora puedes guardar y sacar\n"
	.string "objetos y Pokémon, vía PC!$"

PuebloPaleta_Text_Cartel:
	.string "Pueblo Paleta\p"
	.string "¡Donde inician las grandes\n"
	.string "aventuras!$"


PuebloPaleta_Text_Consejo:
	.string "Consejos de Entrenador\p"
	.string "¡Pulsa Start para abrir el Menu!$"

PuebloPaleta_Text_CasaDeRojo:
	.string "Casa de {PLAYER}$"

PuebloPaleta_Text_CasaDeAzul:
	.string "Casa de Azul$"

PuebloPaleta_Text_LabOak:
	.string "Laboratorio de Investigaion del\n"
	.string "Prof.Oak$"

PuebloPaleta_Text_HierbaInsegura:
    .string "{COLOR BLUE}Prof.Oak: ¡Cuidado! ¡En la hierba viven\n"
    .string "Pokémon salvajes!$"

PuebloPaleta_Text_NoTeVayas::
    .string "{COLOR BLUE}???: ¡Hey! ¡Alto!\n"
    .string "¡No te vayas!$"

PuebloPaleta_Text_PikachuAtrapado::
    .string "{COLOR BLUE}Prof.Oak: ¡Uff! ¡Eso estuvo cerca!$"

PuebloPaleta_Text_PokemonPropio::
    .string "{COLOR BLUE}¡Necesitas a tu propio Pokémon\n"
	.string "como protección!\p"
    .string "¡Ven conmigo, anda!$"

PuebloPaleta_Movement_OakEncuentroIzquierdo::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

	.macro walk_to_lab
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	.endm

PuebloPaleta_Movement_OakEncuentroDerecho::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

	.macro walk_to_lab2
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	.endm

PuebloPaleta_Movement_LaboratorioCaminoIzquierdo::
	walk_down
	walk_to_lab
	walk_right
	walk_in_place_faster_up
	step_end

PuebloPaleta_Movement_LaboratorioCaminoDerecho::
	walk_down
	walk_to_lab2
	walk_right
	walk_in_place_faster_up
	step_end

PuebloPaleta_Movement_RojoLaboratorioCaminoIzquierdo::
	walk_down
	walk_down
	walk_to_lab
	step_end

PuebloPaleta_Movement_RojoLaboratorioCaminoDerecho::
	walk_down
	walk_down
	walk_to_lab2
	step_end

PuebloPaleta_Movement_OakEntrandoAlLaboratorio::
	walk_up
	set_invisible
	step_end

PuebloPaleta_Movement_PlayerEntrandoAlLaboratorio::
	walk_right
	walk_up
	set_invisible
	step_end
