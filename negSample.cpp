#include"myHead.h"
/*
	从不含人脸(室内)的照片裁剪64x128的负样本
	现在（注释后）是，对两张入口的截图裁出2000张负样本
*/
extern void getFiles(string path, vector<string>& files);

/*int main()
{
	int counter = 0;
	string path = "D://Program//C++//proj//phash_svm//pic2.png";
	vector<string> files;
	char saveName[256];
	//getFiles(path, files);
	//cout << files.size() << endl;
	//for (int i = 0; i < files.size(); i++)
	//{
		//Mat src = imread(files[i].c_str());
		Mat src = imread(path);
		imshow("test", src);
		waitKey(0);
		// 图片应大于64x128
		if (src.cols > 100 && src.rows > 120) {
			srand(time(NULL));   // 设置随机种子
			// 从每张图片中剪出10个64x128大小的负样本
			for (int i = 0; i < 1000; i++)
			{
				// 获得随机窗口左上角坐标
				int x = (rand() % (src.cols - 100));
				int y = (rand() % (src.rows - 120));
				Mat imgROI = src(Rect(x, y, 100, 120));
				sprintf_s(saveName, "neg2//example2_%d.jpg", ++counter);
				imwrite(saveName, imgROI);   // 注：imwrite不会检测文件夹是否存在，不存在则不写
			}
		}
	//}
	cout << "得到负样本：" << counter << endl;
	return 0;
}*/