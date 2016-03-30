%option nounput
%option yylineno

%{
	#include <iostream>
	#include <string>

	extern "C" int yylex(void);

	#include "parser.tab.hpp"
%}

blanc			[ \t]+
commentaire (\\\*)([^*])*(\*\\)|(\/\/(.*))

chiffre		[0-9]
entier		{chiffre}+

cercle		(c|C)(e|E)(r|R)(c|C)(l|L)(e|E)
rectangle	(r|R)(e|E)(c|C)(t|T)(a|A)(n|N)(g|G)(l|L)(e|E)
ligne			(l|L)(i|I)(g|G)(n|N)(e|E)

couleur		(rouge|vert|bleu|jaune|noir|blanc|gris)
remplissage	(plein|vide)

mot			([a-z]|[A-Z])+

variable		([a-z])([a-z]|[A-Z]|{chiffre})*

%%

"fin"		return(END);

{blanc}	{	/*	On ignore	*/	}
[\n]	{ yylineno++; }

{commentaire} {	/* On ignore */ }


{entier}	{
	yylval.value = atoi(yytext);
	return(NOMBRE);
}

{cercle}		return(CERCLE);
{rectangle}	return(RECTANGLE);
{ligne}		return(LIGNE);

"Fenetre"	return(FENETRE);

{couleur} 	{
	yylval.string = strdup(yytext);
	return(COULEUR);
}
{remplissage} {
	yylval.string = strdup(yytext);
	return(REMPLISSAGE);
}

{mot}		{
	yylval.string = strdup(yytext);
	return(MOT);
}

{variable}	{
	yylval.string = strdup(yytext);
	return(VARIABLE);
}

"="			return(EGAL);
"°"			return(DEGRE);		
"%"			return(POURCENTAGE);

","			return(VIRGULE);
"#"			return(MOT_DIESE);

"{"			return(ACCOLADE_OUVRANTE);
"}"			return(ACCOLADE_FERMANTE);
"("			return(PARENTHESE_OUVRANTE);
")"			return(PARENTHESE_FERMANTE);
"["			return(CROCHET_OUVRANT);
"]"			return(CROCHET_FERMANT);

%%
