#include"myHead.h"
#include<io.h>
/*
	准备正样本集
*/

extern void getFiles(string path, vector<string>& files);

/*int main()
{
	vector<string> files;
	string path = "E://pics//casia";
	string savePath = "D://Program//C++//proj//phash_svm//testPos";
	getFiles(path, files);
	for (int i = 0; i < files.size(); i++)
	{
		Mat img = imread(files[i].c_str());
		imshow("test", img);
		waitKey(10);
		int pos = files[i].find_last_of('\\');
		imwrite(savePath + "//" + files[i].substr(pos + 1),img);
	}
}*/


/*void draw_box(Mat& img, Rect rect);
void my_mouse_callback(int event, int x, int y, int flags, void* param);
Mat src;
Rect box;
string winName = "src";

int main()
{
	box = Rect(-1, -1, 0, 0);
	// 截取脸部图像保存
	vector<string> files;
	string path = "E://pics//all";
	getFiles(path, files);
	namedWindow(winName, CV_WINDOW_AUTOSIZE);
	setMouseCallback(winName, my_mouse_callback);
	for (int i = 0; i < files.size(); i++) 
	{
		src = imread(files[i].c_str());
		resize(src, src, Size(854, 1286));
		imshow(winName, src);
		waitKey(0);
		// 保存rect
		if (box.width != 0 && box.x != -1) {
			Mat roi = src(box);
			string savePath = "D://Program//C++//proj//phash_svm//pos2//face";
			savePath = savePath.append(to_string(i));
			savePath = savePath.append(".jpg");
			imwrite(savePath, roi);
		}
	}
}

void draw_box(Mat& img, Rect rect)
{
	rectangle(img, Point(rect.x, rect.y), Point(rect.x + rect.width, rect.y + rect.height),Scalar(0,0,255));
	imshow(winName, img);
}

void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN:
		//cout << x <<" "<< y << endl;
		box = Rect(x, y, 0, 0);
		break;
	case CV_EVENT_LBUTTONUP:
		//cout << x << " " << y << endl;
		box.width = x - box.x;
		box.height = y - box.y;
		if (box.width < 0) {
			box.x += box.width;
			box.width *= -1;
		}
		if (box.height < 0) {
			box.y += box.height;
			box.height *= -1;
		}
		draw_box(src, box);
		break;
	default:
		break;
	}
}*/
