#pragma pack(2)
#if !defined MYBMP
#define MYBMP
typedef enum { cRED , cGREEN , cBLUE } Channel;

typedef struct {
  char format[2];         /* always BM */
  int file_size;          /* full size of file including headers */
  int reserved1;          /* set to 0 */
  int pixel_offset;       /* where pixels data start */
} FileHead;               /* total size: 14 bytes */


typedef struct {
  int header_size;        /* set to 40 */
  int image_width;
  int image_height;
  short num_of_planes;
  short bits_per_pixel;
  int compression;
  int raw_pixel_size;
  int h_resolution;
  int v_resolution;
  int num_of_colors;
  int important_colors;
} ImageHead;

typedef struct {
  char blue;
  char green;
  char red;
} Pixel; /* total size: 3 bytes */
      /* opens the BMP file given be the first parameter
      returns pixels data, the file header and the image header */
Pixel** load_image(char*, FileHead*, ImageHead*);
      /* takes a pixels matrix and makes its pixels grey by setting its components
      to the same value, according to the second parameter */
void make_grey(Pixel**, int, int, Channel);
      /* takes a pixels matrix and modify its pixels components:
      reducing blue and grey by 50% and increasing red by (255-red)/2 */
void redify(Pixel**, int, int);
    /* saves the pixels in a BMP file with the name given by the first parameter
    and using the file header and image header passed as 2nd and 3rd params */
int save_image(char* , FileHead*, ImageHead*, Pixel** );
#endif