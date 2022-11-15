#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _putchar - Print a character
 * @c: Character
 * Return: Number of bytes printed
 */
int _putchar(char c);

/**
 * _puts - Prints an array of characters
 * @s: Array of characters
 * Return: Number of bytes printed
 */
unsigned int _puts(char *s);

/**
 * _strlen - Gets length of a string
 * @s: String
 * Return: length of string
 */
unsigned int _strlen(char *s);

/**
 * _strcmp - Compare two string to check for equality
 * @s1: First string
 * @s2: Second String
 * Return: Difference between their characters
 */
int _strcmp(char *s1, char *s2);

#endif
