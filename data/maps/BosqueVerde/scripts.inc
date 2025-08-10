BosqueVerde_MapScripts::
	.byte 0

BosqueVerde_EventScript_Joven::
	msgbox BosqueVerde_Text_Cazabichos, MSGBOX_NPC
	end

BosqueVerde_EventScript_Chico::
	msgbox BosqueVerde_Text_Chico, MSGBOX_NPC
	end

BosqueVerde_EventScript_PistasEntrenador_1::
	msgbox BosqueVerde_Text_Pistas_1, MSGBOX_SIGN
	end

BosqueVerde_EventScript_PistasEntrenador_2::
	msgbox BosqueVerde_Text_Pistas_2, MSGBOX_SIGN
	end

BosqueVerde_EventScript_PistasEntrenador_3::
	msgbox BosqueVerde_Text_Pistas_3, MSGBOX_SIGN
	end

BosqueVerde_EventScript_PistasEntrenador_4::
	msgbox BosqueVerde_Text_Pistas_4, MSGBOX_SIGN
	end

BosqueVerde_EventScript_PistasEntrenador_5::
	msgbox BosqueVerde_Text_Pistas_5, MSGBOX_SIGN
	end

BosqueVerde_EventScript_Salida::
	msgbox BosqueVerde_Text_Salida, MSGBOX_SIGN
	end

BosqueVerde_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, BosqueVerde_Text_RickIntro, BosqueVerde_Text_RickDerrotado
	msgbox BosqueVerde_Text_Rick, MSGBOX_AUTOCLOSE
	end

BosqueVerde_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, BosqueVerde_Text_DougIntro, BosqueVerde_Text_DougDerrotado
	msgbox BosqueVerde_Text_Doug, MSGBOX_AUTOCLOSE
	end

BosqueVerde_EventScript_Samy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, BosqueVerde_Text_SamyIntro, BosqueVerde_Text_SamyDerrotado
	msgbox BosqueVerde_Text_Samy, MSGBOX_AUTOCLOSE
	end

BosqueVerde_EventScript_Antony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, BosqueVerde_Text_AntonyIntro, BosqueVerde_Text_AntonyDerrotado
	msgbox BosqueVerde_Text_Antony, MSGBOX_AUTOCLOSE
	end

BosqueVerde_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, BosqueVerde_Text_CharlieIntro, BosqueVerde_Text_CharlieDerrotado
	msgbox BosqueVerde_Text_Charlie, MSGBOX_AUTOCLOSE
	end

BosqueVerde_Text_Cazabichos::
    .string "{COLOR BLUE}¡Vine aquí con unos amigos!\p"
    .string "¡Van en busca de combates\n"
    .string "Pokémon!$"

BosqueVerde_Text_RickIntro::
    .string "{COLOR BLUE}¡Oye! ¡Tienes Pokémon!\n"
    .string "¡Sí!\l"
    .string "¡Al ataque!$"

BosqueVerde_Text_RickDerrotado::
    .string "¡No!\n"
    .string "¡Mi Caterpie no puede más!$"

BosqueVerde_Text_Rick::
    .string "{COLOR BLUE}¡Ssh!\n"
    .string "¡Vas a espantar a los bichos!$"

BosqueVerde_Text_DougIntro::
    .string "{COLOR BLUE}¡Oye!\n"
    .string "¡Hay que tener disciplina para\l"
    .string "ser Entrenador Pokémon!$"

BosqueVerde_Text_DougDerrotado::
    .string "¿Eh?\n"
    .string "¡No me quedan más Pokémon!$"

BosqueVerde_Text_Doug::
    .string "{COLOR BLUE}¡Vaya!\n"
    .string "¡Voy a atrapar unos más fuertes!$"

BosqueVerde_Text_SamyIntro::
    .string "{COLOR BLUE}¡Oye, espera!\n"
    .string "¿Por qué la prisa?$"

BosqueVerde_Text_SamyDerrotado::
    .string "¡Me rindo!\n"
    .string "¡Eres demasiado fuerte!$"

BosqueVerde_Text_Samy::
    .string "{COLOR BLUE}¡A veces puedes encontrar cosas\n"
    .string "en el suelo!\p"
    .string "¡Estoy buscando los objetos\n"
    .string "que se me cayeron!$"

BosqueVerde_Text_AntonyIntro::
    .string "{COLOR BLUE}No soy especialmente grande, ¡pero\n"
    .string "tampoco soy ningún tonto!$"

BosqueVerde_Text_AntonyDerrotado::
    .string "Vaya, pues parece que tampoco\n"
    .string "soy demasiado fuerte…$"

BosqueVerde_Text_Antony::
    .string "{COLOR BLUE}Así no hay forma de ahorrar…$"

BosqueVerde_Text_CharlieIntro::
    .string "{COLOR BLUE}¿Sabes que los Pokémon\n"
    .string "evolucionan?$"

BosqueVerde_Text_CharlieDerrotado::
    .string "¡Oh! ¡He perdido!$"

BosqueVerde_Text_Charlie::
    .string "{COLOR BLUE}Los Pokémon bichos evolucionan\n"
    .string "muy rápido. ¡Son geniales!$"

BosqueVerde_Text_Chico::
    .string "{COLOR BLUE}¡Me quedé sin Pokébolas con\n"
    .string "las que atrapar Pokémon!\p"
    .string "¡Deberías llevar algunas extra!$"

BosqueVerde_Text_Pistas_1::
    .string "Consejos de Entrenador\p"
    .string "Si quieres evitar los combates,\n"
    .string "¡aléjate de las zonas de hierba!$"

BosqueVerde_Text_Pistas_2::
    .string "¡Usa el antídoto contra el veneno!\n"
    .string "¡Lo conseguirás en las Tiendas\n"
    .string "Pokémon!$"

BosqueVerde_Text_Pistas_3::
    .string "Consejos de Entrenador\p"
    .string "Contact PROF. OAK via a PC to\n"
    .string "get your POKéDEX evaluated!$"

BosqueVerde_Text_Pistas_4::
    .string "Consejos de Entrenador\p"
    .string "¡No robes los Pokémon de otros\n"
    .string "Entrenadores!\p"
    .string "¡Captura sólo Pokémon salvajes\n"
    .string "con las Pokébolas!$"

BosqueVerde_Text_Pistas_5::
    .string "Consejos de Entrenador\p"
    .string "¡Debilita a los Pokémon antes\n"
    .string "de intentar capturarlos!\p"
    .string "¡Si están fuertes, podrían escapar!$"

BosqueVerde_Text_Salida::
    .string "Saliendo del Bosque Verde,\n"
    .string "Se Encuentra Ciudad Plateada$"
