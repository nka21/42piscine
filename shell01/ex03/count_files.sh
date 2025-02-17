#!/bin/sh

# 通常のファイルの数を取得
# 変数の前に空白をつけると、それがコマンドと認識されるためNG
file_count=$(find . -type f | wc -l)
# ディレクトリの数を取得
dir_count=$(find . -type d | wc -l) 

# 合計を出力
echo $((file_count + dir_count))