.set LOCALID_MUSEUM_GUIDE, 3
.set LOCALID_GYM_GUIDE, 5

CiudadPlateada_MapScripts::
	.byte 0

CiudadPlateada_EventScript_CazaBichos::
	lock
	faceplayer
	msgbox CiudadPlateada_Text_Cazabichos_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CiudadPlateada_EventScript_CazaBichos_2
	msgbox CiudadPlateada_Text_Cazabichos_2, MSGBOX_DEFAULT
	release
	end

CiudadPlateada_EventScript_Colegiala::
	msgbox CiudadPlateada_Text_Chica, MSGBOX_NPC
	end

CiudadPlateada_EventScript_CazaBichos_2::
	msgbox CiudadPlateada_Text_Cazabichos_3, MSGBOX_DEFAULT
	release
	end

CiudadPlateada_EventScript_Gordo::
	msgbox CiudadPlateada_Text_Hombre_Obeso, MSGBOX_NPC
	end

CiudadPlateada_EventScript_PistasEntrenador::
	msgbox CiudadPlateada_Text_Pistas, MSGBOX_SIGN
	end

CiudadPlateada_EventScript_Cartel_1::
	msgbox CiudadPlateada_Text_Cartel_1, MSGBOX_SIGN
	end

CiudadPlateada_EventScript_Cartel_2::
	msgbox CiudadPlateada_Text_Cartel_2, MSGBOX_SIGN
	end

CiudadPlateada_EventScript_CartelMuseo::
	msgbox CiudadPlateada_Text_Museo, MSGBOX_SIGN
	end

CiudadPlateada_EventScript_CartelGimnasio::
	lockall
	msgbox CiudadPlateada_Text_Gimnasio, MSGBOX_SIGN
	releaseall
	end

CiudadPlateada_EventScript_GuiaMuseo_1::
	lock
	faceplayer
	msgbox CiudadPlateada_Text_ChicoMuseo_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CiudadPlateada_EventScript_GuiaMuseo_2
	msgbox CiudadPlateada_Text_ChicoMuseo_2, MSGBOX_DEFAULT
	closemessage
	delay 10
	playbgm MUS_FOLLOW_ME, 0
	goto_if_eq VAR_FACING, DIR_NORTH, CiudadPlateada_EventScript_CaminoMuseoNorte
	goto_if_eq VAR_FACING, DIR_SOUTH, CiudadPlateada_EventScript_CaminoMuseoSur
	goto_if_eq VAR_FACING, DIR_EAST, CiudadPlateada_EventScript_CaminoMuseoEste
	goto_if_eq VAR_FACING, DIR_WEST, CiudadPlateada_EventScript_CaminoMuseoOeste
	end

CiudadPlateada_EventScript_GuiaMuseo_2::
	msgbox CiudadPlateada_Text_ChicoMuseo_4, MSGBOX_DEFAULT
	release
	end

CiudadPlateada_EventScript_CaminoMuseoNorte::
	applymovement LOCALID_MUSEUM_GUIDE, CiudadPlateada_Movement_GuiaNorte
	applymovement OBJ_EVENT_ID_PLAYER, CiudadPlateada_Movement_PlayerNorte
	waitmovement 0
	goto CiudadPlateada_EventScript_GuiaMuseoRegreso

CiudadPlateada_EventScript_CaminoMuseoSur::
	applymovement LOCALID_MUSEUM_GUIDE, CiudadPlateada_Movement_GuiaSur
	applymovement OBJ_EVENT_ID_PLAYER, CiudadPlateada_Movement_PlayerSur
	waitmovement 0
	goto CiudadPlateada_EventScript_GuiaMuseoRegreso

CiudadPlateada_EventScript_CaminoMuseoEste::
	applymovement LOCALID_MUSEUM_GUIDE, CiudadPlateada_Movement_GuiaEste
	applymovement OBJ_EVENT_ID_PLAYER, CiudadPlateada_Movement_PlayerEste
	waitmovement 0
	goto CiudadPlateada_EventScript_GuiaMuseoRegreso

CiudadPlateada_EventScript_CaminoMuseoOeste::
	applymovement LOCALID_MUSEUM_GUIDE, CiudadPlateada_Movement_GuiaOeste
	applymovement OBJ_EVENT_ID_PLAYER, CiudadPlateada_Movement_PlayerOeste
	waitmovement 0
	goto CiudadPlateada_EventScript_GuiaMuseoRegreso

