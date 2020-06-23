# 課題4 レポート

aa83988848 薗田光太郎

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
5～9：構造体の宣言
11：探したIDがサンプルの中にあったかを判定する変数flagの宣言
30～46：IDのサンプルデータのファイルの入力
50～67：身長と性別のサンプルデータのファイルの入力
72～90：探すIDとサンプルデータを比較し、あったら結果を表示
92～94：サンプルデータに探したデータがなかった場合、no dataを出力
## 入出力結果

例えば，ID 45313003のデータを調べたいとき，

```
input the filename of sample_ID:../sample/IDs.csv
the filename of sample: ../sample/IDs.csv
input the filename of sample_heights:../sample/heights.csv
the filename of sample: ../sample/heights.csv
Which ID's data do you want? :45313003
-----
ID:45313003
gender:male
height:174.38
```

例えば，ID 453123のデータを調べたいとき，

```
input the filename of sample_ID:../sample/IDs.csv
the filename of sample: ../sample/IDs.csv
input the filename of sample_heights:../sample/heights.csv
the filename of sample: ../sample/heights.csv
Which ID's data do you want? :453123
-----
no data
```

## 修正履歴
[comment #20200623]
- 選択したIDが女性だった場合の性別の出力がエラーとなります。原因は79行目の条件分岐です。heights.csvでは男性は1,女性は2と番号が割り当てられています。修正をお願いします。

- 83行目の改行ができていませんので修正をお願いします。
