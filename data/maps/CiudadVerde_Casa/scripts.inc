CiudadVerde_Casa_MapScripts::
	.byte 0

CiudadVerde_Casa_EventScript_HombreCalvo::
	msgbox CiudadVerde_Casa_Text_HombreCalvo, MSGBOX_NPC
	end

CiudadVerde_Casa_EventScript_Nina::
	msgbox CiudadVerde_Casa_Text_Nina, MSGBOX_NPC
	end

CiudadVerde_Casa_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox CiudadVerde_Casa_Text_Speary
	waitmoncry
	release
	end

CiudadVerde_Casa_EventScript_Cartel::
	msgbox CiudadVerde_Casa_Text_Cartel, MSGBOX_SIGN
	end

CiudadVerde_Casa_Text_HombreCalvo::
    .string "{COLOR BLUE}Inventarse motes es divertido, pero\n"
    .string "tambien dificil.\p"
    .string "Es más fácil recordar nombres\n"
    .string "sencillos.$"

CiudadVerde_Casa_Text_Nina::
    .string "{COLOR RED}¡A mi padre también le gustan los\n"
    .string "Pokémon!$"

CiudadVerde_Casa_Text_Speary::
    .string "Speary: ¡Tetweet!$"

CiudadVerde_Casa_Text_Cartel::
    .string "Spearow\n"
    .string "Nombre: Speary$"
