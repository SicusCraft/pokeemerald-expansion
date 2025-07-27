.set LOCALID_WOMAN, 1
.set LOCALID_LASS,  2

CiudadVerde_Escuela_MapScripts::
	.byte 0

CiudadVerde_Escuela_EventScript_Colegiala::
	lock
	faceplayer
	msgbox CiudadVerde_Escuela_Text_Colegiala
	closemessage
	applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

CiudadVerde_Escuela_EventScript_Maestra::
	lock
	faceplayer
	msgbox CiudadVerde_Escuela_Text_Maestra
	closemessage
	applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CiudadVerde_Escuela_EventScript_Cuaderno::
	lockall
	msgbox CiudadVerde_Escuela_Text_Cuaderno
	releaseall
	end

CiudadVerde_Escuela_EventScript_Pizarra::
	lockall
	msgbox CiudadVerde_Escuela_Text_Pizarra
	releaseall
	end

CiudadVerde_Escuela_Text_Colegiala::
    .string "{COLOR RED}¡Esto es absurdo!\p"
    .string "¿Por qué tengo que aprenderlo en\n"
    .string "inglés?$"

CiudadVerde_Escuela_Text_Maestra::
    .string "{COLOR RED}¡Ya te lo dije!\p"
    .string "¡Hoy en día piden el Inglés en\n"
    .string "todos sitios así que no te quejes!$"

CiudadVerde_Escuela_Text_Cuaderno::
    .string "¡Es el Cuaderno de la chica!\p"
    .string "Lo mejor es no andar de metiches.$"

CiudadVerde_Escuela_Text_Pizarra::
    .string "La pizarra muestra lo básico sobre\n"
    .string "Los problemas de estados de los\l"
    .string "Pokémon.\p"
    .string "Aunque parece estar en Ingles...$"
