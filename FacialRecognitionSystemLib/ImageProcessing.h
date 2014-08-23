#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\objdetect\objdetect.hpp>

#include <map>

#define NULL 0

class ImageProcessing
{

typedef std::map<int, cv::Mat*> FrameMap;

public:
	ImageProcessing(void);
	~ImageProcessing(void);

	int grayscaleImage(cv::Mat image);
	int removeColour(cv::Mat src, cv::Mat dst);
	int loadCascade(cv::CascadeClassifier *cascade, std::string cascade_xml_path);
	cv::Mat addSobelFilter(cv::Mat image);
	int addFrameToMap(int mapId, cv::Mat* frame, int code);
	cv::Mat* getPreviousFrame(int mapId, int code);
	int getSizeRightMap();
	int getSizeLeftMap();

private:
	FrameMap						m_rightEyeMap;
	FrameMap						m_leftEyeMap;

};

