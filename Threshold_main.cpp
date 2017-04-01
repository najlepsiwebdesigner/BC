#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

/// Global variables

int threshold_value = 0;
int const max_value = 255;

int threshold_value2 = 0;
int const max_value2 = 255;

int threshold_type = 3;
int const max_type = 4;

int const max_BINARY_value = 255;

Mat src, src_gray, dst, test;
char* window_name = "Threshold Demo";

char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
char* trackbar_value = "Minimalna vzdialenost";
char* trackbar_value2 = "Maximalna vzdialenost";

/// Function headers
void Threshold_Demo( int, void* );

/**
 * @function main
 */
int main( int argc, char** argv )
{
  /// Load an image
  src = imread( argv[1], 1 ); 
 

  /// Convert the image to Gray
  cvtColor( src, src_gray, CV_BGR2GRAY );

  /// Create a window to display results
  namedWindow( window_name, CV_WINDOW_AUTOSIZE );

  // // Create Trackbar to choose type of Threshold
  // createTrackbar( trackbar_type,
  //                 window_name, &threshold_type,
  //                 max_type, Threshold_Demo );

  createTrackbar( trackbar_value,
                  window_name, &threshold_value,
                  max_value, Threshold_Demo );

  createTrackbar( trackbar_value2,
                  window_name, &threshold_value2,
                  max_value2, Threshold_Demo );
  /// Call the function to initialize
  Threshold_Demo( 0, 0 );

  /// Wait until user finishes program
  while(true)
  {
    int c;
    c = waitKey( 20 );
    if( (char)c == 27 )
      { break; }
   }

}

/**
 * function Threshold_Demo
 */
void Threshold_Demo( int, void* )
{
  /*printf("0: Binary\n"); 
   printf("1: Binary Inverted\n");   
   printf("2: Threshold Truncated\n");   
   printf("3: Threshold to Zero\n");   
    printf("4: Threshold to Zero Inverted\n");  
*/
  threshold( src_gray, dst, threshold_value, max_BINARY_value,3);
  threshold( dst, dst, threshold_value2, max_BINARY_value,4);

  imshow( window_name, dst );
}
