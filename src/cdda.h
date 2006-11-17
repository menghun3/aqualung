/*                                                     -*- linux-c -*-
    Copyright (C) 2004 Tom Szilagyi

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    $Id: cdda.h 339 2006-09-10 17:37:58Z tszilagyi $
*/

#ifndef _CDDA_H
#define _CDDA_H


#include <config.h>

#ifdef HAVE_CDDA

#include <cdio/cdio.h>
#ifdef HAVE_CDDB
#undef HAVE_CDDB
#endif /* HAVE_CDDB */

#include "common.h"

#define CDDA_DRIVES_MAX 16
#define CDDA_MAXLEN 256

typedef struct {
	int n_tracks;
	lsn_t toc[100];
} cdda_disc_t;

typedef struct {
	int is_used; /* drive under use should not be scanned */
	char device_path[CDDA_MAXLEN];
	char vendor[CDDA_MAXLEN];
	char model[CDDA_MAXLEN];
	char revision[CDDA_MAXLEN];
	cdda_disc_t disc;
} cdda_drive_t;

cdda_drive_t * cdda_get_drive(int n);
cdda_drive_t * cdda_get_drive_by_device_path(char * device_path);
int cdda_scan_drive(char * device_path, cdda_drive_t * cdda_drive);
int cdda_scan_all_drives(void);

#endif /* HAVE_CDDA */

#endif /* _CDDA_H */
