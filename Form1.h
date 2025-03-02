#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

#include "Header1.h"
#include "Header2.h"
#include <opencv2/opencv.hpp>
#include "opencv2/videoio.hpp"
#include <iostream>
//#include <ffmpeg/swscale.h>

using namespace cv;

namespace CppCLRWinFormsProject {
	using namespace System::Threading;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	VideoCapture capture;
	VideoWriter writer;
	bool isRecording = false;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			// uncomment to execute the rk1-utils:
			//    N_rk1_Utils_demo::execute(); // shows how the rk1-utils can be used

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBoxOutput;
	private: System::Windows::Forms::Button^ buttonRecord;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBoxOutput = (gcnew System::Windows::Forms::PictureBox());
			this->buttonRecord = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOutput))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBoxOutput
			// 
			this->pictureBoxOutput->Dock = System::Windows::Forms::DockStyle::Top;
			this->pictureBoxOutput->Location = System::Drawing::Point(0, 0);
			this->pictureBoxOutput->Name = L"pictureBoxOutput";
			this->pictureBoxOutput->Size = System::Drawing::Size(1116, 441);
			this->pictureBoxOutput->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBoxOutput->TabIndex = 4;
			this->pictureBoxOutput->TabStop = false;
			this->pictureBoxOutput->Click += gcnew System::EventHandler(this, &Form1::pictureBoxOutput_Click);
			// 
			// buttonRecord
			// 
			this->buttonRecord->Location = System::Drawing::Point(24, 489);
			this->buttonRecord->Name = L"buttonRecord";
			this->buttonRecord->Size = System::Drawing::Size(108, 41);
			this->buttonRecord->TabIndex = 5;
			this->buttonRecord->Text = L"R E C O R D";
			this->buttonRecord->UseVisualStyleBackColor = true;
			this->buttonRecord->Click += gcnew System::EventHandler(this, &Form1::buttonRecord_Click);
			// 
			// timer1
			// 
			//this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1116, 732);
			this->Controls->Add(this->buttonRecord);
			this->Controls->Add(this->pictureBoxOutput);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->Text = L"OpenCV";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOutput))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
#pragma region LocalVariables
	private: System::Threading::Thread^ StreamThreadHandle;
#pragma endregion

		   //#pragma region Delegates
#pragma region delegates
	private: delegate void UPDATE_FRAME(Bitmap^ b);

	private: void UpdateFrame(Bitmap^ b)
	{
		pictureBoxOutput->Image = b;
	}
#pragma endregion

#pragma region ThreadsFunctions
	private: void StreamThread()
	{
		int camera_device = 0;
		//VideoCapture capture;
		Mat frame;

		//Open the camera, make sure the plug in the camera or use built-in camera will de.
		capture.open(camera_device);

		if (!capture.isOpened())
		{
			MessageBox::Show("Error: No Camera is found.");
			return;
		}


		// Keep reading the frame 
		while (capture.read(frame))
		{
			if (frame.empty())
			{
				break;
			}

			Bitmap^ b;

			// Update to the pictirebox
			if (pictureBoxOutput->InvokeRequired)
			{
				// Since this a thread wich is not the same thread that created the pictureBoxOutput, we need to use delegate to update 
				UPDATE_FRAME^ cb = gcnew UPDATE_FRAME(this, &Form1::UpdateFrame);

				// In order to call delegate function, we need to invoke the delegate function
				//before that, convert opencv Mat to bitmap first
				Bitmap^ b = gcnew Bitmap(frame.cols, frame.rows, frame.step, Imaging::PixelFormat::Format24bppRgb, System::IntPtr(frame.data));

				//b->Save("D://MyVideos//output.avi");
				// Invoke the delegate update function
				Control::Invoke(cb, b);
			}
			else
			{
				// In case the pictureBoxOutput is created at the same thread, invoke is not required
				UpdateFrame(b);
			}
		}
	}