CiudadPlateada_EventScript_GuiaMuseoRegreso::
	msgbox CiudadPlateada_Text_ChicoMuseo_3, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_MUSEUM_GUIDE, CiudadPlateada_Movement_GuiaRegreso
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_MUSEUM_GUIDE
	clearflag FLAG_HIDE_PEWTER_MUSEUM_GUIDE
	release
	end

CiudadPlateada_EventScript_GuiaGimnasioScript_Arriba::
	lock
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox CiudadPlateada_Text_ChicoGimnasio, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	applymovement LOCALID_GYM_GUIDE, CiudadPlateada_Movement_GuiaGimPreCaminataArriba
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, CiudadPlateada_Movement_PlayerGimMov_2
	applymovement LOCALID_GYM_GUIDE, CiudadPlateada_Movement_GuiaGimMov_2
	waitmovement 0
	goto CiudadPlateada_EventScript_GuiaGimnasioRegreso

CiudadPlateada_EventScript_GuiaGimnasioScript_Medio::
	lock
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox CiudadPlateada_Text_ChicoGimnasio, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	applymovement LOCALID_GYM_GUIDE, CiudadPlateada_Movement_GuiaGimPreCaminataMedio
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, CiudadPlateada_Movement_PlayerGimMov_3
	applymovement LOCALID_GYM_GUIDE, CiudadPlateada_Movement_GuiaGimMov_3
	waitmovement 0
	goto CiudadPlateada_EventScript_GuiaGimnasioRegreso

CiudadPlateada_EventScript_GuiaGimnasioScript_Abajo::
	lock
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox CiudadPlateada_Text_ChicoGimnasio, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	applymovement LOCALID_GYM_GUIDE, CiudadPlateada_Movement_GuiaGimPreCaminataAbajo
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, CiudadPlateada_Movement_PlayerGimMov_4
	applymovement LOCALID_GYM_GUIDE, CiudadPlateada_Movement_GuiaGimMov_4
	waitmovement 0
	goto CiudadPlateada_EventScript_GuiaGimnasioRegreso

CiudadPlateada_EventScript_GuiaGimnasio::
	lock
	faceplayer
	msgbox CiudadPlateada_Text_ChicoGimnasio, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	applymovement LOCALID_GYM_GUIDE, CiudadPlateada_Movement_GuiaGimPreCaminata
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, CiudadPlateada_Movement_PlayerMovNpcGim
	applymovement LOCALID_GYM_GUIDE, CiudadPlateada_Movement_GuiaGimnasioMovNpc
	waitmovement 0
	goto CiudadPlateada_EventScript_GuiaGimnasioRegreso

CiudadPlateada_EventScript_GuiaGimnasioRegreso::
	msgbox CiudadPlateada_Text_ChicoGimnasio_2, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_GYM_GUIDE, CiudadPlateada_Movement_GuiaGimMovRegreso
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_GYM_GUIDE
	clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	release
	end

CiudadPlateada_Movement_GuiaGimPreCaminata::
	walk_down
	walk_left
	walk_in_place_faster_up
	walk_in_place_up
	step_end

CiudadPlateada_Movement_GuiaGimPreCaminataArriba::
	walk_left
	walk_down
	walk_in_place_faster_right
	walk_in_place_right
	step_end

CiudadPlateada_Movement_GuiaGimPreCaminataMedio::
	walk_down
	walk_in_place_down
	step_end

CiudadPlateada_Movement_GuiaGimPreCaminataAbajo::
	walk_down
	walk_down
	walk_in_place_down
	step_end

CiudadPlateada_Movement_GuiaGimMovRegreso::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

.macro walk_to_gym
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
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
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
.endm

CiudadPlateada_Movement_PlayerGimMov_2::
	walk_left
	walk_to_gym
	step_end

CiudadPlateada_Movement_GuiaGimMov_2::
	walk_to_gym
	walk_right
	walk_in_place_faster_left
	step_end

CiudadPlateada_Movement_PlayerGimMov_3::
	walk_up
	walk_left
	walk_to_gym
	step_end

CiudadPlateada_Movement_GuiaGimMov_3::
	walk_left
	walk_to_gym
	walk_right
	walk_in_place_faster_left
	step_end

CiudadPlateada_Movement_PlayerGimMov_4::
	walk_up
	walk_up
	walk_left
	walk_to_gym
	step_end

CiudadPlateada_Movement_GuiaGimMov_4::
	walk_up
	walk_left
	walk_to_gym
	walk_right
	walk_in_place_faster_left
	step_end

