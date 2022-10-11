#pragma once
#include <string>
#include <vector>
using namespace std;

/*----------�l�b�g���[�N�p�����[�^----------*/
//LL
const int    dataSize = 4;							//���͎����imain.cpp�œ��͂ɍ��킹�Č��肳���j
const int    classNum = 4;						//�N���X�@�imain.cpp�œ��͂ɍ��킹�Č��肳���j
const int    componentNum = 2;				//�R���|�[�l���g��
const double Epsilon = 0.1;					//�w�K��
//TA
const double Beta =0.7;							//�w�K�p�����[�^��
const double convergenceTime =1.0;		//�w�K����
const double samplingTime = 0.001;		//�T���v�����O���ԇ�t[s]

/*-------------------���̓f�[�^-------------------*/
const string datadir = "data/";					//�f�[�^�f�B���N�g��

const string teachdata = "input1.txt";		//���t�f�[�^
const string teachlabel = "label1.txt";		//���t�f�[�^�̃��x��
const vector<string> testdataset = { "input2.txt"
													 ,"input3.txt"
													 ,"input4.txt" };	//�e�X�g�f�[�^
const vector<string> testlabelset = { "label2.txt"
													 ,"label3.txt"
												 	 ,"label4.txt" };	//�e�X�g�f�[�^�̃��x��

//const string teachdata = "lea_sig.csv";			//���t�f�[�^
//const string teachlabel = "lea_T_sig.csv";	//���t�f�[�^�̃��x��
//const vector<string> testdataset = { "dis_sig.csv" };		//�e�X�g�f�[�^
//const vector<string> testlabelset = { "dis_T_sig.csv" };	//�e�X�g�f�[�^�̃��x��

/*-------------------�o�̓f�[�^-------------------*/
const string savedir = "out";					//�o�̓f�B���N�g����
const string output = "/output";				//����m���ۑ���
const string evaluate = "/evaluate";			//�����s��ۑ���