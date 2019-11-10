#include"myHead.h"
/*
	原始LBP特征提取
*/

void LBP(const cv::Mat& image, cv::Mat& lbp_image)
{
	lbp_image = cv::Mat::zeros(image.rows - 2, image.cols - 2, CV_8UC1);
	for (int i = 1; i < image.rows - 1; i++)
	{
		for (int j = 1; j < image.cols - 1; j++)
		{
			uchar center = image.at<uchar>(i, j);
			unsigned char code = 0;
			code |= (image.at<uchar>(i - 1, j - 1) > center) << 7;
			code |= (image.at<uchar>(i - 1, j) > center) << 6;
			code |= (image.at<uchar>(i - 1, j + 1) > center) << 5;
			code |= (image.at<uchar>(i, j + 1) > center) << 4;
			code |= (image.at<uchar>(i + 1, j + 1) > center) << 3;
			code |= (image.at<uchar>(i + 1, j) > center) << 2;
			code |= (image.at<uchar>(i + 1, j - 1) > center) << 1;
			code |= (image.at<uchar>(i, j - 1) > center) << 0;
			lbp_image.at<unsigned char>(i - 1, j - 1) = code;
		}
	}
}



/*int main()
{
	Mat src = imread("E://test.png",0);
	if (!src.data) {
		cout << "img load failed!" << endl;
		return -1;
	}
	Mat lbp_img; 
	LBP(src, lbp_img);
	imshow("origin", src);
	imshow("lbp", lbp_img);
	waitKey(0);

	return 0;
}*/