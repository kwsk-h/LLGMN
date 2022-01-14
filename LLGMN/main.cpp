#include "LLGMN.h"
#include "file.h"
#include <conio.h>
#include <filesystem>

int main(void)
{
	int flag = 1;		//0:online or 1:batch ?
	bool ta = 1;		//0:LLGMN or 1:TA_LLGMN ?
	//LL
	int D = dataSize;							//���͎���
	int K = classNum;							//�N���X
	int M = componentNum;				//�R���|�[�l���g��
	double epsilon = Epsilon;				//�w�K����
	//TA
	double beta = Beta;						//�w�K�p�����[�^��
	double time = convergenceTime;		//�w�K����
	double smp= samplingTime;			//�T���v�����O���ԇ�t[s]

	cout << "0:LLGMN or 1:TA_LLGMN ? : ";
	cin >> ta;
	
	/* ------data�ǂݍ���------ */
	vector<vector<double>> input_datas;
	vector<vector<double>> input_labels;

	//file�ǂݍ���
	fileset(datadir + teachdata, input_datas);
	fileset(datadir + teachlabel, input_labels);
	cout << "���t�f�[�^�ǂݍ���OK" << endl;
	//for(auto X : input_datas) for (auto x : X) cout << x << endl;

	D = input_datas[0].size();//���͎���
	K = input_labels[0].size();//�N���X
	LLGMN LL(D, K, M, epsilon, beta, time, smp);

	/* ------�w�K------ */
	while (true)
	{
		cout << "0:online or 1:batch ? : ";
		cin >> flag;
		cout << "--------------------------------------" << endl;
		if (!ta) cout << "LLGMN" << endl;
		else cout << "TA_LLGMN" << endl;
		cout << "--------------------------------------" << endl;
		//�w�K
		if (!flag)
		{
			cout << "�����w�K�@���t�f�[�^" << endl;
			if (!ta) LL.learn_online(input_datas, input_labels);
			else LL.talearn_online(input_datas, input_labels);
			break;
		}
		else if (flag)
		{
			cout << "�ꊇ�w�K�@���t�f�[�^" << endl;
			if (!ta) LL.learn_batch(input_datas, input_labels);
			else LL.talearn_batch(input_datas, input_labels);
			break;
		}
		else
		{
			cerr << "0 or 1" << endl;
		}
	}	
	/* ------�w�K�����܂�------ */

	/* ------�e�X�g------ */
	for (int n = 0; n < testdataset.size(); n++)
	{
		int num = 0;
		vector<vector<double>> test_datas;
		vector<vector<double>> test_labels;
		cout << testdataset[n] << endl;
		fileset(datadir + testdataset[n], test_datas);
		fileset(datadir + testlabelset[n], test_labels);
		cout << "�e�X�g�f�[�^�ǂݍ���OK" << endl;
		sscanf_s(testdataset[n].c_str(), "input%d.txt", &num);
		//�e�X�g
		vector<vector<double>> output_datas;
		output_datas = LL.test(test_datas, test_labels);
		cout << "-----Finish----" << endl;

		//�o�͕ۑ�
		string save = savedir;
		filesystem::create_directories(savedir) ?
			cout << "created directory - " << savedir << endl :
			cout << "create_directory() failed" << endl << endl;
		//����m���ۑ�
		filewrite(save + output + to_string(num) + ".csv", output_datas);
		//�����s��o��
		LL.CM.resultSave(save + evaluate + to_string(num) + ".csv");
	}
	return 0;
}