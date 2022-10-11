#pragma once
#include <string>
#include <vector>
using namespace std;

/*----------ネットワークパラメータ----------*/
//LL
const int    dataSize = 4;							//入力次元（main.cppで入力に合わせて決定される）
const int    classNum = 4;						//クラス　（main.cppで入力に合わせて決定される）
const int    componentNum = 2;				//コンポーネント数
const double Epsilon = 0.1;					//学習率
//TA
const double Beta =0.7;							//学習パラメータβ
const double convergenceTime =1.0;		//学習時間
const double samplingTime = 0.001;		//サンプリング時間⊿t[s]

/*-------------------入力データ-------------------*/
const string datadir = "data/";					//データディレクトリ

const string teachdata = "input1.txt";		//教師データ
const string teachlabel = "label1.txt";		//教師データのラベル
const vector<string> testdataset = { "input2.txt"
													 ,"input3.txt"
													 ,"input4.txt" };	//テストデータ
const vector<string> testlabelset = { "label2.txt"
													 ,"label3.txt"
												 	 ,"label4.txt" };	//テストデータのラベル

//const string teachdata = "lea_sig.csv";			//教師データ
//const string teachlabel = "lea_T_sig.csv";	//教師データのラベル
//const vector<string> testdataset = { "dis_sig.csv" };		//テストデータ
//const vector<string> testlabelset = { "dis_T_sig.csv" };	//テストデータのラベル

/*-------------------出力データ-------------------*/
const string savedir = "out";					//出力ディレクトリ名
const string output = "/output";				//事後確率保存名
const string evaluate = "/evaluate";			//混合行列保存名