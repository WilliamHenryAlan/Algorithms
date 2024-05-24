#!/bin/bash

# 获取当前日期
current_date=$(date +"%Y.%m.%d")

# 添加所有更改
git add .
if [ $? -ne 0 ]; then
    echo "Failed to add changes!"
    exit 1
fi

# 提交更改，提交信息为当前日期
git commit -m "$current_date"
if [ $? -ne 0 ]; then
    echo "Commit failed!"
    exit 1
else
    echo " Commit successful!"
fi

# # 推送到远程仓库
# git push origin <your-branch-name>
# if [ $? -ne 0 ]; then
#     echo "Push failed"
#     exit 1
# else
#     echo "Push successful"
# fi
