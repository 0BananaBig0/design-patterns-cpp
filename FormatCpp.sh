#########################################################################
# File Name: UpdateMenu.sh
# Author: Huaxiao Liang
# mail: 1184903633@qq.com
# Created Time: Fri 15 Nov 2024 01:23:11 PM CST
#########################################################################
#!/bin/bash
# Loop over all markdown files in the docs directory
for file in */*.cpp; do
   clang-format -i $file
done
