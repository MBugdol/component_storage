cd ..
echo ---Creating Visual Studio 2022 project files---
./vendor/premake5 vs2022
echo ---Creating Makefiles---
./vendor/premake5 gmake2
read -n 1 -s -r -p "Press any key to continue..."
echo
cd proj_scripts