/*
 *  Copyright (c) 2015 Ryan McCullagh <me@ryanmccullagh.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "var.h"

#define RECORD_SIZE 4

typedef struct _VariantRecord {
	Var* v;			/* 4 or 8 bytes */
} VariantRecord;

int main()
{
	VariantRecord *variant_record = malloc(RECORD_SIZE * sizeof(VariantRecord));
	
	variant_record[0].v = var_string("Ryan McCullagh");
	variant_record[1].v = var_long(24);
	variant_record[2].v = var_float(4.99);
	variant_record[3].v = var_string(__FILE__);

	size_t i;

	for(i = 0; i < RECORD_SIZE; i++) {
		
		fprintf(stdout, "variant_record[%zu]=", i);
		
		if(VAR_TYPE(variant_record[i].v) == IS_FLOAT) {
			
			fprintf(stdout, "%.2f", VAR_FVAL(variant_record[i].v));
		
		} else if(VAR_TYPE(variant_record[i].v) == IS_STRING) {
			
			fprintf(stdout, "%s (%zu)", VAR_SVAL(variant_record[i].v), 
						VAR_SLEN(variant_record[i].v));	

		} else if(VAR_TYPE(variant_record[i].v)) {
		
			fprintf(stdout, "%ld", VAR_LVAL(variant_record[i].v));

		} else {
		
			var_print(variant_record[i].v);
		
		}

		fprintf(stdout, "\n");
	
	}
	
	for(i = 0; i < RECORD_SIZE; i++) {
	
		/* Free memory */
		var_destroy(variant_record[i].v);

	}

	free(variant_record);

	return 0;
}
