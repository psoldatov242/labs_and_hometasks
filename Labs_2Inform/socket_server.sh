#!/bin/bash
echo "Запуск сервера на порту 12345..."
while true; do
    echo -e "Сервер получил: $(nc -l -p 12345)"
done
