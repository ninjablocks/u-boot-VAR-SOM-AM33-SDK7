/*
 * (C) Copyright 2011 Free Electrons
 * David Wagner <david.wagner@free-electrons.com>
 *
 * Inspired from envcrc.c:
 * (C) Copyright 2001
 * Paolo Scaffardi, AIRVENT SAM s.p.a - RIMINI(ITALY), arsenio@tin.it
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "compiler.h"
#include <u-boot/crc.h>
#include <version.h>

#define CRC_SIZE sizeof(uint32_t)

int main(int argc, char **argv)
{
	uint32_t crc;
	const char *txt_filename = NULL;
	int txt_fd;
	struct stat txt_file_stat;
	unsigned int filesize = 0;

	unsigned char *filebuf = NULL;

	int ret = EXIT_SUCCESS;

	if (argc < 2) {
		fprintf(stderr, "usage: crc32sum filename\n");
		return EXIT_FAILURE;
	}

	txt_filename = argv[1];
	txt_fd = open(txt_filename, O_RDONLY);
	if (txt_fd == -1) {
		fprintf(stderr, "Can't open \"%s\": %s\n",
				txt_filename, strerror(errno));
		return EXIT_FAILURE;
	}
	/* ... and check it */
	ret = fstat(txt_fd, &txt_file_stat);
	if (ret == -1) {
		fprintf(stderr, "Can't stat() on \"%s\": %s\n",
				txt_filename, strerror(errno));
		return EXIT_FAILURE;
	}

	filesize = txt_file_stat.st_size;

	filebuf = mmap(NULL, sizeof(char) * filesize, PROT_READ,
		       MAP_PRIVATE, txt_fd, 0);
	if (filebuf == MAP_FAILED) {
		fprintf(stderr, "mmap (%zu bytes) failed: %s\n",
				sizeof(char) * filesize,
				strerror(errno));
		fprintf(stderr, "Falling back to read()\n");
	}

	crc = crc32(0, filebuf, filesize);

	fprintf(stdout, "0x%08x\n", crc);

	ret = close(txt_fd);

	return 0;
}
