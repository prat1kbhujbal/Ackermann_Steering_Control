#!bin/bash
cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" -e "^./app/pbPlots/" -e "^./include/pbPlots/") > results/cppcheck_result.txt
echo "Results are stored in results/cppcheck_result.txt"