/*#include"myHead.h"

void detectAndSave(Mat frame,int num);
extern void getFiles(string path, vector<string>& files);

// Global variables
String face_cascade_name = "haarcascade_frontalface_default.xml";
CascadeClassifier face_cascade;
string window_name = "Capture - Face detection";
RNG rng(12345);

// @function main 
int main(int argc, const char** argv)
{
	CvCapture* capture;
	Mat frame;

	//-- 1. Load the cascades
	if (!face_cascade.load(face_cascade_name)) { printf("--(!)Error loading\n"); return -1; };

	//-- 2. Read the pic
	string path = "D:\\Program\\C++\\proj\\phash_svm\\pos2";
	vector<string> files;
	getFiles(path, files);
	for (int i = 0; i < files.size(); i++) {
		Mat img = imread(files[i].c_str());
		if (!img.data) {
			cout << "img load failed!" << endl;
			return -1;
		}
		imshow("Origin", img);
		detectAndSave(img,i);
	}

	return 0;
}

// @function detectAndSave 
void detectAndSave(Mat frame,int num)
{
	std::vector<Rect> faces;
	Mat frame_gray;
	string savePath = "D:\\Program\\C++\\proj\\phash_svm\\pos3\\face";
	savePath = savePath.append(to_string(num));
	savePath = savePath.append("_");

	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	//-- Detect faces
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

	for (size_t i = 0; i < faces.size(); i++)
	{
		string save = savePath;
		save = save.append(to_string(i));
		save = save.append(".jpg");
		Mat faceROI = frame_gray(faces[i]);
		Mat roi;
		// 四周再挖去25pixel保存
		if (faces[i].width > 50 && faces[i].height > 50) {
			roi = faceROI(Rect(25, 25, faces[i].width - 50, faces[i].height - 50));
		}
		else {
			roi = faceROI.clone();
		}
		imshow("roi", roi);
		waitKey(20);
		imwrite(save, roi);
	}
}*/