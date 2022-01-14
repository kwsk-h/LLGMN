#include "LLGMN.h"
#include "file.h"
#include <conio.h>
#include <filesystem>

int main(void)
{
	int flag = 1;		//0:online or 1:batch ?
	bool ta = 1;		//0:LLGMN or 1:TA_LLGMN ?
	//LL
	int D = dataSize;							//入力次元
	int K = classNum;							//クラス
	int M = componentNum;				//コンポーネント数
	double epsilon = Epsilon;				//学習率ε
	//TA
	double beta = Beta;						//学習パラメータβ
	double time = convergenceTime;		//学習時間
	double smp= samplingTime;			//サンプリング時間⊿t[s]

	cout << "0:LLGMN or 1:TA_LLGMN ? : ";
	cin >> ta;
	
	/* ------data読み込み------ */
	vector<vector<double>> input_datas;
	vector<vector<double>> input_labels;

	//file読み込み
	fileset(datadir + teachdata, input_datas);
	fileset(datadir + teachlabel, input_labels);
	cout << "教師データ読み込みOK" << endl;
	//for(auto X : input_datas) for (auto x : X) cout << x << endl;

	D = input_datas[0].size();//入力次元
	K = input_labels[0].size();//クラス
	LLGMN LL(D, K, M, epsilon, beta, time, smp);

	/* ------学習------ */
	while (true)
	{
		cout << "0:online or 1:batch ? : ";
		cin >> flag;
		cout << "--------------------------------------" << endl;
		if (!ta) cout << "LLGMN" << endl;
		else cout << "TA_LLGMN" << endl;
		cout << "--------------------------------------" << endl;
		//学習
		if (!flag)
		{
			cout << "逐次学習　教師データ" << endl;
			if (!ta) LL.learn_online(input_datas, input_labels);
			else LL.talearn_online(input_datas, input_labels);
			break;
		}
		else if (flag)
		{
			cout << "一括学習　教師データ" << endl;
			if (!ta) LL.learn_batch(input_datas, input_labels);
			else LL.talearn_batch(input_datas, input_labels);
			break;
		}
		else
		{
			cerr << "0 or 1" << endl;
		}
	}	
	/* ------学習ここまで------ */

	/* ------テスト------ */
	for (int n = 0; n < testdataset.size(); n++)
	{
		int num = 0;
		vector<vector<double>> test_datas;
		vector<vector<double>> test_labels;
		cout << testdataset[n] << endl;
		fileset(datadir + testdataset[n], test_datas);
		fileset(datadir + testlabelset[n], test_labels);
		cout << "テストデータ読み込みOK" << endl;
		sscanf_s(testdataset[n].c_str(), "input%d.txt", &num);
		//テスト
		vector<vector<double>> output_datas;
		output_datas = LL.test(test_datas, test_labels);
		cout << "-----Finish----" << endl;

		//出力保存
		string save = savedir;
		filesystem::create_directories(savedir) ?
			cout << "created directory - " << savedir << endl :
			cout << "create_directory() failed" << endl << endl;
		//事後確率保存
		filewrite(save + output + to_string(num) + ".csv", output_datas);
		//混合行列出力
		LL.CM.resultSave(save + evaluate + to_string(num) + ".csv");
	}
	return 0;
}