#pragma endregion
		   // You can call the functions at a button click. If you prefer, 
			// you can call them by clicking a menu item.
		  //}

	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e)
	{
		// During the form loading, we create a thread to run OpenCV
		StreamThreadHandle = gcnew Thread(gcnew ThreadStart(this, &Form1::StreamThread));
		StreamThreadHandle->Start();

		timer1->Interval = 30; // Set timer interval (adjust as needed)
		timer1->Start();
	}
	private: System::Void pictureBoxOutput_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}

	private: System::Void buttonRecord_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!isRecording) {
			startRecording("D:\My Videos\\output.avi");
			buttonRecord->Text = "Stop Recording";
		}
		else {
			//stopRecording();
			//buttonRecord->Text = "Start Recording";
		}
		MessageBox::Show("Recording!");
	}
	private: int startRecording(string filename)
	{
		cv::VideoCapture cap(0);

		if (!cap.isOpened())
		{
			std::cerr << "Error: Could not open camera." << std::endl;
		}

		int frame_width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
		int frame_height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
		double fps = 30.0;

		cv::VideoWriter video(filename, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, cv::Size(frame_width, frame_height));
		//cv::VideoWriter video(filename, cv::VideoWriter::fourcc('D', 'I', 'V', 'X'), fps, cv::Size(frame_width, frame_height));

		if (!video.isOpened()) {
			std::cerr << "Error: Could not open VideoWriter." << std::endl;
			return -1;
		}
		cv::Mat frame;
		while (true) {
			cap >> frame; // Capture frame-by-frame

			if (frame.empty()) {
				std::cerr << "Error: Captured frame is empty." << std::endl;
				return -1;
				//break;
			}
			//===================================================================
			if (frame_width == 0 || frame_height == 0) {
				frame_width = 640; // Default width
				frame_height = 480; // Default height
			}

			if (fps <= 0) {
				fps = 30.0; // Default FPS
			}
			//===================================================================


			video.write(frame); // Write the frame into the video file

			cv::imshow("Frame", frame); // Display the frame (optional)

			if (cv::waitKey(1) == 27) { // Press 'ESC' to exit
				break;
			}

		}

		const char* command = "ffmpeg -f dshow -i video=\"Integrated Camera\":audio=\"Microphone (Realtek Audio)\" output.mp4";
		std::system(command);

		cap.release();
		video.release();
		cv::destroyAllWindows();

		std::cout << "Video saved successfully." << std::endl;

		return 0;
	}

	private: int main() {
		return 0;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		//if (isRecording) {
		//	cv::Mat frame;
		//	capture >> frame;
		//	if (!frame.empty()) {
		//		// Convert cv::Mat to System::Drawing::Bitmap for PictureBox
		//		System::Drawing::Bitmap^ bmp = MatToBitmap(frame); // Implement MatToBitmap function (see below)
		//		pictureBoxOutput->Image = bmp;
		//	}
		//}
	}
		   System::Drawing::Bitmap^ Form1::MatToBitmap(cv::Mat frame) {
			   System::Drawing::Bitmap^ bmp = nullptr;
			   try {
				   cv::Mat temp; // Make a copy to avoid issues with data alignment.
				   cv::cvtColor(frame, temp, cv::COLOR_BGR2RGB); // Convert BGR to RGB (WinForms uses RGB).
				   bmp = gcnew System::Drawing::Bitmap(temp.cols, temp.rows, System::Drawing::Imaging::PixelFormat::Format24bppRgb);
				   System::Drawing::Rectangle rect(0, 0, bmp->Width, bmp->Height);
				   System::Drawing::Imaging::BitmapData^ bmpData = bmp->LockBits(rect, System::Drawing::Imaging::ImageLockMode::WriteOnly, bmp->PixelFormat);
				   System::IntPtr ptr = bmpData->Scan0;
				   int bytes = abs(bmpData->Stride) * bmp->Height;
				   memcpy(ptr.ToPointer(), temp.data, bytes);
				   bmp->UnlockBits(bmpData);
			   }
			   catch (System::Exception^ ex) {
				   System::Diagnostics::Debug::WriteLine(ex->Message);
			   }
			   return bmp;
		   }
	};
}// end of class Form1
// end of namespace CppCLRWinFormsProject


