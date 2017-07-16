#!/bin/sh

for (( i = 1; i < 4; i++ )); do
    python3 answer.py < test$i > output;
    d=`diff output out$i`;
    if [[ $d != "" ]]; then
        echo "Test $i failed";
        echo "===============";
        echo "$d"
    else
        echo "Test $i passed!"
    fi
done
rm output;
