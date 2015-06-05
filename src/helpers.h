
#ifndef HELPERS_H
#define HELPERS_H 1

#include <stdio.h>
#include <stdint.h>

uint64_t le64_load(const unsigned char *p);

void le64_store(unsigned char *p, uint64_t x);

void exit_err(const char *msg) __attribute__((noreturn));

void exit_msg(const char *msg) __attribute__((noreturn));

void * xmalloc(size_t size);

void * xsodium_malloc(size_t size);

void xor_buf(unsigned char *dst, const unsigned char *src, size_t len);

int xfput_b64(FILE *fp, const unsigned char *bin, size_t bin_len);

int xfprintf(FILE *fp, const char *format, ...) __attribute__((format(printf, 2, 3)));

int xfclose(FILE *fp);

void trim(char *str);

const char * file_basename(const char *file);

FILE * fopen_create_useronly(const char *file);

#endif
