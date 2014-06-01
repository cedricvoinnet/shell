/*
** sepa.c for sepa.c in /home/gottin_o/Projets/42sh
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Fri Apr 25 12:04:10 2014 gottin_o
** Last update Thu May 29 17:53:27 2014 gottin_o
*/

#include	<stdlib.h>
#include	"../lexer/lexer.h"

t_sepa		sepa_tab[] =
  {
    {SEMICOLON, 1, 1},
    {OR, 2, 2},
    {AND, 2, 2},
    {PIPE, 1, 3},
    {L_DBREDIR, 2, 4},
    {R_DBREDIR, 2, 4},
    {L_REDIR, 1, 4},
    {R_REDIR, 1, 4},
    {NULL, 0, 5},
  };

t_syntax        syntax_tab[] =
  {
    {OTH, (int []) {OTH, SMC, RED, SEP, END}},
    {SEP, (int []) {OTH, RED, END}},
    {RED, (int []) {OTH, END}},
    {SMC, (int[]) {OTH, RED, END}},
    {0, (int []) {END}},
  };
