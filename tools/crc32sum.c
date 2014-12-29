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
	return 0;
}
