#!/bin/bash

 # 推送到远程仓库
git push origin master
git push repository master
if [ $? -ne 0 ]; then
    echo "Push failed"
    exit 1
else
    echo "Push successful"
fi
