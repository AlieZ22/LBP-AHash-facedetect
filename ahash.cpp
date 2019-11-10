#include"myHead.h"
/*
	计算图片的ahash值
*/

vector<int> aHashValue(Mat& src)
{
	Mat img;
	vector<int> rst(64);
	double dldex[64];
	double mean = 0.0;
	int k = 0;

	if (src.channels() == 3)
	{
		cvtColor(src, src, CV_BGR2GRAY);
	}
	img = Mat_<double>(src);
	// 缩放尺寸
	resize(img, img, Size(8, 8));
	// 计算平均像素
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			dldex[k] = img.at<double>(i, j);
			mean += img.at<double>(i, j) / 64;
			k++;
		}
	}
	// 计算哈希值
	for (int i = 0; i < 64; i++) {
		if (dldex[i] >= mean) {
			rst[i] = 1;
		}
		else {
			rst[i] = 0;
		}
	}
	return rst;
}
