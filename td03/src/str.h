/**
 * @file str.h
 * @author Andrew SASSOYE
 */
#ifndef DEV3_STR_H
#define DEV3_STR_H

#include <stdlib.h>

/**
 * Calculate the length of a null-terminated byte string.
 *
 * @param str   pointer to the null-terminated byte string to be examined
 *
 * @return The  length of the null-terminated byte string str.
 */
size_t strlen(const char *str);

/**
 * Compares two null-terminated byte strings lexicographically.
 * The sign of the result is the sign of the difference between the values of the first pair of characters
 * (both interpreted as unsigned char) that differ in the strings being compared.
 * The behavior is undefined if lhs or rhs are not pointers to null-terminated byte strings.
 *
 * @param lhs   pointers to the null-terminated byte strings to compare
 * @param rhs   pointers to the null-terminated byte strings to compare
 *
 * @return      Negative value if lhs appears before rhs in lexicographical order.
 * @return      Zero if lhs and rhs compare equal.
 * @return      Positive value if lhs appears after rhs in lexicographical order.
 */
int strcmp(const char *lhs, const char *rhs);

/**
 * Copies the null-terminated byte string pointed to by src, including the null terminator,
 * to the character array whose first element is pointed to by dest.
 * The behavior is undefined if the dest array is not large enough. The behavior is undefined if the strings overlap.
 * The behavior is undefined if either dest is not a pointer to a character array or src is not a pointer to a
 * null-terminated byte string.
 *
 * @param dest 	pointer to the character array to write to
 * @param src 	pointer to the null-terminated byte string to copy from
 *
 * @return 	    maximum number of characters to write, typically the size of the destination buffer
 */
char *strcpy(char *dest, const char *src);

/**
 * Copies at most count characters of the character array pointed to by src (including the terminating null character,
 * but not any of the characters that follow the null character) to character array pointed to by dest.
 * If count is reached before the entire array src was copied, the resulting character array is not null-terminated.
 * If, after copying the terminating null character from src, count is not reached,
 * additional null characters are written to dest until the total of count characters have been written.
 * The behavior is undefined if the character arrays overlap, if either dest or src is not a pointer to
 * a character array (including if dest or src is a null pointer),
 * if the size of the array pointed to by dest is less than count,
 * or if the size of the array pointed to by src is less than count and it does not contain a null character.
 *
 *
 * @param dest      pointer to the character array to copy to
 * @param src       pointer to the character array to copy from
 * @param count     maximum number of characters to copy
 *
 * @return  	    the size of the destination buffer
 */
char *strncpy(char *dest, const char *src, size_t count);

/**
 * Appends a copy of the null-terminated byte string pointed to by src to the end of the null-terminated byte string
 * pointed to by dest. The character src[0] replaces the null terminator at the end of dest.
 * The resulting byte string is null-terminated.
 * The behavior is undefined if the destination array is not large enough for the contents of both src and dest
 * and the terminating null character. The behavior is undefined if the strings overlap.
 * The behavior is undefined if either dest or src is not a pointer to a null-terminated byte string.
 *
 * @param dest pointer to the null-terminated byte string to append to
 * @param src pointer to the null-terminated byte string to copy from
 *
 * @return returns a copy of dest
 * @return returns zero on success, returns non-zero on error. Also, on error, writes zero to dest[0] (unless dest is a null pointer or destsz is zero or greater than RSIZE_MAX).
 */
char *strcat(char *dest, const char *src);

/**
 * Finds the next token in a null-terminated byte string pointed to by str. The separator characters are identified
 * by null-terminated byte string pointed to by delim.
 * This function is designed to be called multiples times to obtain successive tokens from the same string.
 *
 * @param str pointer to the null-terminated byte string to tokenize
 * @param delim pointer to the null-terminated byte string identifying delimiters
 *
 * @return Returns pointer to the beginning of the next token or NULL if there are no more tokens.
 */
char *strtok(char *str, const char *delim);

#endif //DEV3_STR_H
