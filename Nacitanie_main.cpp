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

int main( int argc, char** argv )
{
 
 	dir = "dataset_petnuchova/depth";
	dp = opendir(dir.c_str());
  	if (dp == NULL) {
    	cout << "Error(" << errno << ") opening " << endl;
    	return errno;
    }

	namedWindow("test", CV_WINDOW_AUTOSIZE );

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

	    imshow("test", image );
	    waitKey(0);
	    //usleep(30*1000);

	    std::cout << dirp->d_name  <<std::endl;
	    // // Endeavor to read a single number from the file and display it
	    // fin.open( filepath.c_str() );
	    // if (fin >> num)
	    //   cout << filepath << ": " << num << endl;
	    // fin.close();
    }

  closedir( dp );

 // char* imageName = "test";

 // //Mat image;
 // Mat image = imread("dataset_petnuchova/depth/1488794534424.png", cv::IMREAD_UNCHANGED);
 // //image = imread( imageName, 1 );

 // if(!image.data )
 // {
 //   printf( " No image data \n " );
 //   return -1;
 // }

 // Mat gray_image;
 // // cvtColor( image, gray_image, CV_BGR2GRAY );

 // // imwrite( "../Stop/1488794534424.png", gray_image );

 // namedWindow( imageName, CV_WINDOW_AUTOSIZE );
 // // namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );

 // imshow( imageName, image );
 // // imshow( "Gray image", gray_image );

 waitKey(0);

 return 0;
}