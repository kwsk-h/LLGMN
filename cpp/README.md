# LLGMN C++

## ***Log-Linearized Gaussian Mixture Network***

ISO C++ 17 以降  
batch学習，online学習，TA-batch学習の動作確認済み．(TA：ターミナルアトラクト)
`TA-batchに不具合あり．batch推奨(2022/10)`

`parameter.h`にてネットワークパラメータおよび学習識別に使用するファイルの指定する．

### Default DATA

  筋電データ（4ch）が4動作（背屈，掌屈，尺屈，撓屈）分で1データとなっており，4データ分のファイルがある．  
  教師ラベルは4動作に対応した4クラスのOne-hotベクトル列となっている．  
  `input1.txt`，`label1.txt`が学習用，残りがテスト用に指定されている．

- input1.txt
  -- label1.txt
- input2.txt
  -- label2.txt
- input3.txt
  -- label3.txt
- input4.txt
  -- label4.txt

人工データ 2ch-4class（lea:学習用，dis:テスト用，二つとも同じデータ）`comment out`  
教師ラベルは4クラスのOne-hotベクトル列となっている．

- lea_sig.csv
- lea_T_sig.csv
- dis_sig.csv
- dis_T_sig.csv
