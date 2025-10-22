#!/bin/bash
echo "Текущие процессы:"
ps -aux
echo "Колмчество процессов: $(ps -aux | wc -l)"
