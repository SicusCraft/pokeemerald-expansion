Ruta1_MapScripts::
	.byte 0

Ruta1_EventScript_EmpleadoDelMercado::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POTION_ON_ROUTE_1, Ruta1_EventScript_PocionObtenida
	msgbox Ruta1_Text_Empleado
	checkitemspace ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	bufferitemname STR_VAR_2, ITEM_POTION
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitmessage
	waitfanfare
	additem ITEM_POTION
	msgbox Ruta1_Text_PocionGuardada
	setflag FLAG_GOT_POTION_ON_ROUTE_1
	release
	end

Ruta1_EventScript_PocionObtenida::
	msgbox Ruta1_Text_Empleado2 MSGBOX_NPC
	release
	end

Ruta1_EventScript_Cartel::
	msgbox Ruta1_Text_Cartel
	release
	end

Ruta1_EventScript_Chico::
	msgbox Ruta1_Text_Chico MSGBOX_NPC
	release
	end

Ruta1_Text_Empleado::
    .string "{COLOR BLUE}¡Hola!\n"
    .string "Trabajo en la Tienda Pokémon.\p"
    .string "¡Tenemos muchas cosas a la\n"
    .string "venta!\p"
    .string "Visítanos en Ciudad Verde.\p"
    .string "¡Mira, te daré una muestra!\n"
    .string "¡Aquí tienes!$"

Ruta1_Text_Empleado2::
    .string "{COLOR BLUE}Ven a visitarnos en caso de que\n"
    .string "necesites Pokébolas para capturar\l"
    .string "algun Pokémon que quieras.$"

Ruta1_Text_Cartel::
    .string "Ruta 1:\n"
    .string "Pueblo Paleta - Ciudad Verde$"

Ruta1_Text_Chico::
    .string "{COLOR BLUE}¿Ves esos bordes del camino?\p"
    .string "Dan miedo, pero puedes saltar\n"
    .string "por encima de ellos.\p"
    .string "¡De esa forma podrás volver\n"
    .string "rápidamente a Pueblo Paleta!$"

Ruta1_Text_PocionGuardada::
    .string "{PLAYER} Guardo la Poción en\n"
    .string "la mochila.$"
