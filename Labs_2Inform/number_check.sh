#!/bin/bash
if [ $# -eq 0 ]; then
    echo "Ошибка: Не передано число"
    exit 1
fi

if [ $(($1 % 2)) -eq 0 ]; then
    echo "Число четное"
else
    echo "Число нечетное"
fi
