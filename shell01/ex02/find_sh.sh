#!/bin/sh

# -type f findコマンドのオプションで、通常のファイルを検索
# {} は、findが見つけたファイルのパス
# basename {} .sh で、ファイル名だけを取得し、.shを削除
find . -type f -name "*.sh" -exec basename {} .sh \;
