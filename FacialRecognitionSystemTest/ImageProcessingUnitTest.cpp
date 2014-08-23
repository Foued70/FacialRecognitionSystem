#include "stdafx.h"
#include "ImageProcessing.h"
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\objdetect\objdetect.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace FacialRecognitionSystemTest
{
	[TestClass]
	public ref class ImageProcessingUnitTest
	{
	private:
		TestContext^ testContextInstance;
		ImageProcessing* imageProcessor;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void removeColourTest()
		{
			// this method removes the colour from the image
			// if the colur is susccessfully removed the 
			// method will return 0, otherwise the method 
			// will return -1
			cv::Mat src;
			src = cv::imread("pic0.jpg", 1);
			cv::Mat dst;
			dst = cv::imread("pic0.jpg", 1);

			Assert::AreEqual<int>(0, imageProcessor->removeColour(src, dst));
		};

		//[TestMethod]
		//void loadCascadeTest()
		//{
		//	// int loadCascade(cv::CascadeClassifier *cascade, std::string cascade_xml_path);
		//	Assert::AreEqual<int>(0, imageProcessor->removeColour(src, dst));
		//};

		//[TestMethod]
		//void addSobelFilterTest()
		//{
		//	// cv::Mat addSobelFilter(cv::Mat image);
		//	Assert::AreEqual<int>(0, imageProcessor->removeColour(src, dst));
		//};
		//[TestMethod]
		//void addFrameToMapTest()
		//{
		//	// int addFrameToMap(int mapId, cv::Mat* frame, int code);
		//	Assert::AreEqual<int>(0, imageProcessor->removeColour(src, dst));
		//};
		//[TestMethod]
		//void getPreviousFrame()
		//{
		//	// int loadCascade(cv::CascadeClassifier *cascade, std::string cascade_xml_path);
		//	Assert::AreEqual<int>(0, imageProcessor->removeColour(src, dst));
		//};
		//[TestMethod]
		//void getSizeRightMapTest()
		//{
		//	// int getSizeRightMap();
		//	Assert::AreEqual<int>(0, imageProcessor->removeColour(src, dst));
		//};
		//[TestMethod]
		//void getSizeLeftMapTest()
		//{
		//	// int getSizeLeftMap();
		//	Assert::AreEqual<int>(0, imageProcessor->removeColour(src, dst));
		//};

	};
}
