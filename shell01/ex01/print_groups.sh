#!/bin/sh

# スペースをカンマに変換して出力
id -Gn "$FT_USER" | tr ' ' ',' | sed -z 's/\n$//'
