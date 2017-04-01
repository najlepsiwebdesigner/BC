#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>


#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>


// header files aby mi fungovali filesystem calls na directory
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>

using namespace cv;
using namespace std;


DIR *dp;
struct dirent *dirp;
struct stat filestat;
string filepath, dir;
ifstream fin;
int num;
/// Global variables

int threshold_value = 0;
int const max_value = 255;

int threshold_value2 = 0;
int const max_value2 = 255;

int threshold_type = 3;
int const max_type = 4;

int const max_BINARY_value = 255;

Mat image, image_gray, dst, test;
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
  //src = imread( argv[1], 1 ); 


  dir = "dataset_petnuchova/depth";
  dp = opendir(dir.c_str());
    if (dp == NULL) {
      cout << "Error(" << errno << ") opening " << endl;
      return errno;
    }

  namedWindow(window_name, CV_WINDOW_AUTOSIZE );

  while ((dirp = readdir( dp ))) {
      filepath = dir + "/" + dirp->d_name;

      // If the file is a directory (or is in some way invalid) we'll skip it 
      if (stat( filepath.c_str(), &filestat )) continue;
      if (S_ISDIR( filestat.st_mode ))         continue;


      std::cout << dir + "/" + dirp->d_name << std::endl;
      Mat image = imread(dir + "/" + dirp->d_name, cv::IMREAD_UNCHANGED);
      
    if(!image.data )
     {
       printf( " No image data \n " );
       return -1;
     }

 

  /// Convert the image to Gray
  //cvtColor( image, image_gray, CV_BGR2GRAY );

  /// Create a window to display results
  //namedWindow( window_name, CV_WINDOW_AUTOSIZE );

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
imshow( window_name, image );
waitKey(0);
  /// Wait until user finishes program
  // while(true)
  // {
  //   int c;
  //   c = waitKey( 20 );
  //   if( (char)c == 27 )
  //     { break; }
  //  }
std::cout << dirp->d_name  <<std::endl;
}
closedir( dp );

 waitKey(0);

 return 0;
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
*/if(!image.empty()){
  threshold( image, dst, threshold_value, max_BINARY_value,3);
  threshold( dst, dst, threshold_value2, max_BINARY_value,4);
 
 imshow( window_name, dst );
        
    }
 
}
