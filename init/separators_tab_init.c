/*
** sepa.c for sepa.c in /home/gottin_o/Projets/42sh
** 
** Made by gottin_o
** Login   <gottin_o@epitech.net>
** 
** Started on  Fri Apr 25 12:04:10 2014 gottin_o
** Last update Sun May 25 13:19:18 2014 gottin_o
*/

#include <stdlib.h>
#include "../lexer/lexer.h"

t_sepa	sepa_tab[] =
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
    {FILE, (int []) {FILE, ARG, SEP, RRED, SMC, END}},
    {EXE, (int []) {FILE, SMC, ARG, SEP, LRED, RRED, END}},
    {SEP, (int []) {EXE, RRED, BTN, END}},
    {RRED, (int []) {FILE, ARG, END}},
    {LRED, (int []) {FILE, END}},
    {BTN, (int[]) {FILE, ARG, SMC, LRED, RRED, SEP, END}},
    {SMC, (int[]) {EXE, LRED, RRED, BTN, END}},
    {ARG, (int []) {FILE, SEP, LRED, RRED, ARG, SMC, END}},
    {0, (int []) {END}},
  };
