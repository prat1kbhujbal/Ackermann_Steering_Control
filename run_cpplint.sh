#!bin/bash
cpplint $( find . -name *.cpp -or -name *.hpp | grep -vE -e "^./build/" -e "^./vendor/" -e "^./app/pbPlots/" -e "^./include/pbPlots/") > results/cpplint_result.txt
echo "Results are stored in results/cpplint_result.txt"