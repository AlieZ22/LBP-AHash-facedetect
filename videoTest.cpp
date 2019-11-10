#include"myHead.h"
/*
	一帧一帧测试视频（rukou.mp4）
	运行后，按ESC将暂停并进行滑动窗口检测
	在滑动窗口检测的过程中，检测到一个时，若按ESC将退出滑动并继续播放视频；若按其他键继续滑动窗口检测
	一帧的窗口检测完自动退出并继续播放视频
*/
extern vector<int> aHashValue(Mat& src);
extern void LBP(const cv::Mat& image, cv::Mat& lbp_image);

int main()
{
	VideoCapture cap;
	Mat frame;
	Mat img;
	int key;
	int num = 100;

	cap.open("tech.flv");
	if (!cap.isOpened()) {
		cout << "cap load failed!" << endl;
		return -1;
	}

	// 加载已训练的svm模型
	CvSVM svm;
	svm.clear();
	string modelPath = "hash_svm.xml";
	FileStorage svm_fs(modelPath, FileStorage::READ);
	if (svm_fs.isOpened()) {
		svm.load(modelPath.c_str());
	}

	// 进行检测
	while (true) 
	{
		cap >> frame;
		imshow("video", frame);
		if (frame.empty()) {
			cout << "结束" << endl;
			break;
		}
		key = waitKey(30);
		if (key != 27) {
			continue;
		}
		// 滑动窗口检测这一帧
		int response;
		img = frame.clone();
		Mat clone;
		cvtColor(img, clone, CV_BGR2GRAY);
		// 滑动窗口大小
		int winSize1 = 180;    // 宽
		int winSize2 = 220;    // 高
		if (img.cols > winSize1 && img.rows > winSize2)
		{
			int step = 25;    // 步长：x,y方向均有
			for (int y = 0; y < img.rows - winSize2; y += step) {
				for (int x = 0; x < img.cols - winSize1; x += step) {
					imshow("detect_frame", img);
					waitKey(5);
					Mat myROI = clone(Rect(x, y, winSize1, winSize2));
					Mat lbp_roi;
					LBP(myROI, lbp_roi);
					imshow("roi", lbp_roi);
					vector<int> hash = aHashValue(myROI);
					Mat dst = Mat(hash);
					dst = dst.reshape(1, 1);
					dst.convertTo(dst, CV_32FC1);
					response = (int)svm.predict(dst);
					// 该窗口检测到人脸
					if (response == 1) {
						cout << "检测人脸" << endl;
						rectangle(img, cvPoint(x, y), cvPoint((x + winSize1), (y + winSize2)), cvScalar(0, 0, 255), 3, 4, 0);
						int c = waitKey(0);
						// 检测到一个时，若按ESC将退出滑动并继续播放视频
						if (c == 27) {
							//string hardPath = "d:\\program\\c++\\proj\\phash_svm\\hardneg\\hard";
							//hardPath = hardPath.append(to_string(num));
							//hardPath = hardPath.append(".jpg");
							//imwrite(hardPath, myROI);
							//num++; 
							goto Label;
						}
					}
					else {
						//cout << "未检测人脸" << endl;
					}
				}
			}
		}
		Label:
			destroyWindow("detect_frame");
			destroyWindow("roi");
	}

}