CiudadPlateada_Movement_GuiaGimnasioMovNpc::
	walk_to_gym
	walk_right
	walk_in_place_faster_left
	step_end

CiudadPlateada_Movement_PlayerMovNpcGim::
	walk_down
	walk_to_gym
	step_end

CiudadPlateada_Movement_GuiaRegreso::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

CiudadPlateada_Movement_PlayerNorte::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	walk_in_place_fast_up
	step_end

CiudadPlateada_Movement_GuiaNorte::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_up
	step_end

CiudadPlateada_Movement_PlayerSur::
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	walk_in_place_fast_up
	step_end

CiudadPlateada_Movement_GuiaSur::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_up
	step_end

CiudadPlateada_Movement_PlayerOeste::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	walk_in_place_fast_up
	step_end

CiudadPlateada_Movement_GuiaOeste::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_up
	step_end

CiudadPlateada_Movement_PlayerEste::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	walk_in_place_fast_up
	step_end

CiudadPlateada_Movement_GuiaEste::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_up
	step_end

CiudadPlateada_Text_Hombre_Obeso::
    .string "{COLOR BLUE}No hay muchos Entrenadores\n"
    .string "por aquí.\p"
    .string "Todos parecen Cazabichos,\n"
    .string "exceptuando Brock, del\l"
    .string "Gimnasio de Plateada.$"

CiudadPlateada_Text_Gimnasio::
    .string "Gimnasio de Ciudad Plateada.\n"
    .string "Líder: Brock:\p"
    .string "¡El entrenador más duro que una\n"
    .string "roca!$"

CiudadPlateada_Text_Cazabichos_1::
    .string "{COLOR BLUE}¡Psssst!\n"
    .string "¿Sabes qué estoy haciendo?$"

CiudadPlateada_Text_Cazabichos_2::
    .string "{COLOR BLUE}Estoy rociando Repelente para\n"
    .string "mantener a los Pokémon salvajes\l"
    .string "alejados de mi jardín.$"

CiudadPlateada_Text_Cazabichos_3::
    .string "{COLOR BLUE}¡Así es!\n"
    .string "¡Es un duro trabajo!$"

CiudadPlateada_Text_Chica::
    .string "{COLOR RED}Los Clefairy vinieron\n"
    .string "de la Luna.\p"
    .string "O al menos eso dicen\n"
    .string "los rumores.\p"
    .string "¡Aparecieron tras la caída de\n"
    .string "varias Piedras Lunares\n"
    .string "en el Mt. Moon!$"

CiudadPlateada_Text_Pistas::
    .string "Consejos de Entrenador\p"
    .string "¡Todo Pokémon que entre al\n"
    .string "campo de batalla obtendrá Exp.!$"

CiudadPlateada_Text_Cartel_1::
    .string "Ciudad Plateada\n"
    .string "La ciudad de la piedra gris$"

CiudadPlateada_Text_Cartel_2::
    .string "¡Aviso!\p"
    .string "Unos ladrones han estado robando\n"
    .string "fósiles en el Mt.Moon.\p"
    .string "Por favor, contactar con la\n"
    .string "policía si disponen de alguna\l"
    .string "información.$"

CiudadPlateada_Text_Museo::
    .string "Museo de la Ciencia de\n"
    .string "Ciudad Plateada$"

CiudadPlateada_Text_ChicoMuseo_1::
    .string "{COLOR BLUE}¿Has estado en el Museo?$"

CiudadPlateada_Text_ChicoMuseo_2::
    .string "{COLOR BLUE}¿De verdad?\n"
    .string "¡Pues tienes que ir!$"

CiudadPlateada_Text_ChicoMuseo_3::
    .string "{COLOR BLUE}¡Está aquí mismo!\p"
    .string "¡Hay que pagar para entrar, pero\n"
    .string "vale la pena! ¡Hasta luego!$"

CiudadPlateada_Text_ChicoMuseo_4::
    .string "{COLOR BLUE}¿No eran geniales esos fósiles\n"
    .string "del Mt. Moon?$"

CiudadPlateada_Text_ChicoGimnasio::
    .string "{COLOR BLUE}Eres Entrenador, ¿no?\p"
    .string "¡Brock está buscando a nuevos\n"
    .string "Contricantes! ¡Sígueme!$"

CiudadPlateada_Text_ChicoGimnasio_2::
    .string "{COLOR BLUE}¡Si eres valiente, pelearás\n"
    .string "contra Brock!$"
