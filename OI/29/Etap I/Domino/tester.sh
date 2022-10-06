#!/bin/bash

i=0
while [ $i -le 999 ]
do
    output=$(./dom.e < "./testy-dom/in/dom$i.in")
    correct=$(cat < "./testy-dom/out/dom$i.out")
    echo "$i: $output cor: $correct"
    ((i++))
done
