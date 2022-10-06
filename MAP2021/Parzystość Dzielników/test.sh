#!/bin/bash

for i in {1..100}
do
    echo "for $i: "
    echo "$i" | ./pd.e
done
exit 0

