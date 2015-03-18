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

#define A_LEN 4

#define VARIANT_RECORD_ARRAY_SIZE(s) (s * sizeof(VariantRecord))

typedef struct _VariantRecord {
	Var* v;			/* 4 or 8 bytes */
} VariantRecord;

int main()
{
	VariantRecord *variant_record = malloc(A_LEN * sizeof(VariantRecord));
	
	variant_record[0].v = var_string("Ryan McCullagh");
	variant_record[1].v = var_long(24);
	variant_record[2].v = var_float(4.99);
	variant_record[3].v = var_string(__FILE__);

	size_t i;

	for(i = 0; i < A_LEN; i++) {
		
		fprintf(stdout, "variant_record[%zu]=", i);
		
		if(VAR_TYPE(variant_record[i].v) == IS_FLOAT) {
			
			fprintf(stdout, "%.2f", VAR_FVAL(variant_record[i].v));
		
		} else if(VAR_TYPE(variant_record[i].v) == IS_STRING) {
			
			fprintf(stdout, "%s (%zu)", VAR_SVAL(variant_record[i].v), 
						VAR_SLEN(variant_record[i].v));	

		} else if(VAR_TYPE(variant_record[i].v) == IS_LONG) {
		
			fprintf(stdout, "%ld", VAR_LVAL(variant_record[i].v));

		} else {
		
			var_print(variant_record[i].v);
		
		}

		fprintf(stdout, "\n");

	}
	
	size_t len;
	char* sval;

	for(i = 0; i < A_LEN; i++) {
		
		sval = var_to_string(variant_record[i].v, &len);

		if(sval == NULL) {

			printf("sval == NULL\n");

		} else {
			
			printf("%s\n", sval);

			free(sval);
		}

	}

	fprintf(stdout, "*** BEGIN var_print_line ***\n");

	for(i = 0; i < A_LEN; i++) {

		var_print_line(variant_record[i].v);

	}

	fprintf(stdout, "*** END var_print_line ***\n");
	
	fprintf(stdout, "*** BEGIN var_print ***\n");

	for(i = 0; i < A_LEN; i++) {

		var_print(variant_record[i].v);
		printf("\n");

	}

	fprintf(stdout, "*** END var_print ***\n");
	
	
	for(i = 0; i < A_LEN; i++) {
	
		/* Free memory */
		var_destroy(variant_record[i].v);

	}

	free(variant_record);

	return 0;
}
