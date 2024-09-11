@echo off

touch headers/"%1".h
touch src/"%1".cpp

echo Done.
code headers/"%1".h src/"%1".cpp