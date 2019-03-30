#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <png.h>
#include "upload.h"

void zapis_png (base_struct* main_game_data, char *output) {
    int x, y;
    int width, height;
    png_byte color_type;
    png_byte bit_depth;

    png_structp png_ptr;
    png_infop info_ptr;
    int number_of_passes;
    png_bytep * row_pointers;

    bit_depth = 8;
    color_type = PNG_COLOR_TYPE_GRAY;

    number_of_passes = 7;
    row_pointers = ( png_bytep* ) malloc ( sizeof ( png_bytep ) * l_rzedow );
    for ( y = 0; y < l_rzedow; y++ )
        row_pointers[y] = ( png_byte* ) malloc( sizeof ( png_byte ) * l_kolumn );

    for ( y = 0; y < l_rzedow; y++ ) {
        png_byte* row = row_pointers[y];
        for ( x = 0; x < l_kolumn; x++ ) {
            row[x] = main_game_data->table[y + 1][x + 1] == 1 ? 0 : 255;
        }
    }

    FILE *fp = fopen( output, "wb" );
    if ( !fp )
        printf ( "[write_png_file] File %s could not be opened for writing", output );

    png_ptr = png_create_write_struct ( PNG_LIBPNG_VER_STRING, NULL, NULL, NULL );

    if ( !png_ptr )
        printf ( "[write_png_file] png_create_write_struct failed" ) ;

    info_ptr = png_create_info_struct ( png_ptr );
    if ( !info_ptr )
        printf ( "[write_png_file] png_create_info_struct failed" );

    if ( setjmp ( png_jmpbuf ( png_ptr ) ) )
        printf ( "[write_png_file] Error during init_io" );

    png_init_io ( png_ptr, fp );

    if ( setjmp ( png_jmpbuf ( png_ptr ) ) )
        printf ( "[write_png_file] Error during writing header" );

    png_set_IHDR ( png_ptr, info_ptr, l_kolumn, l_rzedow,
                   bit_depth, color_type, PNG_INTERLACE_NONE,
                   PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE );

    png_write_info ( png_ptr, info_ptr );

    if ( setjmp ( png_jmpbuf ( png_ptr ) ) )
        printf ( "[write_png_file] Error during writing bytes" );

    png_write_image ( png_ptr, row_pointers );

    if ( setjmp ( png_jmpbuf ( png_ptr ) ) )
        printf ( "[write_png_file] Error during end of write" );

    png_write_end ( png_ptr, NULL );
    png_destroy_write_struct ( &png_ptr, &info_ptr );

    for ( y = 0; y < l_rzedow; y++ )
        free ( row_pointers[y] );
    free ( row_pointers );

    fclose ( fp );
}