#include "StdAfx.h"
#include "ImageProcessing.h"

#include <iostream>
#include <opencv2\imgproc\imgproc.hpp>

using namespace std;
using namespace cv;

ImageProcessing::ImageProcessing(void)
{
}


ImageProcessing::~ImageProcessing(void)
{
}

int ImageProcessing::loadCascade(CascadeClassifier* cascade, string cascade_xml_path)
{
	int retval = 0;

	// load the pre-built classifier objects
	if (cascade->load(cascade_xml_path))
	{
		cout << "loading " << cascade_xml_path << " file." << endl;
	}
	else
	{
		cout << "failed to load the " << cascade_xml_path << " file... exiting program!!!" << endl;
		retval = -1;
	}

	return retval;
}

int ImageProcessing::removeColour(Mat src, Mat dst)
{
	return 0;
}

// Computes the x component of the gradient vector
// at a given point in a image.
// returns gradient in the x direction
int xGradient(Mat image, int x, int y)
{
	return image.at<uchar>(y-1, x-1) +
		2*image.at<uchar>(y, x-1) +
		image.at<uchar>(y+1, x-1) -
		image.at<uchar>(y-1, x+1) -
		2*image.at<uchar>(y, x+1) -
		image.at<uchar>(y+1, x+1);
}

// Computes the y component of the gradient vector
// at a given point in a image
// returns gradient in the y direction
int yGradient(Mat image, int x, int y)
{
	return image.at<uchar>(y-1, x-1) +
		2*image.at<uchar>(y-1, x) +
		image.at<uchar>(y-1, x+1) -
		image.at<uchar>(y+1, x-1) -
		2*image.at<uchar>(y+1, x) -
		image.at<uchar>(y+1, x+1);
}

Mat ImageProcessing::addSobelFilter(Mat image)
{
	Mat src;
	Mat dst;
	int gx = 0;
	int gy = 0;
	int sum = 0;
	// Load an image
	cvtColor(image, src, CV_BGR2GRAY);

	dst = src.clone();
	if( !dst.data )
	{ 
		cout << "no data found!" << endl;
		return image; 
	}

	for(int y = 0; y < src.rows; y++)
		for(int x = 0; x < src.cols; x++)
			dst.at<uchar>(y,x) = (uchar)0.0;

	for(int y = 1; y < src.rows - 1; y++)
	{
		for(int x = 1; x < src.cols - 1; x++)
		{
			gx = xGradient(src, x, y);
			gy = yGradient(src, x, y);
			sum = abs(gx) + abs(gy);
			sum = sum > 255 ? 255:sum;
			sum = sum < 0 ? 0 : sum;
			dst.at<uchar>(y,x) = sum;
		}
	}

	return dst;
}

// method used to add the current frame to the map
int ImageProcessing::addFrameToMap(int mapId, Mat* frame, int code)
{
	if (code == 0)
	{
		m_rightEyeMap.insert(pair<int,Mat*>(mapId,frame));
	}
	else
	{
		m_leftEyeMap.insert(pair<int,Mat*>(mapId,frame));
	}
	return 0;
}


// method used to the get the value that is stored
// in the map
Mat* ImageProcessing::getPreviousFrame(int mapId, int code)
{
	if (code = 0)
	{
		FrameMap::iterator rightIter = m_rightEyeMap.find(mapId);
		if(rightIter == m_rightEyeMap.end())
			return NULL;
		return (*rightIter).second;
	}
	else
	{
		FrameMap::iterator leftIter = m_leftEyeMap.find(mapId);
		if(leftIter == m_leftEyeMap.end())
			return NULL;
		return (*leftIter).second;
	}
	return NULL;
}

int ImageProcessing::getSizeRightMap()
{
	return m_rightEyeMap.size();
}

int ImageProcessing::getSizeLeftMap()
{
	return m_rightEyeMap.size();
}
