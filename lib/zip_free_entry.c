/*
  zip_free_entry.c -- free struct zip_entry
  Copyright (C) 1999 Dieter Baron and Thomas Klaunser

  This file is part of libzip, a library to manipulate ZIP files.
  The authors can be contacted at <nih@giga.or.at>

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
*/



#include <stdlib.h>
#include "zip.h"

int
_zip_free_entry(struct zip_entry *ze)
{
    int ret;

    ret = 0;
    
    free(ze->fn);
    free(ze->fn_old);
    
    zip_free_meta(ze->meta);
    zip_free_meta(ze->ch_meta);
    if (ze->ch_func)
	ret = ze->ch_func(ze->ch_data, NULL, 0, ZIP_CMD_CLOSE);
    
    free(ze->ch_data);

    return ret;
}